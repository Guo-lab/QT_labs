/********************************************************************************
** Form generated from reading UI file 'calculator.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALCULATOR_H
#define UI_CALCULATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calculator
{
public:
    QAction *actionHow_to_use_this_Calculator;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QPushButton *Clear;
    QPushButton *Btn6;
    QPushButton *Btn5;
    QPushButton *Btn1;
    QPushButton *Btn7;
    QPushButton *Btn4;
    QPushButton *Btn8;
    QPushButton *Btn3;
    QPushButton *Btn0;
    QPushButton *Equal;
    QPushButton *Btn2;
    QPushButton *Btn9;
    QPushButton *Add;
    QPushButton *Subtract;
    QPushButton *Multiply;
    QPushButton *Divide;
    QLineEdit *Display;
    QMenuBar *menuBar;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Calculator)
    {
        if (Calculator->objectName().isEmpty())
            Calculator->setObjectName(QString::fromUtf8("Calculator"));
        Calculator->resize(352, 313);
        actionHow_to_use_this_Calculator = new QAction(Calculator);
        actionHow_to_use_this_Calculator->setObjectName(QString::fromUtf8("actionHow_to_use_this_Calculator"));
        centralWidget = new QWidget(Calculator);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Clear = new QPushButton(centralWidget);
        Clear->setObjectName(QString::fromUtf8("Clear"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Clear->sizePolicy().hasHeightForWidth());
        Clear->setSizePolicy(sizePolicy);
        Clear->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Clear, 4, 0, 1, 1);

        Btn6 = new QPushButton(centralWidget);
        Btn6->setObjectName(QString::fromUtf8("Btn6"));
        sizePolicy.setHeightForWidth(Btn6->sizePolicy().hasHeightForWidth());
        Btn6->setSizePolicy(sizePolicy);
        Btn6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn6, 2, 2, 1, 1);

        Btn5 = new QPushButton(centralWidget);
        Btn5->setObjectName(QString::fromUtf8("Btn5"));
        sizePolicy.setHeightForWidth(Btn5->sizePolicy().hasHeightForWidth());
        Btn5->setSizePolicy(sizePolicy);
        Btn5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn5, 2, 1, 1, 1);

        Btn1 = new QPushButton(centralWidget);
        Btn1->setObjectName(QString::fromUtf8("Btn1"));
        sizePolicy.setHeightForWidth(Btn1->sizePolicy().hasHeightForWidth());
        Btn1->setSizePolicy(sizePolicy);
        Btn1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn1, 3, 0, 1, 1);

        Btn7 = new QPushButton(centralWidget);
        Btn7->setObjectName(QString::fromUtf8("Btn7"));
        sizePolicy.setHeightForWidth(Btn7->sizePolicy().hasHeightForWidth());
        Btn7->setSizePolicy(sizePolicy);
        Btn7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn7, 1, 0, 1, 1);

        Btn4 = new QPushButton(centralWidget);
        Btn4->setObjectName(QString::fromUtf8("Btn4"));
        sizePolicy.setHeightForWidth(Btn4->sizePolicy().hasHeightForWidth());
        Btn4->setSizePolicy(sizePolicy);
        Btn4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn4, 2, 0, 1, 1);

        Btn8 = new QPushButton(centralWidget);
        Btn8->setObjectName(QString::fromUtf8("Btn8"));
        sizePolicy.setHeightForWidth(Btn8->sizePolicy().hasHeightForWidth());
        Btn8->setSizePolicy(sizePolicy);
        Btn8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn8, 1, 1, 1, 1);

        Btn3 = new QPushButton(centralWidget);
        Btn3->setObjectName(QString::fromUtf8("Btn3"));
        sizePolicy.setHeightForWidth(Btn3->sizePolicy().hasHeightForWidth());
        Btn3->setSizePolicy(sizePolicy);
        Btn3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn3, 3, 2, 1, 1);

        Btn0 = new QPushButton(centralWidget);
        Btn0->setObjectName(QString::fromUtf8("Btn0"));
        sizePolicy.setHeightForWidth(Btn0->sizePolicy().hasHeightForWidth());
        Btn0->setSizePolicy(sizePolicy);
        Btn0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn0, 4, 1, 1, 1);

        Equal = new QPushButton(centralWidget);
        Equal->setObjectName(QString::fromUtf8("Equal"));
        sizePolicy.setHeightForWidth(Equal->sizePolicy().hasHeightForWidth());
        Equal->setSizePolicy(sizePolicy);
        Equal->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Equal, 4, 2, 1, 1);

        Btn2 = new QPushButton(centralWidget);
        Btn2->setObjectName(QString::fromUtf8("Btn2"));
        sizePolicy.setHeightForWidth(Btn2->sizePolicy().hasHeightForWidth());
        Btn2->setSizePolicy(sizePolicy);
        Btn2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn2, 3, 1, 1, 1);

        Btn9 = new QPushButton(centralWidget);
        Btn9->setObjectName(QString::fromUtf8("Btn9"));
        sizePolicy.setHeightForWidth(Btn9->sizePolicy().hasHeightForWidth());
        Btn9->setSizePolicy(sizePolicy);
        Btn9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#C0C0C0;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Btn9, 1, 2, 1, 1);

        Add = new QPushButton(centralWidget);
        Add->setObjectName(QString::fromUtf8("Add"));
        sizePolicy.setHeightForWidth(Add->sizePolicy().hasHeightForWidth());
        Add->setSizePolicy(sizePolicy);
        Add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#FF8C00;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Add, 1, 3, 1, 1);

        Subtract = new QPushButton(centralWidget);
        Subtract->setObjectName(QString::fromUtf8("Subtract"));
        sizePolicy.setHeightForWidth(Subtract->sizePolicy().hasHeightForWidth());
        Subtract->setSizePolicy(sizePolicy);
        Subtract->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#FF8C00;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Subtract, 2, 3, 1, 1);

        Multiply = new QPushButton(centralWidget);
        Multiply->setObjectName(QString::fromUtf8("Multiply"));
        sizePolicy.setHeightForWidth(Multiply->sizePolicy().hasHeightForWidth());
        Multiply->setSizePolicy(sizePolicy);
        Multiply->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#FF8C00;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Multiply, 3, 3, 1, 1);

        Divide = new QPushButton(centralWidget);
        Divide->setObjectName(QString::fromUtf8("Divide"));
        sizePolicy.setHeightForWidth(Divide->sizePolicy().hasHeightForWidth());
        Divide->setSizePolicy(sizePolicy);
        Divide->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:#FF8C00;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
"QPushButton::pressed {\n"
"background-color:#A9A9A9;\n"
"border:1px solid greay;\n"
"padding:5px;\n"
"}\n"
""));

        gridLayout->addWidget(Divide, 4, 3, 1, 1);

        Display = new QLineEdit(centralWidget);
        Display->setObjectName(QString::fromUtf8("Display"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Display->sizePolicy().hasHeightForWidth());
        Display->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(24);
        Display->setFont(font);
        Display->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"background-color:gray;\n"
"border:1px solid gray;\n"
"color: #ffffff;\n"
"}"));
        Display->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(Display, 0, 0, 1, 4);

        Calculator->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Calculator);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 352, 23));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        Calculator->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Calculator);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Calculator->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Calculator);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Calculator->setStatusBar(statusBar);

        menuBar->addAction(menuHelp->menuAction());
        menuHelp->addAction(actionHow_to_use_this_Calculator);

        retranslateUi(Calculator);

        QMetaObject::connectSlotsByName(Calculator);
    } // setupUi

    void retranslateUi(QMainWindow *Calculator)
    {
        Calculator->setWindowTitle(QApplication::translate("Calculator", "Calculator", nullptr));
        actionHow_to_use_this_Calculator->setText(QApplication::translate("Calculator", "How to use this Calculator", nullptr));
        Clear->setText(QApplication::translate("Calculator", "AC", nullptr));
        Btn6->setText(QApplication::translate("Calculator", "6", nullptr));
        Btn5->setText(QApplication::translate("Calculator", "5", nullptr));
        Btn1->setText(QApplication::translate("Calculator", "1", nullptr));
        Btn7->setText(QApplication::translate("Calculator", "7", nullptr));
        Btn4->setText(QApplication::translate("Calculator", "4", nullptr));
        Btn8->setText(QApplication::translate("Calculator", "8", nullptr));
        Btn3->setText(QApplication::translate("Calculator", "3", nullptr));
        Btn0->setText(QApplication::translate("Calculator", "0", nullptr));
        Equal->setText(QApplication::translate("Calculator", "=", nullptr));
        Btn2->setText(QApplication::translate("Calculator", "2", nullptr));
        Btn9->setText(QApplication::translate("Calculator", "9", nullptr));
        Add->setText(QApplication::translate("Calculator", "+", nullptr));
        Subtract->setText(QApplication::translate("Calculator", "-", nullptr));
        Multiply->setText(QApplication::translate("Calculator", "*", nullptr));
        Divide->setText(QApplication::translate("Calculator", "/", nullptr));
        Display->setText(QApplication::translate("Calculator", "0.0", nullptr));
        menuHelp->setTitle(QApplication::translate("Calculator", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Calculator: public Ui_Calculator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALCULATOR_H
