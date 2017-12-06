#include "lanchat.h"
#include <QHostInfo>
#include <QNetworkInterface>
#include <QProcess>
#include <QDateTime>
#include <QMessageBox>
#include <QKeyEvent>
#include <QFileDialog>
#include <QColorDialog>
#include <QScrollBar>
#include "xmlUtils.h"

LANChat::LANChat(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	this->resize(850,550);

	initData();
}

LANChat::~LANChat()
{
	delete m_pSetAction;
	delete m_pQuitAction;
	delete m_pRestoreWinAction;
	delete m_pSettingWidget;
}

void LANChat::initData()
{
	m_pSettingWidget = NULL;

	CreateTrayIcon();

	m_strLocalHostName = QHostInfo::localHostName();
	m_strIP = getIP();
	m_strUserName = getUserName();

	//local user info
	QFile file("profile.xml");
	xmlUtils objXMLUtils;
	if(!file.exists())
	{
		objXMLUtils.create_xml_DOM("profile.xml");
	}
	//objXMLUtils.add_xmlnode_DOM("profile.xml", m_strLocalHostName, m_strUserName, m_strIP);
	//objXMLUtils.update_username_xml_DOM("profile.xml", "123456");
	QString strUserName = objXMLUtils.read_username_xml_DOM("profile.xml");
	qDebug() << "user name" << strUserName;
	if(strUserName.length() > 0)
		m_strUserName = strUserName;

	ui.labelName->setText(m_strLocalHostName);

	ui.textEdit->setFocusPolicy(Qt::StrongFocus);
	ui.textBrowser->setFocusPolicy(Qt::NoFocus);

	ui.textEdit->setFocus();
	ui.textEdit->installEventFilter(this);

	m_pUdpSocket = new QUdpSocket(this);
	m_port = 7755;
	m_pUdpSocket->bind(m_port, QUdpSocket::ShareAddress | QUdpSocket::ReuseAddressHint);
	connect(m_pUdpSocket, SIGNAL(readyRead()), this, SLOT(processPendingDatagrams()));
	sendMessage(NewParticipant);

	m_pServer = new TcpServer(this);
	connect(m_pServer,SIGNAL(sendFileName(QString)),this,SLOT(sentFileName(QString)));
	connect(ui.textEdit,SIGNAL(currentCharFormatChanged(QTextCharFormat)),this,SLOT(currentFormatChanged(const QTextCharFormat)));
	connect(ui.listWidgetUser, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(onListItemUserClicked( QListWidgetItem *)));

	//sqlite
	m_SqlUtils.dataBaseInit();
	m_SqlUtils.dataBaseOpen();
	m_SqlUtils.createUserItemTable();
}

void LANChat::sendMessage( MessageType type, QString serverAddress/*=""*/ )
{
	QByteArray data;
	QDataStream out(&data, QIODevice::WriteOnly);

	out << type << m_strUserName << m_strLocalHostName;
	switch(type)
	{
	case ParticipantLeft:
		out << m_strIP;
		m_pUdpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, m_port);
		break;
	case NewParticipant:
		out << m_strIP;
		m_pUdpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, m_port);
		break;
	case Message :
		if(ui.textEdit->toPlainText().length() > 0)
		{
			QString strMsg = getMessage();
			out << m_strIP << strMsg;
			ui.textBrowser->verticalScrollBar()->setValue(ui.textBrowser->verticalScrollBar()->maximum());

			qDebug() << "Destination IP address " << m_destHostAddress.toString();
			m_pUdpSocket->writeDatagram(data, data.length(), m_destHostAddress, m_port);

			QString time = QDateTime::currentDateTime().toString("hh:mm:ss");
			ui.textBrowser->setTextColor(Qt::black);
			ui.textBrowser->setCurrentFont(QFont("Times New Roman",12));
			ui.textBrowser->append("[ " + m_strUserName +" ] "+ time);
			ui.textBrowser->append(strMsg);
		}
		break;
	case FileName:
		{
#if 0
			int row = ui.tableWidget->currentRow();
			QString clientAddress = ui.tableWidget->item(row,2)->text();
			out << address << clientAddress << m_strFileName;
#endif
			break;
		}
	case Refuse:
		{
			out << serverAddress;
			break;
		}
	}

	//m_pUdpSocket->writeDatagram(data, data.length(), QHostAddress::Broadcast, m_port);
}

QString LANChat::getUserName()
{
	QStringList envVariables;
	envVariables << "USERNAME.*" << "USER.*" << "USERDOMAIN.*" << "HOSTNAME.*" << "DOMAINNAME.*";
	QStringList environment = QProcess::systemEnvironment();

	foreach(QString string, envVariables)
	{
		int index = environment.indexOf(QRegExp(string));
		if(index != -1)
		{
			QStringList stringList = environment.at(index).split("=");
			if(stringList.size() == 2)
			{
				return stringList.at(1);
				break;
			}
		}
	}

	return "unknown";
}

