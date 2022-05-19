#ifndef MYYVIEWMODEL_H
#define MYYVIEWMODEL_H

#include <QObject>
#include <QWidget>
#include <QAbstractItemModel>
#include <QAbstractListModel>

class MyViewModel : public QAbstractListModel
{
public:
    MyViewModel(QStringList &list,QObject *parent=0);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
//    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
private:
    QStringList list;
};

#endif // MYYVIEWMODEL_H
