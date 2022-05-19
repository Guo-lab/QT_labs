#include "mydialog.h"
#include "ui_mydialog.h"

#include <QPainter>

#include <QInputDialog>
#include <QDebug>
#include <QColorDialog>
#include <QFontDialog>
#include <QFileDialog>
#include <QMessageBox>


MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
    // cancel default
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
}




void MyDialog::paintEvent(QPaintEvent *event) {
    QPainterPath path;
    path.setFillRule(Qt::WindingFill);
    QRect rect = QRect(0, 0, this->width(), this->height());
    path.addRoundRect(rect, 10, 10);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillPath(path, QBrush(Qt::white));
    painter.setPen(Qt::gray);
    painter.drawPath(path);
}

void MyDialog::on_pushButton_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Login successfully!");
    msgBox.exec();

    ////this->deleteLater();
}

void MyDialog::on_pushButton_2_clicked()
{
    QMessageBox msgBox;
    msgBox.setText("Register successfully!");
    msgBox.exec();

    ////this->deleteLater();
}



void MyDialog::on_pushButton_3_clicked()
{
    ////this->deleteLater();
    /// 14:01:58: Starting /home/sq/桌面/build-Day9-Dialog-Desktop_Qt_5_12_0_GCC_64bit-Debug/Day9-Dialog...
    /// munmap_chunk(): invalid pointer
    /// 14:02:00: 程序异常结束。
    /// 14:02:00: The process was ended forcefully.
    /// 14:02:01: /home/sq/桌面/build-Day9-Dialog-Desktop_Qt_5_12_0_GCC_64bit-Debug/Day9-Dialog crashed.
    this->close();
}







MyDialog::~MyDialog()
{
    delete ui;
}
