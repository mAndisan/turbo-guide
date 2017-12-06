#ifndef ABOUTSETWIDGET_H
#define ABOUTSETWIDGET_H

#include <QWidget>
#include "ui_aboutsetwidget.h"

class aboutSetWidget : public QWidget
{
	Q_OBJECT

public:
	aboutSetWidget(QWidget *parent = 0);
	~aboutSetWidget();

private:
	Ui::aboutSetWidget ui;
};

#endif // ABOUTSETWIDGET_H
