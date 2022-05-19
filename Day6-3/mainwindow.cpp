#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this); //:/new/prefix1/code.png
}

MainWindow::~MainWindow()
{
    delete ui;
}
