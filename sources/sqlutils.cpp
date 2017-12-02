#include "sqlutils.h"

sqlUtils::sqlUtils()
{

}

sqlUtils::~sqlUtils()
{

}

void sqlUtils::dataBaseInit()
{
	m_dataBase = QSqlDatabase::addDatabase("QSQLITE");
	m_dataBase.setDatabaseName("chatConfig.db");
//	m_dataBase.setUserName("xuxuan");
//	m_dataBase.setPassword("AI4teru");
}

void sqlUtils::dataBaseOpen()
{
	if(!m_dataBase.open())
	{
		qDebug() << "Fail to open database." << m_dataBase.lastError();
	}
}

void sqlUtils::dataBaseClose()
{
	m_dataBase.close();
}

void sqlUtils::createUserItemTable()
{
	QSqlQuery sqlQuery;
	QString create_sql = "create table userItemTable (id INTEGER PRIMARY KEY AUTOINCREMENT, \
											userName varchar(30), \
											ipAddress varchar(20), \
											localHostName varchar(64))";
	sqlQuery.prepare(create_sql);
	if(!sqlQuery.exec())
	{
		qDebug() << "Fail to create userItem table." << sqlQuery.lastError();
	}
}

void sqlUtils::insertUserItem( QString strUserName, QString strIP, QString strLocalHostName )
{
	QSqlQuery sqlQuery;
	QString insert_sql = "insert into userItemTable(userName, ipAddress, localHostName) values (?, ?, ?)";
	sqlQuery.prepare(insert_sql);
	sqlQuery.addBindValue(strUserName);
	sqlQuery.addBindValue(strIP);
	sqlQuery.addBindValue(strLocalHostName);
	if(!sqlQuery.exec())
	{
		qDebug() << "Fail to insert userItem." << sqlQuery.lastError();
	}
}

bool sqlUtils::isUserItemExist( QString strIP )
{
	bool isExist = false;
	QSqlQuery sqlQuery;
	QString select_sql = "select count(*) from userItemTable where ipAddress = ";
	select_sql += "'";
	select_sql += strIP;
	select_sql += "'";

	qDebug() << "Select sql :" << select_sql;
	sqlQuery.prepare(select_sql);
	if(!sqlQuery.exec())
	{
		qDebug() << "Fail to create userItem table." << sqlQuery.lastError();
	}
	else
	{
		int counts = 0;
		sqlQuery.next();
		
		counts = sqlQuery.value(0).toInt();

		qDebug() << "counts :" << counts;
		if(counts > 0)
			isExist = true;
	}
//	bool isExist = sqlQuery.exec(QString("select count(*) from userItem where ipAddress = '%1'").arg(strIP));
	return isExist;
}

void sqlUtils::deleteTable( QString strTable )
{
	QSqlQuery sqlQuery;
	QString delete_sql = "delete from ";
	delete_sql += strTable;

	sqlQuery.prepare(delete_sql);
	if(!sqlQuery.exec())
	{
		qDebug() << "delete table Failed." << sqlQuery.lastError();
	}

	QString update_sql = "update sqlite_sequence set seq = 0 where name = ";
	update_sql += strTable;
	sqlQuery.prepare(update_sql);
	if(!sqlQuery.exec())
	{
		qDebug() << "update sqlite_sequence Failed." << sqlQuery.lastError();
	}
}

void sqlUtils::deleteUserItemByIP( QString strIP )
{
	QSqlQuery sqlQuery;
	QString delete_sql = QString("delete from userItemTable where ipAddress = '%1'").arg(strIP);
	sqlQuery.prepare(delete_sql);
	if(!sqlQuery.exec())
	{
		qDebug() << "delete user item Failed." << sqlQuery.lastError();
	}
}
