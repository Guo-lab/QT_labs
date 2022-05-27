/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_9;
    QWidget *loc;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(444, 639);
        Widget->setWindowOpacity(1.000000000000000);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 411, 51));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(layoutWidget->sizePolicy().hasHeightForWidth());
        layoutWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/people/people.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        sizePolicy.setHeightForWidth(pushButton_3->sizePolicy().hasHeightForWidth());
        pushButton_3->setSizePolicy(sizePolicy);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/people/sent.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon1);
        pushButton_3->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/people/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon2);
        pushButton_2->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(pushButton_2);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 560, 421, 51));
        sizePolicy.setHeightForWidth(layoutWidget1->sizePolicy().hasHeightForWidth());
        layoutWidget1->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_8 = new QPushButton(layoutWidget1);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        sizePolicy.setHeightForWidth(pushButton_8->sizePolicy().hasHeightForWidth());
        pushButton_8->setSizePolicy(sizePolicy);
        pushButton_8->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pushButton_8);

        pushButton_7 = new QPushButton(layoutWidget1);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy);
        pushButton_7->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pushButton_7);

        pushButton_9 = new QPushButton(layoutWidget1);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        sizePolicy.setHeightForWidth(pushButton_9->sizePolicy().hasHeightForWidth());
        pushButton_9->setSizePolicy(sizePolicy);
        pushButton_9->setIconSize(QSize(32, 32));

        horizontalLayout_3->addWidget(pushButton_9);

        loc = new QWidget(Widget);
        loc->setObjectName(QString::fromUtf8("loc"));
        loc->setGeometry(QRect(20, 80, 41, 31));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Transferrer", nullptr));
        pushButton->setText(QApplication::translate("Widget", "        Friends", nullptr));
        pushButton_3->setText(QApplication::translate("Widget", "        Sent", nullptr));
        pushButton_2->setText(QApplication::translate("Widget", "        About", nullptr));
        pushButton_8->setText(QApplication::translate("Widget", "        Received", nullptr));
        pushButton_7->setText(QApplication::translate("Widget", "        IP", nullptr));
        pushButton_9->setText(QApplication::translate("Widget", "        Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