QString LANChat::getIP()
{
	QString localHostName = QHostInfo::localHostName();
	QHostInfo info = QHostInfo::fromName(localHostName);
	foreach(QHostAddress address, info.addresses())
// 	QList<QHostAddress> list = QNetworkInterface::allAddresses();
// 	foreach (QHostAddress address, list)
	{
		if(address.protocol() == QAbstractSocket::IPv4Protocol)
		{
			return address.toString();
		}
	}

	return "unknown";
}

void LANChat::processPendingDatagrams()
{
	while(m_pUdpSocket->hasPendingDatagrams())
	{
		QByteArray datagram;
		datagram.resize(m_pUdpSocket->pendingDatagramSize());
		m_pUdpSocket->readDatagram(datagram.data(),datagram.size());
		QDataStream in(&datagram,QIODevice::ReadOnly);
		int messageType;
		in >> messageType;
		QString userName,localHostName,ipAddress,message;
		QString time = QDateTime::currentDateTime().toString("hh:mm:ss");
		switch(messageType)
		{
		case Message:
			{
				in >>userName >>localHostName >>ipAddress >>message;
				ui.textBrowser->setTextColor(Qt::blue);
				ui.textBrowser->setCurrentFont(QFont("Times New Roman",12));
				ui.textBrowser->append("[ " +userName+" ] "+ time);
				ui.textBrowser->append(message);
				break;
			}
		case NewParticipant:
			{
				in >>userName >>localHostName >>ipAddress;
				newParticipant(userName,localHostName,ipAddress);

				break;
			}
		case ParticipantLeft:
			{
				in >> userName >>localHostName >> ipAddress;
				participantLeft(ipAddress, userName, localHostName, time);
				break;
			}
		case FileName:
			{
				in >>userName >>localHostName >> ipAddress;
				QString clientAddress,fileName;
				in >> clientAddress >> fileName;
				hasPendingFile(userName,ipAddress,clientAddress,fileName);
				break;
			}
		case Refuse:
			{
				in >> userName >> localHostName;
				QString serverAddress;
				in >> serverAddress;            
				QString ipAddress = getIP();

				if(ipAddress == serverAddress)
				{
					m_pServer->refused();
				}
				break;
			}
		}
	}
}

void LANChat::newParticipant( QString strUserName, QString strLocalHostName, QString strIPAddress )
{
	bool isExist = m_SqlUtils.isUserItemExist(strIPAddress);
	if(!isExist)
	{
		QListWidgetItem *pUserItem = new QListWidgetItem();
		pUserItem->setSizeHint(QSize(0, 60));
		//ui.listWidgetUser->insertItem(0, pUserItem);
		ui.listWidgetUser->addItem(pUserItem);

		userItemWidget *pUserItemWidget = new userItemWidget(this);
		pUserItemWidget->setUserHeadImage(":/LANChat/image/User.png");
		pUserItemWidget->setUserName(strUserName);
		pUserItemWidget->setUserIP(strIPAddress);
		ui.listWidgetUser->setItemWidget(pUserItem, pUserItemWidget);

		ui.onlineUser->setText(QStringLiteral("在线人数：%1").arg(ui.listWidgetUser->count()));
		sendMessage(NewParticipant);

		m_SqlUtils.insertUserItem(strUserName, strIPAddress, strLocalHostName);
	}
}

void LANChat::sentFileName( QString fileName)
{
	this->m_strFileName = fileName;
	sendMessage(FileName);
}

void LANChat::currentFormatChanged( const QTextCharFormat &format )
{
	ui.fontComboBox->setCurrentFont(format.font());

	if(format.fontPointSize()<9)  //如果字体大小出错，因为我们最小的字体为9
		ui.fontsizecomboBox->setCurrentIndex(3); //即显示12
	else ui.fontsizecomboBox->setCurrentIndex(
		ui.fontsizecomboBox->findText(QString::number(format.fontPointSize())));

	ui.textbold->setChecked(format.font().bold());
	ui.textitalic->setChecked(format.font().italic());
	ui.textUnderline->setChecked(format.font().underline());
	m_color = format.foreground().color();
}

bool LANChat::eventFilter( QObject *target, QEvent *event )
{
	if(target == ui.textEdit)
	{
		if(event->type() == QEvent::KeyPress)
		{
			QKeyEvent *k = static_cast<QKeyEvent *>(event);
			if((k->modifiers() == Qt::ControlModifier) && (k->key() == Qt::Key_Return))
			{
				//换行
				ui.textEdit->append("\n");
			}
			else if(k->key() == Qt::Key_Enter || k->key() == Qt::Key_Return)
			{
				onSend_clicked();
				return true;
			}
		}
	}
	return QWidget::eventFilter(target,event);
}

