/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QLabel *label;
    QTextEdit *textEdit;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QString::fromUtf8("Settings"));
        Settings->resize(494, 305);
        label = new QLabel(Settings);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 30, 261, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        textEdit = new QTextEdit(Settings);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 70, 421, 41));
        textEdit->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(Settings);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(260, 120, 201, 51));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(40, 190, 241, 21));
        label_2->setFont(font);
        pushButton_2 = new QPushButton(Settings);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(260, 220, 201, 51));
        pushButton_2->setFont(font1);

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QDialog *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Dialog", nullptr));
        label->setText(QApplication::translate("Settings", "Directory for Saving Files", nullptr));
        pushButton->setText(QApplication::translate("Settings", "Change the directory", nullptr));
        label_2->setText(QApplication::translate("Settings", "Theme Color (Background)", nullptr));
        pushButton_2->setText(QApplication::translate("Settings", "Change the Theme Color", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
