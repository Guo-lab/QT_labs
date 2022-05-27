#include "pagethree.h"
#include "ui_pagethree.h"

PageThree::PageThree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageThree)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    hide();
}

PageThree::~PageThree()
{
    delete ui;
}



void PageThree::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //获取客户区
    QRect rc = this->rect();

    //QString strInfo = "页面3";

    //设置文本颜色
    painter.setPen(qRgb(0,255,0));
    //设置字体
    //painter.setFont(QFont("隶书",36,QFont::Bold));
    //painter.drawText(0,-0,this->width(),this->height(),Qt::AlignCenter,strInfo);
    //绘制边框
    painter.drawRect(0, 0, width() -1, height() -1);


}

