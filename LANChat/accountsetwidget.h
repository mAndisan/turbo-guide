#ifndef ACCOUNTSETWIDGET_H
#define ACCOUNTSETWIDGET_H

#include <QWidget>
#include "ui_accountsetwidget.h"

class accountSetWidget : public QWidget
{
	Q_OBJECT

public:
	accountSetWidget(QWidget *parent = 0);
	~accountSetWidget();

private:
	Ui::accountSetWidget ui;

public:
	void setUserName(QString strUserName);
};

#endif // ACCOUNTSETWIDGET_H
