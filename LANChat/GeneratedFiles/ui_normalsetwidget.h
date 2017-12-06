/********************************************************************************
** Form generated from reading UI file 'normalsetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALSETWIDGET_H
#define UI_NORMALSETWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_normalSetWidget
{
public:

    void setupUi(QWidget *normalSetWidget)
    {
        if (normalSetWidget->objectName().isEmpty())
            normalSetWidget->setObjectName(QStringLiteral("normalSetWidget"));
        normalSetWidget->resize(400, 300);

        retranslateUi(normalSetWidget);

        QMetaObject::connectSlotsByName(normalSetWidget);
    } // setupUi

    void retranslateUi(QWidget *normalSetWidget)
    {
        normalSetWidget->setWindowTitle(QApplication::translate("normalSetWidget", "normalSetWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class normalSetWidget: public Ui_normalSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALSETWIDGET_H
