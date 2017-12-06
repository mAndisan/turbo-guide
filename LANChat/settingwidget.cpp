#include "settingwidget.h"
#include "xmlUtils.h"
#include <QDebug>

settingWidget::settingWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initData();
	initView();
}

settingWidget::~settingWidget()
{
	delete m_pAccountSetWidget;
	delete m_pNormalSetWidget;
	delete m_pAboutSetWidget;
	delete m_pListWidget;
	delete m_pHLayout;
}

void settingWidget::initView()
{
	m_pHLayout = new QHBoxLayout;
	m_pListWidget = new QListWidget;
	m_pAccountSetWidget = new accountSetWidget;
	m_pNormalSetWidget = new normalSetWidget;
	m_pAboutSetWidget = new aboutSetWidget;

	m_pListWidget->setMaximumWidth(100);
	m_pListWidget->setFrameShape(QListWidget::NoFrame);
	//账号设置
	m_pItemAccount = new QListWidgetItem;
	m_pItemAccount->setText(QStringLiteral("账号设置"));
	m_pItemAccount->setSizeHint(QSize(0, 40));
	m_pListWidget->addItem(m_pItemAccount);

	//通用设置
	m_pItemNormal = new QListWidgetItem;
	m_pItemNormal->setText(QStringLiteral("通用设置"));
	m_pItemNormal->setSizeHint(QSize(0, 40));
	m_pListWidget->addItem(m_pItemNormal);

	//关于
	m_pItemAbout = new QListWidgetItem;
	m_pItemAbout->setText(QStringLiteral("关于"));
	m_pItemAbout->setSizeHint(QSize(0, 40));
	m_pListWidget->addItem(m_pItemAbout);
	m_pHLayout->addWidget(m_pListWidget);

	m_pAccountSetWidget->setUserName(m_strUserName);
	m_pHLayout->addWidget(m_pAccountSetWidget);
	
	m_pHLayout->addWidget(m_pNormalSetWidget);
	m_pNormalSetWidget->hide();

	m_pHLayout->addWidget(m_pAboutSetWidget);
	m_pAboutSetWidget->hide();

	this->setLayout(m_pHLayout);

	connect(m_pListWidget, SIGNAL(itemClicked(QListWidgetItem *)), this, SLOT(onItemClicked( QListWidgetItem *)));
}

void settingWidget::initData()
{
	xmlUtils objXMLUtils;
	m_strUserName = objXMLUtils.read_username_xml_DOM("profile.xml");

	m_pHLayout = NULL;
	m_pListWidget = NULL;
	m_pAccountSetWidget = NULL;
	m_pNormalSetWidget = NULL;
	m_pAboutSetWidget = NULL;
}

void settingWidget::onItemClicked( QListWidgetItem *pItem )
{
	if(pItem->text() == QStringLiteral("账号设置"))
	{
		qDebug() << "account item clicked";
		m_pNormalSetWidget->hide();
		m_pAboutSetWidget->hide();
		m_pAccountSetWidget->show();
	}
	else if(pItem->text() == QStringLiteral("通用设置"))
	{
		qDebug() << "normal item clicked";
		m_pAccountSetWidget->hide();
		m_pAboutSetWidget->hide();
		m_pNormalSetWidget->show();
	}
	else
	{
		qDebug() << "about item clicked";
		m_pAccountSetWidget->hide();
		m_pNormalSetWidget->hide();
		m_pAboutSetWidget->show();
	}
}
