#include "normalsetwidget.h"

normalSetWidget::normalSetWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit_D->setStyleSheet("background-color:white;");
}

normalSetWidget::~normalSetWidget()
{

}
