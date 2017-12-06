/********************************************************************************
** Form generated from reading UI file 'useritemwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERITEMWIDGET_H
#define UI_USERITEMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_userItemWidget
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_HeadImage;
    QVBoxLayout *verticalLayout;
    QLabel *label_UserName;
    QLabel *label_IP;

    void setupUi(QWidget *userItemWidget)
    {
        if (userItemWidget->objectName().isEmpty())
            userItemWidget->setObjectName(QStringLiteral("userItemWidget"));
        userItemWidget->resize(380, 72);
        horizontalLayoutWidget = new QWidget(userItemWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 0, 331, 71));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_HeadImage = new QLabel(horizontalLayoutWidget);
        label_HeadImage->setObjectName(QStringLiteral("label_HeadImage"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_HeadImage->sizePolicy().hasHeightForWidth());
        label_HeadImage->setSizePolicy(sizePolicy);
        label_HeadImage->setMaximumSize(QSize(45, 45));

        horizontalLayout->addWidget(label_HeadImage);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_UserName = new QLabel(horizontalLayoutWidget);
        label_UserName->setObjectName(QStringLiteral("label_UserName"));
        label_UserName->setMaximumSize(QSize(16777215, 40));
        QFont font;
        font.setPointSize(18);
        label_UserName->setFont(font);
        label_UserName->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        verticalLayout->addWidget(label_UserName);

        label_IP = new QLabel(horizontalLayoutWidget);
        label_IP->setObjectName(QStringLiteral("label_IP"));
        QFont font1;
        font1.setPointSize(12);
        label_IP->setFont(font1);
        label_IP->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout->addWidget(label_IP);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(userItemWidget);

        QMetaObject::connectSlotsByName(userItemWidget);
    } // setupUi

    void retranslateUi(QWidget *userItemWidget)
    {
        userItemWidget->setWindowTitle(QApplication::translate("userItemWidget", "userItemWidget", 0));
        label_HeadImage->setText(QString());
        label_UserName->setText(QString());
        label_IP->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class userItemWidget: public Ui_userItemWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERITEMWIDGET_H
