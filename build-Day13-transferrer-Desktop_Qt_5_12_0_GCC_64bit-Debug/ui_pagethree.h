/********************************************************************************
** Form generated from reading UI file 'pagethree.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAGETHREE_H
#define UI_PAGETHREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PageThree
{
public:
    QTextBrowser *textBrowser;
    QWidget *widget;
    QLabel *label;
    QWidget *widget_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QFrame *line;

    void setupUi(QWidget *PageThree)
    {
        if (PageThree->objectName().isEmpty())
            PageThree->setObjectName(QString::fromUtf8("PageThree"));
        PageThree->resize(406, 446);
        textBrowser = new QTextBrowser(PageThree);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 391, 91));
        widget = new QWidget(PageThree);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(40, 110, 101, 81));
        widget->setStyleSheet(QString::fromUtf8("image:    url(:/new/icon/src.png)"));
        label = new QLabel(PageThree);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(160, 110, 121, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        widget_2 = new QWidget(PageThree);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(30, 230, 201, 191));
        widget_2->setStyleSheet(QString::fromUtf8("image:  url(:/new/icon/8414647.png)"));
        label_2 = new QLabel(PageThree);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 140, 211, 20));
        QFont font1;
        font1.setPointSize(6);
        label_2->setFont(font1);
        label_3 = new QLabel(PageThree);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(270, 240, 101, 18));
        label_4 = new QLabel(PageThree);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(270, 270, 121, 18));
        label_5 = new QLabel(PageThree);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(270, 300, 121, 61));
        label_5->setAcceptDrops(false);
        label_5->setWordWrap(true);
        line = new QFrame(PageThree);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(20, 200, 371, 16));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        retranslateUi(PageThree);

        QMetaObject::connectSlotsByName(PageThree);
    } // setupUi

    void retranslateUi(QWidget *PageThree)
    {
        PageThree->setWindowTitle(QApplication::translate("PageThree", "Form", nullptr));
        textBrowser->setHtml(QApplication::translate("PageThree", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Sans Serif'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:20pt; font-weight:600;\">My Transferrer</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">This application refers to Kylin Chuanshu.</span></p>\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        label->setText(QApplication::translate("PageThree", "Kylin Chuanshu ", nullptr));
        label_2->setText(QApplication::translate("PageThree", "https://www.ubuntukylin.com/applications/79-cn.html", nullptr));
        label_3->setText(QApplication::translate("PageThree", "Author:        Gsq", nullptr));
        label_4->setText(QApplication::translate("PageThree", "Date:     2022-05-25", nullptr));
        label_5->setText(QApplication::translate("PageThree", "(C)  Transferrer                                       Version 1.0.0       (R)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PageThree: public Ui_PageThree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAGETHREE_H
