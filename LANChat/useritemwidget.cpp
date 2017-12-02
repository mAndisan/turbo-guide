#include "useritemwidget.h"

userItemWidget::userItemWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

userItemWidget::~userItemWidget()
{

}

void userItemWidget::setUserHeadImage( QString strImageName )
{
	ui.label_HeadImage->setPixmap(QPixmap(strImageName));
}

void userItemWidget::setUserName( QString strName )
{
	ui.label_UserName->setText(strName);
}

void userItemWidget::setUserIP( QString strIP )
{
	ui.label_IP->setText(strIP);
}

QString userItemWidget::userName()
{
	return ui.label_UserName->text();
}

QString userItemWidget::userIP()
{
	return ui.label_IP->text();
}
