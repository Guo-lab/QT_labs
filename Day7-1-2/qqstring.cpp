#include "qqstring.h"
#include <QDebug>

QQString::QQString(const QString &s) {
    self = s;
    qDebug() << "New QQString " << self;
}

QString QQString::append2(const QString &s){
    QString res = self.append(s);
    qDebug() << "QQString Appending: " << res;
    return  res;
}

QString QQString::insert2(int n, const QString &s){
    QString res = self.insert(n, s);
    qDebug() << "QQString Inserting: " << res;
    return  res;
}

QString QQString::replace2(int a, int b, const QString &s){
    QString res = self.replace(a, b, s);
    qDebug() << "QQString Replacing: " << res;
    return  res;
}
bool QQString::startsWith2(const QString &s){
    qDebug() << "QQString Starts With" << s << "?: " << self.startsWith(s);
    return  self.startsWith(s);
}

QQString::~QQString(){
    qDebug() << "Delete QQString, bye";
}
