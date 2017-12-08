#ifndef SETTINGWIDGET_H
#define SETTINGWIDGET_H

#include <QWidget>
#include "ui_settingwidget.h"
#include <QHBoxLayout>
#include <QListWidget>
#include "accountsetwidget.h"
#include "normalsetwidget.h"
#include "aboutsetwidget.h"

class settingWidget : public QWidget
{
	Q_OBJECT

public:
	settingWidget(QWidget *parent = 0);
	~settingWidget();

private:
	Ui::settingWidget ui;

	QHBoxLayout *m_pHLayout;
	QListWidget *m_pListWidget;
	QListWidgetItem *m_pItemAccount;
	QListWidgetItem *m_pItemNormal;
	QListWidgetItem *m_pItemAbout;
	accountSetWidget *m_pAccountSetWidget;
	normalSetWidget *m_pNormalSetWidget;
	aboutSetWidget *m_pAboutSetWidget;

	QString m_strUserName;
private:
	void closeEvent(QCloseEvent *event);
	void initView();
	void initData();

private slots:
	void onItemClicked(QListWidgetItem *pItem);
};

#endif // SETTINGWIDGET_H
