#include "widget.h"
#include "ui_widget.h"
#include <QProgressBar>
#include <QTime>
#include <QTimer>
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    QProgressBar *progressBar = new QProgressBar(this);
    progressBar->move(this->width()/2-progressBar->width()/2,50);
    progressBar->setRange(0,100);
    progressBar->setValue(0);
    progressBar->setOrientation(Qt::Horizontal);

    QTimer *timer = new QTimer(this);
    timer->setInterval(1000);
    timer->start();

    qsrand(static_cast<uint>( QTime(0, 0, 0).secsTo(QTime::currentTime()) ));

    timer->connect(timer,&QTimer::timeout,this,[=](){
        if(progressBar->value() < 100){
            progressBar->setValue(progressBar->value()+qrand()%6+1);
        }else {
            timer->stop();
        }
    });

    connect(progressBar,&QProgressBar::valueChanged,this,[](int v){
       qDebug()<<"progress:"<<v<<"%";
    });
}

Widget::~Widget()
{
    delete ui;
}
