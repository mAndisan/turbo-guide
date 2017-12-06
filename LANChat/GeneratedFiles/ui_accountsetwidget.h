/********************************************************************************
** Form generated from reading UI file 'accountsetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCOUNTSETWIDGET_H
#define UI_ACCOUNTSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_accountSetWidget
{
public:
    QLabel *labelUserName;
    QLineEdit *lineEdit_UserName;

    void setupUi(QWidget *accountSetWidget)
    {
        if (accountSetWidget->objectName().isEmpty())
            accountSetWidget->setObjectName(QStringLiteral("accountSetWidget"));
        accountSetWidget->resize(400, 300);
        accountSetWidget->setMinimumSize(QSize(0, 0));
        labelUserName = new QLabel(accountSetWidget);
        labelUserName->setObjectName(QStringLiteral("labelUserName"));
        labelUserName->setGeometry(QRect(60, 50, 51, 21));
        lineEdit_UserName = new QLineEdit(accountSetWidget);
        lineEdit_UserName->setObjectName(QStringLiteral("lineEdit_UserName"));
        lineEdit_UserName->setGeometry(QRect(120, 50, 141, 20));

        retranslateUi(accountSetWidget);

        QMetaObject::connectSlotsByName(accountSetWidget);
    } // setupUi

    void retranslateUi(QWidget *accountSetWidget)
    {
        accountSetWidget->setWindowTitle(QApplication::translate("accountSetWidget", "accountSetWidget", 0));
        labelUserName->setText(QApplication::translate("accountSetWidget", "\347\224\250\346\210\267\345\220\215\357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class accountSetWidget: public Ui_accountSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCOUNTSETWIDGET_H
