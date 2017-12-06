#include "accountsetwidget.h"

accountSetWidget::accountSetWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

accountSetWidget::~accountSetWidget()
{

}

void accountSetWidget::setUserName(QString strUserName)
{
	ui.lineEdit_UserName->setText(strUserName);
}
