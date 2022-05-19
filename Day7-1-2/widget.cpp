#include "widget.h"
#include "ui_widget.h"

#include <QDebug>

#include "q_negative_abs.h"
#include "qqstring.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);



    // qAbs-like encapsulation
    ////qDebug()<<qAbs(-4);
    qDebug()<<qnAbs(4);



    // QString-like encapsulation
    QString s = "Hello";
    ////qDebug() << s;
    QQString ss(s);
    ss.append2(" World");
    ss.insert2(5, ", New");
    ss.replace2(0, 5, "Hi");
    ss.startsWith2("H");



}

Widget::~Widget()
{
    delete ui;
}
