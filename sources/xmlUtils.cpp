#include "xmlUtils.h"


xmlUtils::xmlUtils(void)
{
}


xmlUtils::~xmlUtils(void)
{
}

void xmlUtils::createXML( QString strFileName )
{
	QFile xmlFile(strFileName);
	if(!xmlFile.open(QIODevice::WriteOnly | QIODevice::Text))
		return;

	QDomDocument domDoc;
	QString strHeader("version=\"1.0\" encoding=\"UTF-8\"");
	domDoc.appendChild(domDoc.createProcessingInstruction("xml", strHeader));

	QDomElement root_elem = domDoc.createElement("self");
	domDoc.appendChild(root_elem);

	QDomElement item1 = domDoc.createElement("item");
	item1.setAttribute("src", "&lt;&gt;");
	item1.setAttribute("dst", "<>");
	root_elem.appendChild(item1);

	QDomElement item2 = domDoc.createElement("item");
	item2.setAttribute("src", "&quot;&apos;&amp;");
	item2.setAttribute("dst", "\"'&");
	root_elem.appendChild(item2);

	QDomElement item3 = domDoc.createElement("item");
	item3.setAttribute("src", "test data");
	item3.setAttribute("dst", "one two");
	root_elem.appendChild(item3);

	QTextStream out(&xmlFile);
	domDoc.save(out, 4);
	xmlFile.close();
}
