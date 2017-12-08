#ifndef SQLUTILS_H
#define SQLUTILS_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>

const QString strUserTable = "userItemTable";

class sqlUtils
{
public:
	sqlUtils();
	~sqlUtils();

private:
	QSqlDatabase m_dataBase;

public:
	void dataBaseInit();
	void dataBaseOpen();
	void dataBaseClose();
	void createUserItemTable();
	void createMsgTable();
	void insertUserItem(QString strUserName, QString strIP, QString strLocalHostName);
	void insertMsgItem(QString strFromIP, QString strToIP, QString strTime, QString strMsg);
	bool isUserItemExist(QString strIP);

	void deleteTable(QString strTable);
	void deleteUserItemByIP(QString strIP);
};

#endif // SQLUTILS_H
