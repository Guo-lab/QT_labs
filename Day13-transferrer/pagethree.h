#ifndef PAGETHREE_H
#define PAGETHREE_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>

namespace Ui {
class PageThree;
}

class PageThree : public QWidget
{
    Q_OBJECT

public:
    explicit PageThree(QWidget *parent = nullptr);
    ~PageThree();

private:
    void paintEvent(QPaintEvent *e);

private:
    Ui::PageThree *ui;
};

#endif // PAGETHREE_H
