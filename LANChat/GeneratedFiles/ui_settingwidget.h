/********************************************************************************
** Form generated from reading UI file 'settingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWIDGET_H
#define UI_SETTINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_settingWidget
{
public:

    void setupUi(QWidget *settingWidget)
    {
        if (settingWidget->objectName().isEmpty())
            settingWidget->setObjectName(QStringLiteral("settingWidget"));
        settingWidget->resize(400, 300);

        retranslateUi(settingWidget);

        QMetaObject::connectSlotsByName(settingWidget);
    } // setupUi

    void retranslateUi(QWidget *settingWidget)
    {
        settingWidget->setWindowTitle(QApplication::translate("settingWidget", "\350\256\276\347\275\256", 0));
    } // retranslateUi

};

namespace Ui {
    class settingWidget: public Ui_settingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWIDGET_H
