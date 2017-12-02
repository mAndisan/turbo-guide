#pragma once
#include <QDomDocument>
#include <QFile>
#include <QTextStream>

class xmlUtils
{
public:
	xmlUtils(void);
	~xmlUtils(void);

	void createXML(QString strFileName);
};

