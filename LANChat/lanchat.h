#ifndef LANCHAT_H
#define LANCHAT_H

#include <QtWidgets/QMainWindow>
#include <QUdpSocket>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QCloseEvent>
#include "ui_lanchat.h"
#include "tcpclient.h"
#include "tcpserver.h"
#include "useritemwidget.h"
#include "sqlutils.h"
#include "settingwidget.h"

enum MessageType{Message, NewParticipant, ParticipantLeft, FileName, Refuse};

class LANChat : public QMainWindow
{
	Q_OBJECT

public:
	LANChat(QWidget *parent = 0);
	~LANChat();

	void CreateTrayMenu();
	void CreateTrayIcon();

	QSystemTrayIcon *m_pTrayIcon;
	QMenu *m_pMenu;

	QAction *m_pMiniSizeAction;
	QAction *m_pMaxSizeAction;
	QAction *m_pRestoreWinAction;
	QAction *m_pQuitAction;
	QAction *m_pSetAction;

	QString m_strLocalHostName;
	QString m_strUserName;
	QString m_strIP;

	QString getMessage();

protected:
	void changeEvent(QEvent *e);
	void newParticipant(QString userName, QString localHostName, QString ipAddress);
	void participantLeft(QString strIP, QString userName,QString localHostName,QString time);
	void sendMessage(MessageType type, QString serverAddress="");
	QString getIP();
	QString getUserName();
	void closeEvent(QCloseEvent *event);
	void hasPendingFile(QString userName,QString serverAddress,
		QString clientAddress,QString fileName);

	bool eventFilter(QObject *target, QEvent *event);//事件过滤器

	void initData();

private:
	Ui::LANChatClass ui;

	QUdpSocket *m_pUdpSocket;
	qint16 m_port;
	QString m_strFileName;
	TcpServer *m_pServer;
	QColor m_color;

	sqlUtils m_SqlUtils;
	QHostAddress m_destHostAddress;
	int m_quitType;		// 1 - via trayIcon

	settingWidget *m_pSettingWidget;

	bool saveFile(const QString& fileName);//保存聊天记录
private slots:
	void processPendingDatagrams();
	void sentFileName(QString);
	void currentFormatChanged(const QTextCharFormat &format);

	void onTextUnderline_clicked(bool checked);
	void onClear_clicked();
	void onSave_clicked();
	void onTextcolor_clicked();
	void onTextitalic_clicked(bool checked);
	void onTextbold_clicked(bool checked);
	void onFontComboBox_currentFontChanged(QFont f);
	void onFontsizecomboBox_currentIndexChanged(QString );
	void onSendfile_clicked();
	void onSend_clicked();
	void onIconQuit_clicked();
	void onIconSetting_clicked();

	void onListItemUserClicked(QListWidgetItem *pItem);
public:
	void iconActivated(QSystemTrayIcon::ActivationReason reason);
};

#endif // LANCHAT_H
