#ifndef MYITEMDELEGATE_H
#define MYITEMDELEGATE_H
#include <QAbstractItemDelegate>


class MyItemDelegate : public QAbstractItemDelegate
{
public:
    MyItemDelegate();
    void paint(QPainter *painter,
               const QStyleOptionViewItem &option, const QModelIndex &index) const Q_DECL_OVERRIDE;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index) const Q_DECL_OVERRIDE;
};

#endif // MYITEMDELEGATE_H
