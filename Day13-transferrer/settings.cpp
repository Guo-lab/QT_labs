#include "settings.h"
#include "ui_settings.h"

#include <QColorDialog>
#include <QDebug>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    QColor a;
    a.setRgb(0,255,255,255);
    setPalette(a);

    ui->textEdit->setPlaceholderText("/home/sq");
}

Settings::~Settings()
{
    delete ui;
}








void Settings::on_pushButton_clicked()
{
    QString textstring =  this->ui->textEdit->toPlainText();
    this->ui->textEdit->setText(textstring);
    qDebug() << "Now the directory for saving files changes into: "+textstring;
    this->ui->textEdit->setPlaceholderText(textstring);
}

void Settings::on_pushButton_2_clicked()
{
    QColor Color = QColorDialog::getColor(QPalette::Background,this);
    setPalette(Color);
}
