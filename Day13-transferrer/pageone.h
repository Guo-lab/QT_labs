#ifndef PAGEONE_H
#define PAGEONE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class PageOne;
}

class PageOne : public QWidget
{
    Q_OBJECT

public:
    explicit PageOne(QWidget *parent = nullptr);
    ~PageOne();

private:
    void paintEvent(QPaintEvent *e);

private:
    Ui::PageOne *ui;
};

#endif // PAGEONE_H
