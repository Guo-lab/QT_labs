/********************************************************************************
** Form generated from reading UI file 'update.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UPDATE_H
#define UI_UPDATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Update
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *Update)
    {
        if (Update->objectName().isEmpty())
            Update->setObjectName(QString::fromUtf8("Update"));
        Update->resize(384, 64);
        Update->setStyleSheet(QString::fromUtf8(" background-color:rgba(88,88,88,88%);"));
        centralWidget = new QWidget(Update);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(20, 20, 151, 31));
        pushButton->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: white;\n"
"font-size: 15px;\n"
"border: 0px solid #dcdfe6;\n"
"border-radius: 5px;\n"
"hover{background-color:rgba(169,169,169,90%)};\n"
"pressed{background-color:rgba(90,90,90,90%);};\n"
"checked{background-color:rgba(90,90,90,90%);};"));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(199, 20, 151, 31));
        pushButton_2->setStyleSheet(QString::fromUtf8("background:transparent;\n"
"color: white;\n"
"font-size: 15px;\n"
"border: 0px solid #dcdfe6;\n"
"border-radius: 5px;\n"
"hover{background-color:rgba(169,169,169,90%)};\n"
"pressed{background-color:rgba(90,90,90,90%);};\n"
"checked{background-color:rgba(90,90,90,90%);};"));
        Update->setCentralWidget(centralWidget);

        retranslateUi(Update);

        QMetaObject::connectSlotsByName(Update);
    } // setupUi

    void retranslateUi(QMainWindow *Update)
    {
        Update->setWindowTitle(QApplication::translate("Update", "Update data from remote", nullptr));
        pushButton->setText(QApplication::translate("Update", "GET", nullptr));
        pushButton_2->setText(QApplication::translate("Update", "POST", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Update: public Ui_Update {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UPDATE_H
