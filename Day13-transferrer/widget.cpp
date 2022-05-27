#include "widget.h"
#include "ui_widget.h"

#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/new/icon/8414647.png"));

    ui->pushButton->setIcon(QIcon(":/new/icon/people.png"));
    ui->pushButton_2->setIcon(QIcon(":/new/icon/about.png"));
    ui->pushButton_3->setIcon(QIcon(":/new/icon/sent.png"));


    ui->pushButton_7->setIcon(QIcon(":/new/icon/2.png"));
    ui->pushButton_8->setIcon(QIcon(":/new/icon/1.png"));
    ui->pushButton_9->setIcon(QIcon(":/new/icon/3.png"));


    ptr_one = new PageOne(this);
    ptr_two = new PageTwo(this);
    ptr_three = new PageThree(this);

    ptr_one->move(ui->loc->pos());
    ptr_one->show();

}

Widget::~Widget()
{
    delete ui;
}

// Friends
void Widget::on_pushButton_clicked()
{
    ptr_two->close();
    ptr_three->close();

    ptr_one->move(ui->loc->pos());
    ptr_one->show();
}

// Sent
void Widget::on_pushButton_3_clicked()
{
    ptr_one->close();
    ptr_three->close();

    ptr_two->move(ui->loc->pos());
    ptr_two->show();
}

// About
void Widget::on_pushButton_2_clicked()
{
    ptr_one->close();
    ptr_two->close();

    ptr_three->move(ui->loc->pos());
    ptr_three->show();
}








// Received
void Widget::on_pushButton_8_clicked()
{
    //qDebug("OK");
    QStringList file_names = QFileDialog::getOpenFileNames(this, tr("Folder with Received Files"), "/home/sq");
    //qDebug() << file_names;
}

// IP
void Widget::on_pushButton_7_clicked()
{
    //qDebug("OK");
    QMessageBox IPBox;
    IPBox.setWindowTitle("LOCAL IP");
    IPBox.setText("Local IP Address:        \n  XXX.XXX.X.X\n");
    IPBox.setIconPixmap(QPixmap(":/new/icon/2.png").scaled(QSize(64, 64) ) );
    QPushButton *agreeBut = IPBox.addButton("Got it.", QMessageBox::AcceptRole);
    IPBox.exec();
}


// Settings
void Widget::on_pushButton_9_clicked()
{
    //qDebug("OK");
    dialog = new Settings(this);
    dialog->setModal(false);
    dialog->show();

}
