#include "xmlUtils.h"


xmlUtils::xmlUtils(void)
{
}


xmlUtils::~xmlUtils(void)
{
}

void xmlUtils::createXML( QString strFileName, QString strLocalHostName, QString strUserName, QString strIP )
{
	QFile xmlFile(strFileName);
	if(!xmlFile.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QXmlStreamWriter xmlWriter(&xmlFile);
	xmlWriter.setAutoFormatting(true);
	xmlWriter.writeStartDocument();
	xmlWriter.writeStartElement("Self");
	xmlWriter.writeTextElement("localhostname", strLocalHostName);
	xmlWriter.writeTextElement("username", strUserName);
	xmlWriter.writeTextElement("ip", strIP);

	xmlWriter.writeEndElement();
	xmlWriter.writeEndDocument();
	xmlFile.close();
}

void xmlUtils::setItemLocalHostName( QString strLocalHostName )
{

}

QString xmlUtils::itemLocalHostName()
{
	QString strLocalHostName;
	QString strFileName = "self.xml";
	QFile xmlFile(strFileName);
	if(!xmlFile.open(QFile::ReadOnly | QFile::Text))
		return "";

	QXmlStreamReader xmlReader(&xmlFile);
	xmlReader.readNext();
	while (!xmlReader.atEnd())
	{
		if(xmlReader.isStartElement())
		{
			if(xmlReader.name() == "Self")
				xmlReader.readNext();
			else if(xmlReader.name() == "localhostname")
			{
				strLocalHostName = xmlReader.readElementText();
				break;
			}
		}
		else
			xmlReader.readNext();
	}

	xmlFile.close();
	return strLocalHostName;
}

void xmlUtils::setItemUserName( QString strUserName )
{

}

QString xmlUtils::itemUserName()
{
	QString strUserName;
	QString strFileName = "self.xml";
	QFile xmlFile(strFileName);
	if(!xmlFile.open(QFile::ReadOnly | QFile::Text))
		return "";

	QXmlStreamReader xmlReader(&xmlFile);
	xmlReader.readNext();
	while (!xmlReader.atEnd())
	{
		if(xmlReader.isStartElement())
		{
			if(xmlReader.name() == "Self")
				xmlReader.readNext();
			else if(xmlReader.name() == "username")
			{
				strUserName = xmlReader.readElementText();
				break;
			}
		}
		else
			xmlReader.readNext();
	}

	xmlFile.close();
	return strUserName;
}

void xmlUtils::setItemIP( QString strIP )
{

}

QString xmlUtils::itemIP()
{
	QString strIP;
	QString strFileName = "self.xml";
	QFile xmlFile(strFileName);
	if(!xmlFile.open(QFile::ReadOnly | QFile::Text))
		return "";

	QXmlStreamReader xmlReader(&xmlFile);
	xmlReader.readNext();
	while (!xmlReader.atEnd())
	{
		if(xmlReader.isStartElement())
		{
			if(xmlReader.name() == "Self")
				xmlReader.readNext();
			else if(xmlReader.name() == "ip")
			{
				strIP = xmlReader.readElementText();
				break;
			}
		}
		else
			xmlReader.readNext();
	}

	xmlFile.close();
	return strIP;
}

void xmlUtils::create_xml_DOM( QString fileName )
{
	QFile file(fileName);
	file.open(QIODevice::ReadWrite);
	QDomDocument doc;
	QDomProcessingInstruction instruction;
	instruction = doc.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
	doc.appendChild(instruction);
	QDomElement root = doc.createElement("profile");
	doc.appendChild(root);

	QDomText text = doc.createTextNode("");
	root.appendChild(text);
	QTextStream out(&file);
	doc.save(out, 4);
	file.close();
}

void xmlUtils::add_xmlnode_DOM( QString fileName, QString localHostName, QString userName, QString ip )
{
	QFile file(fileName);
	if(!file.open(QIODevice::ReadOnly | QFile::Text))
		return;
	QDomDocument doc;
	QString errorStr;
	int errorLine;
	int errorColumn;

	if(!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
	{
		file.close();
	}
	file.close();

	QDomElement root = doc.documentElement();
	if(root.isNull())
	{
		root = doc.createElement("profile");
	}
	QDomElement element_localhostname = doc.createElement("localhostname");
	QDomElement element_username = doc.createElement("username");
	QDomElement element_ip = doc.createElement("ip");
	QDomText text;
	text = doc.createTextNode(localHostName);
	element_localhostname.appendChild(text);
	text = doc.createTextNode(userName);
	element_username.appendChild(text);
	text = doc.createTextNode(ip);
	element_ip.appendChild(text);
	text.clear();

	root.appendChild(element_localhostname);
	root.appendChild(element_username);
	root.appendChild(element_ip);

	if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;
	QTextStream out(&file);
	doc.save(out, 4);
	file.close();
}

void xmlUtils::update_username_xml_DOM( QString fileName, QString userName )
{
	QFile file(fileName);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return;
	QDomDocument doc;
	if(!doc.setContent(&file))
	{
		file.close();
		return;
	}
	file.close();

	QDomNodeList lists = doc.elementsByTagName("profile");
	QDomNodeList child = lists.at(0).childNodes();
	child.at(1).toElement().firstChild().setNodeValue(userName);

	if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QTextStream out(&file);
	doc.save(out, 4);
	file.close();
}

void xmlUtils::do_xml_DOM( const QString opt, QString fileName )
{

}

QString xmlUtils::read_username_xml_DOM( QString fileName )
{
	QString strUserName;
	QFile file(fileName);
	if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
		return "";
	QString errorStr;
	int errorLine;
	int errorColumn;

	QDomDocument doc;
	if(!doc.setContent(&file, false, &errorStr, &errorLine, &errorColumn))
	{
		file.close();
		return "";
	}
	file.close();

	QDomElement root = doc.documentElement();
	if(root.tagName() != "profile")
		return "";

	QDomNodeList lists = doc.elementsByTagName("profile");
	QDomNodeList child = lists.at(0).childNodes();
	strUserName = child.at(1).toElement().text();

	return strUserName;
}


