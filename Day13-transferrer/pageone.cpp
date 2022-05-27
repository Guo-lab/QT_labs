#include "pageone.h"
#include "ui_pageone.h"

#include <QListWidget>
#include <QDebug>
#include <QMessageBox>



PageOne::PageOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PageOne)
{
    ui->setupUi(this);

    setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);hide();


    QListWidget *listWidget = new QListWidget(this);
    listWidget->setGeometry(10,10,this->width()-20,430);

    listWidget->setIconSize(QSize(80, 80));
    //listWidget->setFixedHeight(100);
    QFont oo;
    oo.setPointSize(14);
    listWidget->setFont(oo);

    listWidget->setSpacing(10);

    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/new/icon/kylin.png"));
    item->setText("local host : XXX.XXX.X.X");

    QListWidgetItem *item2 = new QListWidgetItem;
    item2->setIcon(QIcon(":/new/icon/11.png"));
    item2->setText("Windows 10 : XXX.XXX.X.X");

    QListWidgetItem *item3 = new QListWidgetItem;
    item3->setIcon(QIcon(":/new/icon/22.png"));
    item3->setText("Ubuntu 22 : XXX.XXX.X.X");

    QListWidgetItem *item4 = new QListWidgetItem;
    item4->setIcon(QIcon(":/new/icon/2080284.png"));
    item4->setText("Android : XXX.XXX.X.X");


    listWidget->addItem(item);
        listWidget->addItem(item2);
            listWidget->addItem(item3);
                listWidget->addItem(item4);

    //QStringList list;
    //list <<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H"<<"I";
    //listWidget->addItems(list);
    //listWidget->sortItems(Qt::DescendingOrder);

    connect(listWidget,&QListWidget::itemClicked,this,[=](QListWidgetItem *item){
        qDebug()<<item->data(0).toString();
        QMessageBox::information(this,"Use IP: ",item->text());
    });
}

PageOne::~PageOne()
{
    delete ui;
}



void PageOne::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    //获取客户区
    QRect rc = this->rect();

    //QString strInfo = "页面一";
    //设置文本颜色
    painter.setPen(qRgb(255,155,0));
    //设置字体
    //painter.setFont(QFont("隶书",36,QFont::Bold));
    //painter.drawText(0,-0,this->width(),this->height(),Qt::AlignCenter,strInfo);
    //https://blog.csdn.net/chenyijun/article/details/52161129?spm=1035.2023.3001.6557&utm_medium=distribute.pc_relevant_bbs_down_v2.none-task-blog-2~default~OPENSEARCH~Rate-2-52161129-bbs-300135016.pc_relevant_bbs_down_cate&depth_1-utm_source=distribute.pc_relevant_bbs_down_v2.none-task-blog-2~default~OPENSEARCH~Rate-2-52161129-bbs-300135016.pc_relevant_bbs_down_cate
    painter.drawRect(0, 0, width() -1, height() -1); //绘制边框


}
