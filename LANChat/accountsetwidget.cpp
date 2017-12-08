#include "accountsetwidget.h"
#include "xmlUtils.h"

accountSetWidget::accountSetWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit_UserName->setStyleSheet("background-color:white;");
}

accountSetWidget::~accountSetWidget()
{

}

void accountSetWidget::setUserName(QString strUserName)
{
	if(strUserName.length() > 0)
		ui.lineEdit_UserName->setText(strUserName);
	else
	{
		QString strName = ui.lineEdit_UserName->text();
		xmlUtils xml;
		xml.update_username_xml_DOM(gstrXMLName, strName);
	}
}
