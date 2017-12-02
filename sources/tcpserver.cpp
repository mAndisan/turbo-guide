#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QTcpSocket>
#include <QFileDialog>
#include <QMessageBox>

TcpServer::TcpServer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TcpServer)
{
    ui->setupUi(this);
    this->setFixedSize(350,180);

    tcpPort = 6666;
    tcpServer = new QTcpServer(this);  
    connect(tcpServer,SIGNAL(newConnection()),this,SLOT(sendMessage()));

    initServer();

}

TcpServer::~TcpServer()
{
    delete ui;
}

void TcpServer::changeEvent(QEvent *e)
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

void TcpServer::sendMessage()  //��ʼ��������
{
    ui->serverSendBtn->setEnabled(false);
    clientConnection = tcpServer->nextPendingConnection();
    connect(clientConnection,SIGNAL(bytesWritten(qint64)),SLOT(updateClientProgress(qint64)));

    ui->serverStatusLabel->setText(QStringLiteral("��ʼ�����ļ� %1 ��").arg(theFileName));

    localFile = new QFile(fileName);
    if(!localFile->open((QFile::ReadOnly))){//��ֻ����ʽ��
        QMessageBox::warning(this,QStringLiteral("Ӧ�ó���"),QStringLiteral("�޷���ȡ�ļ� %1:\n%2").arg(fileName).arg(localFile->errorString()));
        return;
    }
    TotalBytes = localFile->size();
    QDataStream sendOut(&outBlock,QIODevice::WriteOnly);
    sendOut.setVersion(QDataStream::Qt_4_6);
    time.start();  //��ʼ��ʱ
    QString currentFile = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
    sendOut<<qint64(0)<<qint64(0)<<currentFile;
    TotalBytes += outBlock.size();
    sendOut.device()->seek(0);
    sendOut<<TotalBytes<<qint64((outBlock.size()-sizeof(qint64)*2));
    bytesToWrite = TotalBytes - clientConnection->write(outBlock);
    qDebug()<<currentFile<<TotalBytes;
    outBlock.resize(0);

}

void TcpServer::updateClientProgress(qint64 numBytes)//���½�����
{
    bytesWritten += (int)numBytes;
    if(bytesToWrite > 0){
        outBlock = localFile->read(qMin(bytesToWrite,loadSize));
        bytesToWrite -= (int)clientConnection->write(outBlock);
        outBlock.resize(0);
    }
    else{
        localFile->close();
    }
    ui->progressBar->setMaximum(TotalBytes);
    ui->progressBar->setValue(bytesWritten);

   float useTime = time.elapsed();
   double speed = bytesWritten / useTime;
   ui->serverStatusLabel->setText(QStringLiteral("�ѷ��� %1MB (%2MB/s) \n��%3MB ����ʱ:%4��\n����ʣ��ʱ�䣺%5��")
                                  .arg(bytesWritten / (1024*1024))//�ѷ���
                                  .arg(speed*1000/(1024*1024),0,'f',2)//�ٶ�
                                  .arg(TotalBytes / (1024 * 1024))//�ܴ�С
                                  .arg(useTime/1000,0,'f',0)//��ʱ
                                  .arg(TotalBytes/speed/1000 - useTime/1000,0,'f',0));//ʣ��ʱ��

   //num.sprintf("%.1f KB/s", (bytesWritten*1000) / (1024.0*time.elapsed()));
    if(bytesWritten == TotalBytes)
        ui->serverStatusLabel->setText(QStringLiteral("�����ļ� %1 �ɹ�").arg(theFileName));

}

void TcpServer::on_serverOpenBtn_clicked()  //��
{
    fileName = QFileDialog::getOpenFileName(this);
    if(!fileName.isEmpty())
    {
        theFileName = fileName.right(fileName.size() - fileName.lastIndexOf('/')-1);
        ui->serverStatusLabel->setText(QStringLiteral("Ҫ���͵��ļ�Ϊ��%1 ").arg(theFileName));
        ui->serverSendBtn->setEnabled(true);
        ui->serverOpenBtn->setEnabled(false);
    }
}

void TcpServer::refused()   //���Է��ܾ�
{
    tcpServer->close();
    ui->serverStatusLabel->setText(QStringLiteral("�Է��ܾ����գ�����"));
}

void TcpServer::on_serverSendBtn_clicked()  //����
{
    if(!tcpServer->listen(QHostAddress::Any,tcpPort))//��ʼ����
    {
        qDebug() << tcpServer->errorString();
        close();
        return;
    }

    ui->serverStatusLabel->setText(QStringLiteral("�ȴ��Է�����... ..."));
    emit sendFileName(theFileName);
}

void TcpServer::on_serverCloseBtn_clicked()//�˳�
{   
    if(tcpServer->isListening())
    {
        tcpServer->close();
        clientConnection->abort();
    }
    this->close();
}

void TcpServer::initServer()//��ʼ��
{
    loadSize = 4*1024;
    TotalBytes = 0;
    bytesWritten = 0;
    bytesToWrite = 0;

    ui->serverStatusLabel->setText(QStringLiteral("��ѡ��Ҫ���͵��ļ�"));
    ui->progressBar->reset();
    ui->serverOpenBtn->setEnabled(true);
    ui->serverSendBtn->setEnabled(false);

    tcpServer->close();

}
