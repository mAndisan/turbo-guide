/********************************************************************************
** Form generated from reading UI file 'lanchat.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LANCHAT_H
#define UI_LANCHAT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LANChatClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *labelName;
    QFrame *line;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *textbold;
    QToolButton *textitalic;
    QToolButton *textUnderline;
    QToolButton *textColor;
    QToolButton *sendFile;
    QToolButton *save;
    QToolButton *clear;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer;
    QPushButton *send;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *onlineUser;
    QListWidget *listWidgetUser;

    void setupUi(QMainWindow *LANChatClass)
    {
        if (LANChatClass->objectName().isEmpty())
            LANChatClass->setObjectName(QStringLiteral("LANChatClass"));
        LANChatClass->resize(748, 510);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        QBrush brush1(QColor(240, 240, 240, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        LANChatClass->setPalette(palette);
        QIcon icon;
        icon.addFile(QStringLiteral(":/LANChat/image/MSN-Messenger.png"), QSize(), QIcon::Normal, QIcon::Off);
        LANChatClass->setWindowIcon(icon);
        centralWidget = new QWidget(LANChatClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QPalette palette1;
        QBrush brush2(QColor(245, 245, 245, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Shadow, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Shadow, brush2);
        centralWidget->setPalette(palette1);
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(1, 0, 0, 1);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelName = new QLabel(centralWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        QFont font;
        font.setPointSize(16);
        labelName->setFont(font);

        verticalLayout->addWidget(labelName);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMinimumSize(QSize(550, 0));
        textBrowser->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        textBrowser->setPalette(palette2);
        textBrowser->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        textbold = new QToolButton(centralWidget);
        textbold->setObjectName(QStringLiteral("textbold"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/LANChat/image/textbold.png"), QSize(), QIcon::Normal, QIcon::Off);
        textbold->setIcon(icon1);
        textbold->setIconSize(QSize(24, 24));
        textbold->setCheckable(true);
        textbold->setAutoRaise(true);

        horizontalLayout_4->addWidget(textbold);

        textitalic = new QToolButton(centralWidget);
        textitalic->setObjectName(QStringLiteral("textitalic"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/LANChat/image/textitalic.png"), QSize(), QIcon::Normal, QIcon::Off);
        textitalic->setIcon(icon2);
        textitalic->setIconSize(QSize(24, 24));
        textitalic->setCheckable(true);
        textitalic->setAutoRaise(true);

        horizontalLayout_4->addWidget(textitalic);

        textUnderline = new QToolButton(centralWidget);
        textUnderline->setObjectName(QStringLiteral("textUnderline"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/LANChat/image/textunder.png"), QSize(), QIcon::Normal, QIcon::Off);
        textUnderline->setIcon(icon3);
        textUnderline->setIconSize(QSize(24, 24));
        textUnderline->setCheckable(true);
        textUnderline->setAutoRaise(true);

        horizontalLayout_4->addWidget(textUnderline);

        textColor = new QToolButton(centralWidget);
        textColor->setObjectName(QStringLiteral("textColor"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/LANChat/image/textcolor.png"), QSize(), QIcon::Normal, QIcon::Off);
        textColor->setIcon(icon4);
        textColor->setIconSize(QSize(24, 24));
        textColor->setCheckable(false);
        textColor->setAutoRaise(true);

        horizontalLayout_4->addWidget(textColor);

        sendFile = new QToolButton(centralWidget);
        sendFile->setObjectName(QStringLiteral("sendFile"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/LANChat/image/fileopen.png"), QSize(), QIcon::Normal, QIcon::Off);
        sendFile->setIcon(icon5);
        sendFile->setIconSize(QSize(24, 24));
        sendFile->setCheckable(false);
        sendFile->setAutoRaise(true);

        horizontalLayout_4->addWidget(sendFile);

        save = new QToolButton(centralWidget);
        save->setObjectName(QStringLiteral("save"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/LANChat/image/Floppy.png"), QSize(), QIcon::Normal, QIcon::Off);
        save->setIcon(icon6);
        save->setIconSize(QSize(24, 24));
        save->setCheckable(false);
        save->setAutoRaise(true);

        horizontalLayout_4->addWidget(save);

        clear = new QToolButton(centralWidget);
        clear->setObjectName(QStringLiteral("clear"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/LANChat/image/Bin (empty).png"), QSize(), QIcon::Normal, QIcon::Off);
        clear->setIcon(icon7);
        clear->setIconSize(QSize(24, 24));
        clear->setCheckable(false);
        clear->setAutoRaise(true);

        horizontalLayout_4->addWidget(clear);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_4);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 16777215));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::Base, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush2);
        textEdit->setPalette(palette3);
        textEdit->setFrameShape(QFrame::NoFrame);

        verticalLayout->addWidget(textEdit);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));
        send->setMinimumSize(QSize(100, 25));

        horizontalLayout_5->addWidget(send);


        verticalLayout->addLayout(horizontalLayout_5);


        horizontalLayout_3->addLayout(verticalLayout);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(0);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        onlineUser = new QLabel(centralWidget);
        onlineUser->setObjectName(QStringLiteral("onlineUser"));

        horizontalLayout_2->addWidget(onlineUser);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        listWidgetUser = new QListWidget(centralWidget);
        listWidgetUser->setObjectName(QStringLiteral("listWidgetUser"));
        listWidgetUser->setMaximumSize(QSize(300, 16777215));
        QPalette palette4;
        QBrush brush3(QColor(227, 227, 227, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Light, brush3);
        QBrush brush4(QColor(238, 234, 232, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Light, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Disabled, QPalette::Light, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        listWidgetUser->setPalette(palette4);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        listWidgetUser->setFont(font1);
        listWidgetUser->setFrameShape(QFrame::NoFrame);
        listWidgetUser->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(listWidgetUser, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        LANChatClass->setCentralWidget(centralWidget);

        retranslateUi(LANChatClass);
        QObject::connect(send, SIGNAL(clicked()), LANChatClass, SLOT(onSend_clicked()));
        QObject::connect(sendFile, SIGNAL(clicked()), LANChatClass, SLOT(onSendfile_clicked()));
        QObject::connect(textbold, SIGNAL(clicked(bool)), LANChatClass, SLOT(onTextbold_clicked(bool)));
        QObject::connect(textitalic, SIGNAL(clicked(bool)), LANChatClass, SLOT(onTextitalic_clicked(bool)));
        QObject::connect(textColor, SIGNAL(clicked()), LANChatClass, SLOT(onTextcolor_clicked()));
        QObject::connect(save, SIGNAL(clicked()), LANChatClass, SLOT(onSave_clicked()));
        QObject::connect(clear, SIGNAL(clicked()), LANChatClass, SLOT(onClear_clicked()));
        QObject::connect(textUnderline, SIGNAL(clicked(bool)), LANChatClass, SLOT(onTextUnderline_clicked(bool)));

        QMetaObject::connectSlotsByName(LANChatClass);
    } // setupUi

    void retranslateUi(QMainWindow *LANChatClass)
    {
        LANChatClass->setWindowTitle(QApplication::translate("LANChatClass", "\345\217\212\346\227\266\351\233\250", 0));
        labelName->setText(QString());
#ifndef QT_NO_TOOLTIP
        textbold->setToolTip(QApplication::translate("LANChatClass", "\345\212\240\347\262\227", 0));
#endif // QT_NO_TOOLTIP
        textbold->setText(QApplication::translate("LANChatClass", "...", 0));
        textitalic->setText(QApplication::translate("LANChatClass", "...", 0));
        textUnderline->setText(QApplication::translate("LANChatClass", "...", 0));
        textColor->setText(QApplication::translate("LANChatClass", "...", 0));
        sendFile->setText(QApplication::translate("LANChatClass", "...", 0));
        save->setText(QApplication::translate("LANChatClass", "...", 0));
#ifndef QT_NO_TOOLTIP
        clear->setToolTip(QApplication::translate("LANChatClass", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", 0));
#endif // QT_NO_TOOLTIP
        clear->setText(QApplication::translate("LANChatClass", "...", 0));
        send->setText(QApplication::translate("LANChatClass", "\345\217\221\351\200\201(&S)", 0));
        onlineUser->setText(QApplication::translate("LANChatClass", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", 0));
    } // retranslateUi

};

namespace Ui {
    class LANChatClass: public Ui_LANChatClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LANCHAT_H
