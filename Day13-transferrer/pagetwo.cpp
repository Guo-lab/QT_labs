#include "pagetwo.h"
#include "ui_pagetwo.h"

PageTwo::PageTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageTwo)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();
}

PageTwo::~PageTwo()
{
    delete ui;
}


void PageTwo::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);


    //设置画笔,画笔决定了线和文字等颜色
    painter.setPen(qRgb(255,0,0));

    //获取客户区
    QRect rc = this->rect();

    QString strInfo = "  Page Two  \n  Recent files  \n";

    strInfo += "\nNothing";

    //设置文本颜色
    painter.setPen(qRgb(0,0,255));

    //painter.

    //设置字体
    painter.setFont(QFont("New Roman",36,QFont::Bold));
    painter.drawText(0,0,this->width(),this->height(),Qt::AlignCenter,strInfo);

    painter.drawRect(0, 0, width() -1, height() -1); //绘制边框
}
