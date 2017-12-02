#include "tcpclient.h"
#include "ui_tcpclient.h"
#include <QFileDialog>
#include <QMessageBox>
TcpClient::TcpClient(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpClient)
{
    ui->setupUi(this);
    this->setFixedSize(350,180);

    TotalBytes = 0;
    bytesReceived = 0;
    fileNameSize = 0;

    tcpClient = new QTcpSocket(this);
    tcpPort = 6666;
    connect(tcpClient,SIGNAL(readyRead()),this,SLOT(readMessage()));
    connect(tcpClient,SIGNAL(error(QAbstractSocket::SocketError)),this,
            SLOT(displayError(QAbstractSocket::SocketError)));

}

TcpClient::~TcpClient()
{
    delete ui;
}

void TcpClient::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void TcpClient::setHostAddress(QHostAddress address)  //���÷�������ַ�����ӷ�����
{
    hostAddress = address;
    newConnect();
}
void TcpClient::newConnect()
{
    blockSize = 0;
    tcpClient->abort();
    tcpClient->connectToHost(hostAddress,tcpPort);
    time.start();
}

void TcpClient::readMessage()
{
    QDataStream in(tcpClient);
    in.setVersion(QDataStream::Qt_4_6);

    float useTime = time.elapsed();
    if(bytesReceived <= sizeof(qint64)*2){
        if((tcpClient->bytesAvailable() >= sizeof(qint64)*2) && (fileNameSize == 0)){
            in>>TotalBytes>>fileNameSize;
            bytesReceived += sizeof(qint64)*2;
        }
        if((tcpClient->bytesAvailable() >= fileNameSize) && (fileNameSize != 0)){
            in>>fileName;
            bytesReceived +=fileNameSize;

            if(!localFile->open(QFile::WriteOnly)){
                QMessageBox::warning(this,QStringLiteral("Ӧ�ó���"),QStringLiteral("�޷���ȡ�ļ� %1:\n%2.").arg(fileName).arg(localFile->errorString()));
                return;
            }
        }else{
            return;
        }
    }
    if(bytesReceived < TotalBytes){
        bytesReceived += tcpClient->bytesAvailable();
        inBlock = tcpClient->readAll();
        localFile->write(inBlock);
        inBlock.resize(0);
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesReceived);
    qDebug()<<bytesReceived<<"received"<<TotalBytes;

    double speed = bytesReceived / useTime;
    ui->tcpClientStatusLabel->setText(QStringLiteral("�ѽ��� %1MB (%2MB/s) \n��%3MB ����ʱ:%4��\n����ʣ��ʱ�䣺%5��")
                                   .arg(bytesReceived / (1024*1024))//�ѽ���
                                   .arg(speed*1000/(1024*1024),0,'f',2)//�ٶ�
                                   .arg(TotalBytes / (1024 * 1024))//�ܴ�С
                                   .arg(useTime/1000,0,'f',0)//��ʱ
                                   .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//ʣ��ʱ��

    if(bytesReceived == TotalBytes)
    {
        tcpClient->close();
        ui->tcpClientStatusLabel->setText(QStringLiteral("�����ļ� %1 ���").arg(fileName));
	localFile->close();   //�������ļ���һ��Ҫ�رգ���Ȼ���ܳ�����
    }
}


void TcpClient::displayError(QAbstractSocket::SocketError socketError) //������
{
    switch(socketError)
    {
        case QAbstractSocket::RemoteHostClosedError : break;
        default : qDebug() << tcpClient->errorString();
    }
}

void TcpClient::on_tcpClientCloseBtn_clicked()//�ر�
{
    tcpClient->abort();
    this->close();
}

void TcpClient::on_tcpClientCancleBtn_clicked()//ȡ��
{
   tcpClient->abort();
}
