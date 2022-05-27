/********************************************************************************
** Form generated from reading UI file 'pagetwo.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGETWO_H
#define UI_PAGETWO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageTwo
{
public:

    void setupUi(QWidget *PageTwo)
    {
        if (PageTwo->objectName().isEmpty())
            PageTwo->setObjectName(QString::fromUtf8("PageTwo"));
        PageTwo->resize(406, 446);

        retranslateUi(PageTwo);

        QMetaObject::connectSlotsByName(PageTwo);
    } // setupUi

    void retranslateUi(QWidget *PageTwo)
    {
        PageTwo->setWindowTitle(QApplication::translate("PageTwo", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageTwo: public Ui_PageTwo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGETWO_H
