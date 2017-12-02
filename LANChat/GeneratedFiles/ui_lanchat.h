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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
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
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout_4;
    QFontComboBox *fontComboBox;
    QComboBox *fontsizecomboBox;
    QToolButton *textbold;
    QToolButton *textitalic;
    QToolButton *textUnderline;
    QToolButton *textColor;
    QToolButton *sendFile;
    QToolButton *save;
    QToolButton *clear;
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/LANChat/image/MSN-Messenger.png"), QSize(), QIcon::Normal, QIcon::Off);
        LANChatClass->setWindowIcon(icon);
        centralWidget = new QWidget(LANChatClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelName = new QLabel(centralWidget);
        labelName->setObjectName(QStringLiteral("labelName"));
        QFont font;
        font.setPointSize(16);
        labelName->setFont(font);

        verticalLayout->addWidget(labelName);

        textBrowser = new QTextBrowser(centralWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(2);
        sizePolicy.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy);
        textBrowser->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(textBrowser);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        fontComboBox = new QFontComboBox(centralWidget);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(fontComboBox->sizePolicy().hasHeightForWidth());
        fontComboBox->setSizePolicy(sizePolicy1);
        fontComboBox->setMinimumSize(QSize(1, 25));

        horizontalLayout_4->addWidget(fontComboBox);

        fontsizecomboBox = new QComboBox(centralWidget);
        fontsizecomboBox->setObjectName(QStringLiteral("fontsizecomboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(fontsizecomboBox->sizePolicy().hasHeightForWidth());
        fontsizecomboBox->setSizePolicy(sizePolicy2);
        fontsizecomboBox->setMinimumSize(QSize(0, 25));
        fontsizecomboBox->setEditable(true);

        horizontalLayout_4->addWidget(fontsizecomboBox);

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


        verticalLayout->addLayout(horizontalLayout_4);

        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMaximumSize(QSize(16777215, 16777215));

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
        gridLayout_2->setSpacing(6);
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
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(20);
        listWidgetUser->setFont(font1);
        listWidgetUser->setIconSize(QSize(30, 30));

        gridLayout_2->addWidget(listWidgetUser, 0, 0, 1, 1);


        horizontalLayout_3->addLayout(gridLayout_2);

        LANChatClass->setCentralWidget(centralWidget);

        retranslateUi(LANChatClass);
        QObject::connect(send, SIGNAL(clicked()), LANChatClass, SLOT(onSend_clicked()));
        QObject::connect(sendFile, SIGNAL(clicked()), LANChatClass, SLOT(onSendfile_clicked()));
        QObject::connect(fontsizecomboBox, SIGNAL(currentIndexChanged(QString)), LANChatClass, SLOT(onFontsizecomboBox_currentIndexChanged(QString)));
        QObject::connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), LANChatClass, SLOT(onFontComboBox_currentFontChanged(QFont)));
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
        fontsizecomboBox->clear();
        fontsizecomboBox->insertItems(0, QStringList()
         << QApplication::translate("LANChatClass", "9", 0)
         << QApplication::translate("LANChatClass", "10", 0)
         << QApplication::translate("LANChatClass", "11", 0)
         << QApplication::translate("LANChatClass", "12", 0)
         << QApplication::translate("LANChatClass", "13", 0)
         << QApplication::translate("LANChatClass", "14", 0)
         << QApplication::translate("LANChatClass", "15", 0)
         << QApplication::translate("LANChatClass", "16", 0)
         << QApplication::translate("LANChatClass", "17", 0)
         << QApplication::translate("LANChatClass", "18", 0)
         << QApplication::translate("LANChatClass", "19", 0)
         << QApplication::translate("LANChatClass", "20", 0)
         << QApplication::translate("LANChatClass", "21", 0)
         << QApplication::translate("LANChatClass", "22", 0)
        );
        fontsizecomboBox->setCurrentText(QApplication::translate("LANChatClass", "9", 0));
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
