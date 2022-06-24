#ifndef WIDGET_H
#define WIDGET_H

#include "databaseoperator.h"
#include "datadisplay.h"

#include <QWidget>
//#include "calendarwidget.h"
#include <QTime>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QDebug>
#include <QTimer>
#include <QPushButton>
#include "date.h"
#include <QCheckBox>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


typedef enum {
    Monday = 0,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday,
    Week
} E_WEEK;

class DayLabel : public QLabel {
    Q_OBJECT

private:
    QLabel *labelIcon;

public:
    DayLabel(QWidget *parent = nullptr);

protected:
    void mousePressEvent(QMouseEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);


signals:
    void signalClicked(int day);
    void signalEnter(int m);
    void signalLeave(int l);
};

class Widget : public QWidget
{
    Q_OBJECT

private:
    int m_nYear;
    int m_nMonth;
    int m_nDay;
//    QTime ct;
    QTimer *timer;
    QVBoxLayout *verlayout;
    QWidget *widgetTime;
    QLabel *labelTime;
    QWidget *widgetSecond;
    QWidget *overcontrol;
    QLabel *showCanlendarYearMonth;
    QPushButton *lastMonth;
    QPushButton *nextMonth;
    QPushButton *nian;
    QPushButton *yue;
    QPushButton *today;
    QWidget *weekTitle;
    QLabel *labelWeek[Week];
    QWidget *caBody;
    QGridLayout *gridLayout;
    DayLabel *labelDay[42];
    QWidget *doAndNotdo;
    QLabel *lunarDate;
    QLabel *yiji;
    QCheckBox *onlyOne;

    QWidget *addYiji;
    QWidget *nianList;
    QGridLayout *gridLayoutNian;
    QLabel *labelNian[12];
    QWidget *yueList;
    QGridLayout *gridLayoutYue;
    QLabel *labelYue[12];
    QLabel *whatToDo;
    //QWidget *toDoList;

    DatabaseOperator dbOp;
    QList<DateValue> dateValues;

    Ui::Widget *ui;


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    void paintEvent(QPaintEvent *);
    void wheelEvent(QWheelEvent *event);

signals:
    void signalWheel(int m);

private slots:
    void showTime();
    void showLastMonth();
    void showNextMonth();
    void nianPanel();
    void yuePanel();
    void toToday();
    void initDate();
    void onyiji(int);
    void sltDayClicked(int day);
    void sltDayEnter(int m);
    void sltDayLeave(int l);
    void sltDayWheel(int m);
    void updateData();
};


#endif // WIDGET_H
