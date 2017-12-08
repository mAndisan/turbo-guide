#include "aboutsetwidget.h"

aboutSetWidget::aboutSetWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//setStyleSheet("background-color:white;");

	ui.label_gitLink->setOpenExternalLinks(true);
	//ui.label_gitLink->setText("<a href = https://github.com/mAndisan/turbo-guide>https://github.com/mAndisan/turbo-guide</a>");
	ui.label_gitLink->setText(QString::fromLocal8Bit("<style> a {text-decoration:none} </style> <a href = https://github.com/mAndisan/turbo-guide>https://github.com/mAndisan/turbo-guide</a>"));

}

aboutSetWidget::~aboutSetWidget()
{

}
