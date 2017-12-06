#ifndef NORMALSETWIDGET_H
#define NORMALSETWIDGET_H

#include <QWidget>
#include "ui_normalsetwidget.h"

class normalSetWidget : public QWidget
{
	Q_OBJECT

public:
	normalSetWidget(QWidget *parent = 0);
	~normalSetWidget();

private:
	Ui::normalSetWidget ui;
};

#endif // NORMALSETWIDGET_H
