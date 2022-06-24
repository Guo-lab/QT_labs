#ifndef DATE_H
#define DATE_H

#include <QObject>

class Date : public QObject
{
    Q_OBJECT

public:
    Date(QObject *parent = nullptr);

public:
    static int getFirstDayOfWeek(int year, int month);
    static int getTotalMonthDays(int year, int month);
    static bool isLoopYaer(int year);
    static int getMonthDays(int year, int month);
};


#endif // DATE_H
