#include "widget.h"
#include "ui_widget.h"
#include <QListView>
#include <QStringListModel>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QListView *listView = new QListView(this);
    listView->setLineWidth(100);
    listView->setGeometry(10,10,this->width()-20,80);

    QStringListModel *model = new QStringListModel;
    QStringList list ;
    list.append("A");
    list.append("B");
    list.append("C");
    list.append("D");
    list.append("E");
    list.append("F");
    list.append("G");
    model->setStringList(list);
    listView->setModel(model);
    connect(listView,SIGNAL(clicked(QModelIndex)),this,SLOT(indexClickedSlot(QModelIndex)));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::indexClickedSlot(const QModelIndex &index)
{
    QMessageBox::information(this,"",index.data().toString());

}

