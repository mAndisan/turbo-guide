#pragma once
#include <QFile>
#include <QTextStream>
#include <QXmlStreamWriter>
#include <QXmlStreamReader>
#include <QDomDocument>

class xmlUtils
{
public:
	xmlUtils(void);
	~xmlUtils(void);

	//QXmlStreamReader
	void createXML(QString strFileName, QString strLocalHostName, QString strUserName, QString strIP);

	void setItemLocalHostName(QString strLocalHostName);
	QString itemLocalHostName();

	void setItemUserName(QString strUserName);
	QString itemUserName();

	void setItemIP(QString strIP);
	QString itemIP();

	//DOM
	void create_xml_DOM(QString fileName);
	void do_xml_DOM(const QString opt, QString fileName);
	void add_xmlnode_DOM(QString fileName, QString localHostName, QString userName, QString ip);
	void update_username_xml_DOM(QString fileName, QString userName);
	QString read_username_xml_DOM(QString fileName);
};

