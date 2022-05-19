#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>

namespace Ui {
class Calculator;
}

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    ~Calculator();


// slots 2022-5-18
public slots:
    void NumPressed();
    void OpPressed();
    void Cal();
    void Clear();





private slots:
    void on_actionHow_to_use_this_Calculator_triggered();

private:
    Ui::Calculator *ui;
};

#endif // CALCULATOR_H
