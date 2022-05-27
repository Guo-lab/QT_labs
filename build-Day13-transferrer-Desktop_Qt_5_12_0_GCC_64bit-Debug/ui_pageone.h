/********************************************************************************
** Form generated from reading UI file 'pageone.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGEONE_H
#define UI_PAGEONE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageOne
{
public:

    void setupUi(QWidget *PageOne)
    {
        if (PageOne->objectName().isEmpty())
            PageOne->setObjectName(QString::fromUtf8("PageOne"));
        PageOne->resize(406, 446);

        retranslateUi(PageOne);

        QMetaObject::connectSlotsByName(PageOne);
    } // setupUi

    void retranslateUi(QWidget *PageOne)
    {
        PageOne->setWindowTitle(QApplication::translate("PageOne", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageOne: public Ui_PageOne {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGEONE_H
