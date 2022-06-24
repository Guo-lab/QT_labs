#ifndef DATA_H
#define DATA_H

#include <QString>
#include <QList>

#define SUCCESS true
#define FAILURE false

// 数据表dates中数据项的掩码
#define YEAR_MASK 0xfff
#define LEAP_MONTH_MASK 0xf
#define MONTH_MASK 0xf
#define WEEK_MASK 0xf
#define DATE_MASK 0xff

// 数据表dates中数据项的位置
#define YEAR_POS 20
#define LEAP_MONTH_POS 16
#define MONTH_POS 12
#define WEEK_POS 8
#define DATE_POS 0

// 数据表变量
enum {
    DATE_TABLE = 1,
    SCHEDULE_TABLE
};

// 数据表dates的数据项
typedef struct
{
    int date;
    int lunarDate;
    QString suitable;
    QString unsuitable;
    QString info;
} DateValue;
// 支持的日期范围为1900.1.1-2100.12.31
// date项格式：8位16进制数字，第1-3位：年份(0x76c-0x834)，第4位：置空，第5位：月份(0x0-0xc)，第6位：星期(0x1-0x7)，第7-8位：日期(0x00-0x1f)
// lunarDate项格式：8位16进制数字，第1-3位：天干地支(0x001-0x03c)，第4位：闰月标记(0x0-0x1)，第5位：月份(0x0-0xc)，第6位：置空，第7-8位：日期(0x00-0x1f)
// 日期为0时指代整个月份，月份和日期均为0时指代整个年份

// 数据表schedules的数据项
typedef struct
{
    int no;
    int date;
    int time;
    QString schedule;
} ScheduleValue;
// time项范围为0-1439，指代一天中的具体时间(0:00-23:59)，-1指代整天

// 得到日期信息
inline int getDate(int date)
{
    return (date >> DATE_POS) & DATE_MASK;
}

// 得到闰月标记信息
inline int getLeapMonth(int date)
{
    return (date >> LEAP_MONTH_POS) & LEAP_MONTH_MASK;
}

// 得到月份信息
inline int getMonth(int date)
{
    return (date >> MONTH_POS) & MONTH_MASK;
}

// 得到年份信息
inline int getYear(int date)
{
    return (date >> YEAR_POS) & YEAR_MASK;
}

// 得到星期信息
inline int getWeek(int date)
{
    return (date >> WEEK_POS) & WEEK_MASK;
}

// 得到某日的前一日
int getPrevDate(int date);
// 得到某日的后一日
int getNextDate(int date);

// 得到宜忌信息
QString getYiByDate(int date);
QString getJiByDate(int date);

// 得到该月最大天数
int getMaxDay(int date);

// 读取json文件
bool readJsonFiles(QList<DateValue> &dateValues);

// 生成随机数据

#endif // DATA_H