void LANChat::onSend_clicked()
{
	sendMessage(Message);
}

void LANChat::onSendfile_clicked()
{
#if 0
	if(ui.tableWidget->selectedItems().isEmpty())
	{
		QMessageBox::warning(0,QStringLiteral("选择用户"),QStringLiteral("请先从用户列表选择要传送的用户！"),QMessageBox::Ok);
		return;
	}
#endif
	m_pServer->show();
	m_pServer->initServer();
}

void LANChat::onFontsizecomboBox_currentIndexChanged( QString size)
{
	ui.textEdit->setFontPointSize(size.toDouble());
	ui.textEdit->setFocus();
}

void LANChat::onFontComboBox_currentFontChanged( QFont f )
{
	ui.textEdit->setCurrentFont(f);
	ui.textEdit->setFocus();
}

void LANChat::onTextbold_clicked( bool checked )
{
	if(checked)
		ui.textEdit->setFontWeight(QFont::Bold);
	else
		ui.textEdit->setFontWeight(QFont::Normal);
	ui.textEdit->setFocus();
}

void LANChat::onTextitalic_clicked( bool checked )
{
	ui.textEdit->setFontItalic(checked);
	ui.textEdit->setFocus();
}

void LANChat::onTextcolor_clicked()
{
	m_color = QColorDialog::getColor(m_color, this);
	if(m_color.isValid())
	{
		ui.textEdit->setTextColor(m_color);
		ui.textEdit->setFocus();
	}
}

void LANChat::onSave_clicked()
{
	if(ui.textBrowser->document()->isEmpty())
		QMessageBox::warning(0,QStringLiteral("警告"),QStringLiteral("聊天记录为空，无法保存！"),QMessageBox::Ok);
	else
	{
		//获得文件名
		QString fileName = QFileDialog::getSaveFileName(this,QStringLiteral("保存聊天记录"),QStringLiteral("聊天记录"),QStringLiteral("文本(*.txt);;All File(*.*)"));
		if(!fileName.isEmpty())
			saveFile(fileName);
	}
}

void LANChat::onClear_clicked()
{
	ui.textBrowser->clear();
}

void LANChat::onTextUnderline_clicked( bool checked )
{
	ui.textEdit->setFontUnderline(checked);
	ui.textEdit->setFocus();
}

bool LANChat::saveFile( const QString& fileName )
{
	QFile file(fileName);
	if(!file.open(QFile::WriteOnly | QFile::Text))

	{
		QMessageBox::warning(this,QStringLiteral("保存文件"),
			QStringLiteral("无法保存文件 %1:\n %2").arg(fileName)
			.arg(file.errorString()));
		return false;
	}
	QTextStream out(&file);
	out << ui.textBrowser->toPlainText();

	return true;
}

QString LANChat::getMessage()
{
	QString msg = ui.textEdit->toHtml();

	ui.textEdit->clear();
	ui.textEdit->setFocus();
	return msg;
}

void LANChat::changeEvent( QEvent *e )
{
	QWidget::changeEvent(e);
	switch (e->type()) {
	case QEvent::LanguageChange:
		ui.retranslateUi(this);
		break;
	default:
		break;
	}
}

void LANChat::participantLeft(QString strIP, QString userName,QString localHostName,QString time )
{
	if(m_strIP != strIP)
	{
		for(int i = 0; i < ui.listWidgetUser->count(); i++)
		{
			QListWidgetItem *pItem = ui.listWidgetUser->item(i);
			QWidget *pItemWidget = ui.listWidgetUser->itemWidget(pItem);
			userItemWidget *pTemp = (userItemWidget *)pItemWidget;
			QString strItempIP = pTemp->userIP();
			if(strItempIP == strIP)
			{
				ui.listWidgetUser->removeItemWidget(pItem);
				break;
			}
		}

		m_SqlUtils.deleteUserItemByIP(strIP);

		ui.textBrowser->setTextColor(Qt::gray);
		ui.textBrowser->setCurrentFont(QFont("Times New Roman",10));
		ui.textBrowser->append(QStringLiteral("%1 于 %2 离开！").arg(userName).arg(time));
		ui.onlineUser->setText(QStringLiteral("在线人数：%1").arg(ui.listWidgetUser->count()));
	}
}

void LANChat::closeEvent( QCloseEvent *event )
{
	sendMessage(ParticipantLeft);

	m_SqlUtils.deleteTable(strUserTable);
	m_SqlUtils.dataBaseClose();

	if(1 == m_quitType)
	{
		m_quitType = 0;
		event->accept();
	}
	else
	{
		if(this->isVisible())
		{
			hide();
			event->ignore();
		}
		else
		{
			event->accept();
		}
	}
}

