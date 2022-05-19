#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mylistview.h"
#include <QListView>
#include "myviewmodel.h"
#include <QStringList>
#include "myitemdelegate.h"
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyListView *listView = new MyListView;
    MyItemDelegate *delegate = new MyItemDelegate();
    listView->setGeometry(10,20,this->width()-20,this->height()-100);
    listView->setParent(this);
    QStringList *list = new QStringList;;
    *list << "A" <<"B" <<"C" <<"D"<<"E"<<"F"<<"G";
    MyViewModel *model = new MyViewModel(*list);
    listView->setModel(model);
    listView->setItemDelegate(delegate);

    connect(listView,SIGNAL(clicked(QModelIndex)),this,
                          SLOT(indexClickedSlot(QModelIndex)));
}
// 自定义槽函数
void MainWindow::indexClickedSlot(const QModelIndex &index)
{
    QMessageBox::information(this,"",index.data().toString());

}

MainWindow::~MainWindow()
{
    delete ui;
}
