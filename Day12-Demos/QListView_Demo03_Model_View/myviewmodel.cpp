#include "myviewmodel.h"

//MyViewModel::MyViewModel()
//{
//    list<<"a"<<"b"<<"c"<<"d";
//}

MyViewModel::MyViewModel(QStringList &list,QObject *parent)
{
    this->list = list;
}

int MyViewModel::rowCount(const QModelIndex &parent) const
{
    return list.count();
}

QVariant MyViewModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }
    if(index.row() >= list.size()){
        return QVariant();
    }
    if(role == Qt::DisplayRole){
        return list.at(index.row());
    }else {
        return QVariant();
    }
}
