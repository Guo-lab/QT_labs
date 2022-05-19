#include "calculator.h"
#include "ui_calculator.h"

#include <QDebug>
#include <QMessageBox>

// static var
static double calVal = 0.0;
static bool divTrigger = false;
static bool mulTrigger = false;
static bool addTrigger = false;
static bool subTrigger = false;


Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calVal));

    // Num Button
    QPushButton *numButtons[10];
    for(int i=0;i<10;i++){
        // Create Btn(i) in calculator.ui
        QString buttonName = "Btn" + QString::number((i));
        numButtons[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(numButtons[i], SIGNAL(released()),this,SLOT(NumPressed()) );
    }
    // Other Button
    connect(ui->Add,SIGNAL(released()),this,SLOT(OpPressed()));
    connect(ui->Subtract,SIGNAL(released()),this,SLOT(OpPressed()));
    connect(ui->Multiply,SIGNAL(released()),this,SLOT(OpPressed()));
    connect(ui->Divide,SIGNAL(released()),this,SLOT(OpPressed()));

    connect(ui->Equal,SIGNAL(released()),this,SLOT(Cal()));
    connect(ui->Clear,SIGNAL(released()),this,SLOT(Clear()));
}

Calculator::~Calculator()
{
    delete ui;
}




void Calculator::NumPressed() {
    //qDebug() << Calculator::findChild<QPushButton *>("Btn1");
    //QPushButton *button = (QPushButton *)sender();
    QPushButton *button = static_cast<QPushButton *>(sender());
    QString butval = button->text();
    QString displayVal = ui->Display->text();

    if((displayVal.toDouble() == 0)||(displayVal.toDouble() == 0.0)){
        ui->Display->setText(butval);
    } else {
        // Concat the numbers
        QString newVal = displayVal+butval;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal,'g',16));
    }
}

void Calculator::OpPressed() {
    divTrigger = false;
    mulTrigger = false;
    addTrigger = false;
    subTrigger = false;

    QString displayVal = ui->Display->text();
    calVal = displayVal.toDouble();

    // Get the value of the current button
    QPushButton *button = static_cast<QPushButton *>(sender());
    QString butVal = button->text();

    if(QString::compare(butVal,"/",Qt::CaseInsensitive) == 0) {
        divTrigger = true;
    } else if (QString::compare(butVal,"*",Qt::CaseInsensitive) == 0) {
        mulTrigger = true;
    } else if (QString::compare(butVal,"+",Qt::CaseInsensitive) == 0) {
        addTrigger = true;
    } else if (QString::compare(butVal,"-",Qt::CaseInsensitive) == 0) {
        subTrigger = true;
    }
    ui->Display->setText(butVal);
}


void Calculator::Cal() {
    double solution = 0.0;
    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();

    if(addTrigger || subTrigger || mulTrigger || divTrigger){
        if(addTrigger) {
            solution = calVal + dblDisplayVal;
        } else if (subTrigger) {
            solution = calVal - dblDisplayVal;
        } else if (mulTrigger) {
            solution = calVal * dblDisplayVal;
        } else if (divTrigger) {
            solution = calVal / dblDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution));
}

void Calculator::Clear() {
    ui->Display->setText("");
}

void Calculator::on_actionHow_to_use_this_Calculator_triggered()
{
    QString about = "";
    about += "How to use this Calculator:                \n";
    about += "\n  This calculator only deals with \n                                           one-step calculation!\n";
    about += "\n There are ten numbers: [0 1 2 3 4 5 6 7 8 9].\n";
    about += " There are four operators: [+ - * /].\n";
    about += " Press the button \"=\" to get the results.\n";
        about += " Press the button \"AC\" to clear the Inputs.\n";
    about += "\n\n====================================\n";
    about += "\n                                                 Author : Gsq\n";
    about += "                                                 Date   : 2022-5-18\n";
    about += "                            (C) Calculator Version 1.0   (R)";
    about += "\n===================================\n";
    QMessageBox::about(this, "About the Calculator", about);
}
