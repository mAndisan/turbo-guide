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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_normalSetWidget
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_D;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_Change;
    QPushButton *pushButton_OpenDir;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pushButton_Clean;

    void setupUi(QWidget *normalSetWidget)
    {
        if (normalSetWidget->objectName().isEmpty())
            normalSetWidget->setObjectName(QStringLiteral("normalSetWidget"));
        normalSetWidget->setWindowModality(Qt::NonModal);
        normalSetWidget->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(normalSetWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(9, 0, 9, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        label = new QLabel(normalSetWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_6->addWidget(label);

        verticalSpacer_3 = new QSpacerItem(20, 60, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_3);


        horizontalLayout->addLayout(verticalLayout_6);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        lineEdit_D = new QLineEdit(normalSetWidget);
        lineEdit_D->setObjectName(QStringLiteral("lineEdit_D"));
        lineEdit_D->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(lineEdit_D);

        label_2 = new QLabel(normalSetWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 14));

        verticalLayout->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 0, -1, -1);
        pushButton_Change = new QPushButton(normalSetWidget);
        pushButton_Change->setObjectName(QStringLiteral("pushButton_Change"));

        horizontalLayout_2->addWidget(pushButton_Change);

        pushButton_OpenDir = new QPushButton(normalSetWidget);
        pushButton_OpenDir->setObjectName(QStringLiteral("pushButton_OpenDir"));

        horizontalLayout_2->addWidget(pushButton_OpenDir);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(normalSetWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pushButton_Clean = new QPushButton(normalSetWidget);
        pushButton_Clean->setObjectName(QStringLiteral("pushButton_Clean"));

        verticalLayout_3->addWidget(pushButton_Clean);


        horizontalLayout_3->addLayout(verticalLayout_3);


        verticalLayout_2->addLayout(horizontalLayout_3);


        retranslateUi(normalSetWidget);

        QMetaObject::connectSlotsByName(normalSetWidget);
    } // setupUi

    void retranslateUi(QWidget *normalSetWidget)
    {
        normalSetWidget->setWindowTitle(QString());
        label->setText(QApplication::translate("normalSetWidget", "\346\226\207\344\273\266\347\256\241\347\220\206", 0));
        label_2->setText(QApplication::translate("normalSetWidget", "\346\226\207\344\273\266\351\273\230\350\256\244\344\277\235\345\255\230\344\275\215\347\275\256", 0));
        pushButton_Change->setText(QApplication::translate("normalSetWidget", "\346\233\264\346\224\271", 0));
        pushButton_OpenDir->setText(QApplication::translate("normalSetWidget", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", 0));
        label_3->setText(QApplication::translate("normalSetWidget", "\351\200\232\347\224\250", 0));
        pushButton_Clean->setText(QApplication::translate("normalSetWidget", "\346\270\205\347\251\272\350\201\212\345\244\251\350\256\260\345\275\225", 0));
    } // retranslateUi

};

namespace Ui {
    class normalSetWidget: public Ui_normalSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALSETWIDGET_H
