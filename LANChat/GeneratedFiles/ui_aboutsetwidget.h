/********************************************************************************
** Form generated from reading UI file 'aboutsetwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTSETWIDGET_H
#define UI_ABOUTSETWIDGET_H

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

class Ui_aboutSetWidget
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_gitLink;

    void setupUi(QWidget *aboutSetWidget)
    {
        if (aboutSetWidget->objectName().isEmpty())
            aboutSetWidget->setObjectName(QStringLiteral("aboutSetWidget"));
        aboutSetWidget->resize(400, 300);
        verticalLayout = new QVBoxLayout(aboutSetWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(aboutSetWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(80, 16777215));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        label_2 = new QLabel(aboutSetWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(aboutSetWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMaximumSize(QSize(16777215, 16777215));
        label_3->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_2->addWidget(label_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_gitLink = new QLabel(aboutSetWidget);
        label_gitLink->setObjectName(QStringLiteral("label_gitLink"));
        label_gitLink->setFont(font);
        label_gitLink->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout_3->addWidget(label_gitLink);


        verticalLayout->addLayout(horizontalLayout_3);


        retranslateUi(aboutSetWidget);

        QMetaObject::connectSlotsByName(aboutSetWidget);
    } // setupUi

    void retranslateUi(QWidget *aboutSetWidget)
    {
        aboutSetWidget->setWindowTitle(QApplication::translate("aboutSetWidget", "aboutSetWidget", 0));
        label->setText(QApplication::translate("aboutSetWidget", "\347\211\210\346\234\254\344\277\241\346\201\257", 0));
        label_2->setText(QApplication::translate("aboutSetWidget", "\345\217\212\346\227\266\351\233\250 0.0.1", 0));
        label_3->setText(QApplication::translate("aboutSetWidget", "\345\274\200\346\272\220\350\257\264\346\230\216", 0));
        label_gitLink->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class aboutSetWidget: public Ui_aboutSetWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTSETWIDGET_H
