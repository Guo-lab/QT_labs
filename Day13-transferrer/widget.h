#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

#include <QColor>
#include <pageone.h>
#include <pagetwo.h>
#include <pagethree.h>

#include "settings.h"

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


public:
    PageOne *ptr_one;
    PageTwo *ptr_two;
    PageThree *ptr_three;

    QColor *Color;
    QString savedDirPath = "";

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_8_clicked();
    
    void on_pushButton_7_clicked();
    
    void on_pushButton_9_clicked();
    
private:
    Ui::Widget *ui;
    Settings *dialog;
};

#endif // WIDGET_H