void LANChat::hasPendingFile( QString userName,QString serverAddress, QString clientAddress,QString fileName )
{
	QString ipAddress = getIP();
	if(ipAddress == clientAddress)
	{
		int btn = QMessageBox::information(this,QStringLiteral("接受文件"),
			QStringLiteral("来自%1(%2)的文件：%3,是否接收？")
			.arg(userName).arg(serverAddress).arg(fileName),
			QMessageBox::Yes,QMessageBox::No);
		if(btn == QMessageBox::Yes)
		{
			QString name = QFileDialog::getSaveFileName(0,QStringLiteral("保存文件"),fileName);
			if(!name.isEmpty())
			{
				TcpClient *client = new TcpClient(this);
				client->setFileName(name);
				client->setHostAddress(QHostAddress(serverAddress));
				client->show();

			}

		}
		else{
			sendMessage(Refuse,serverAddress);
		}
	}
}

void LANChat::CreateTrayMenu()
{
//	m_pMiniSizeAction = new QAction(QStringLiteral("最小化(&N)"), this);
//	m_pMaxSizeAction = new QAction(QStringLiteral("最大化(&X)"), this);
	m_pRestoreWinAction = new QAction(QStringLiteral("打开面板(&R)"), this);
	m_pQuitAction = new QAction(QStringLiteral("退出(&Q)"), this);
	m_pSetAction = new QAction(QStringLiteral("设置"), this);

	m_pMenu = new QMenu((QWidget *)QApplication::desktop());
//	m_pMenu->addAction(m_pMiniSizeAction);
//	m_pMenu->addAction(m_pMaxSizeAction);
	m_pMenu->addAction(m_pSetAction);
	m_pMenu->addAction(m_pRestoreWinAction);
	m_pMenu->addSeparator();
	m_pMenu->addAction(m_pQuitAction);

//	connect(m_pMiniSizeAction, SIGNAL(triggered()), this, SLOT(hide()));
//	connect(m_pMaxSizeAction, SIGNAL(triggered()), this, SLOT(showMaximized()));
	connect(m_pRestoreWinAction, SIGNAL(triggered()), this, SLOT(showNormal()));
	connect(m_pQuitAction, SIGNAL(triggered()), this, SLOT(onIconQuit_clicked()));
	connect(m_pSetAction, SIGNAL(triggered()), this, SLOT(onIconSetting_clicked()));
}

void LANChat::CreateTrayIcon()
{
	CreateTrayMenu();

	if(!QSystemTrayIcon::isSystemTrayAvailable())
		return;

	m_pTrayIcon = new QSystemTrayIcon(this);
	m_pTrayIcon->setIcon(QIcon(":/LANChat/image/MSN-Messenger.png"));
	setWindowIcon(QIcon(":/LANChat/image/MSN-Messenger.png"));

	m_pTrayIcon->setToolTip("LANChat V1.0");
//	m_pTrayIcon->showMessage("LANChat", "LANChat Beta1.0", QSystemTrayIcon::Information, 10000);

	m_pTrayIcon->setContextMenu(m_pMenu);
	m_pTrayIcon->show();

	this->connect(m_pTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(iconActivated(QSystemTrayIcon::ActivationReason)));
}

void LANChat::iconActivated( QSystemTrayIcon::ActivationReason reason )
{
	switch (reason)
	{
	case QSystemTrayIcon::Unknown:
		break;
	case QSystemTrayIcon::Context:
		break;
	case QSystemTrayIcon::DoubleClick:
	case QSystemTrayIcon::Trigger:
		showNormal();
		break;
	case QSystemTrayIcon::MiddleClick:
		m_pTrayIcon->showMessage("LANChat", "LANChat Beta1.0", QSystemTrayIcon::Information, 10000);
		break;
	default:
		break;
	}
}

void LANChat::onListItemUserClicked( QListWidgetItem *pItem )
{
	QWidget *pItemWidget = ui.listWidgetUser->itemWidget(pItem);
	userItemWidget *pTemp = (userItemWidget *)pItemWidget;
	QString strTextLabel = pTemp->userName();
	ui.labelName->setText(strTextLabel);

	QString strIP = pTemp->userIP();
	m_destHostAddress.setAddress(strIP);
}

void LANChat::onIconQuit_clicked()
{
	m_quitType = 1;
	close();

	if(m_pSettingWidget != NULL)
		m_pSettingWidget->close();
}

void LANChat::onIconSetting_clicked()
{
	qDebug() << "setting show";
	if(!this->isVisible())
		showNormal();

	if(m_pSettingWidget == NULL)
		m_pSettingWidget = new settingWidget;
	
	m_pSettingWidget->show();
}
