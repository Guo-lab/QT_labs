#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPushButton *btn = new QPushButton(this);
    btn->setGeometry(10,50, 271,41);
    btn->setText("Mum: Do to bed, babe!");

    connect(btn, &QPushButton::clicked, this, &MainWindow::MumSays);

    QPushButton *btn2 = new QPushButton(this);
    btn2->setGeometry(10,100, 271,41);
    btn2->setText("Children: I am going!");
    connect(btn2, &QPushButton::clicked, this, [=](){
        qDebug() << "Children fall sleep!";
        //btn, SIGNAL(clicked(bool)), this, SLOT(MumSays())
        disconnect(btn, &QPushButton::clicked, this, &MainWindow::MumSays);
    });


}

void MainWindow::MumSays() {
    // Mum says something
    QMessageBox MumMsgBox;
    MumMsgBox.setWindowTitle("Mum Says:");
    MumMsgBox.setText("Go to bed, it is time to sleep!");
    MumMsgBox.exec();
}



MainWindow::~MainWindow()
{
    delete ui;
}
