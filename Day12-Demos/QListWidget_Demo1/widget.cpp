#include "widget.h"
#include "ui_widget.h"
#include <QListWidget>
#include <QDebug>
#include <QMessageBox>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("QListWidget");
    QListWidget *listWidget = new QListWidget(this);
    listWidget->setGeometry(10,10,this->width()-20,150);

    QListWidgetItem *item = new QListWidgetItem;
    item->setIcon(QIcon(":/4.5-1.png"));
    item->setText("银河麒麟");
    item->setToolTip("what's up?");
    listWidget->addItem(item);
    QStringList list;
    list <<"A"<<"B"<<"C"<<"D"<<"E"<<"F"<<"G"<<"H"<<"I";
    listWidget->addItems(list);

    listWidget->sortItems(Qt::DescendingOrder);

    connect(listWidget,&QListWidget::itemClicked,this,[=](QListWidgetItem *item){
        qDebug()<<item->data(0).toString();
        QMessageBox::information(this,"Select",item->text());
    });
}

Widget::~Widget()
{
    delete ui;
}
