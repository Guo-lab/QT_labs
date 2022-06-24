#ifndef DATADISPLAY_H
#define DATADISPLAY_H

#include "data.h"

#include <QSqlQuery>
#include <QSqlRecord>

inline QString getMonthName(int date)
{
    return QString::number(getYear(date)) + "年" + QString::number(getMonth(date)) + "月";
}

QString getLunarYearName(QSqlRecord record);

QString getInfo(QSqlRecord record);

QString getYiji(QSqlRecord record);

#endif // DATADISPLAY_H
