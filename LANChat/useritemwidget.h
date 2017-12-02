#ifndef USERITEMWIDGET_H
#define USERITEMWIDGET_H

#include <QWidget>
#include <QString>
#include "ui_useritemwidget.h"

class userItemWidget : public QWidget
{
	Q_OBJECT

public:
	userItemWidget(QWidget *parent = 0);
	~userItemWidget();

private:
	Ui::userItemWidget ui;

public:
	void setUserHeadImage(QString strImageName);
	void setUserName(QString strName);
	void setUserIP(QString strIP);

	QString userName();
	QString userIP();
};

#endif // USERITEMWIDGET_H
