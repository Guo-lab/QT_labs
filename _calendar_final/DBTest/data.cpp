#include "data.h"

//#include <fstream>
//#include <jsoncpp/json/json.h>
#include <QDebug>
#include <QFile>
#include <QMap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

// 每月最大天数
QList<int> daysPerMonth = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// 宜忌信息
QList<QString> yiji = {
    "祭祀", "祈福", "嫁娶", "订盟", "纳采", "修造", "动土", "移徙", "入宅", "安葬",
    "开市", "破屋", "坏垣", "伐木", "开光", "理发", "造庙", "造桥", "栽种", "作灶",
    "沐浴", "扫舍", "纳畜", "上梁", "出行", "赴任", "掘井", "筑堤", "词讼", "交易"
};

int getPrevDate(int date)
{
    int newWeek = getWeek(date) - 1;
    if(newWeek <= 0)
        newWeek += 7;

    if(getDate(date) == 1){
        if(getMonth(date) == 1){
            return ((getYear(date) - 1) << YEAR_POS)
                    + (newWeek << WEEK_POS)
                    + (12 << MONTH_POS) + (31 << DATE_POS);
        }

        return (getYear(date) << YEAR_POS)
                + (newWeek << WEEK_POS)
                + ((getMonth(date) - 1) << MONTH_POS)
                + ((getMaxDay(date)) << DATE_POS);
    }

    return (getYear(date) << YEAR_POS)
            + (newWeek << WEEK_POS)
            + (getMonth(date) << MONTH_POS)
            + ((getDate(date) - 1) << DATE_POS);
}

int getNextDate(int date)
{
    int newWeek = getWeek(date) + 1;
    if(newWeek > 7)
        newWeek %= 7;

    if(getDate(date) == getMaxDay(date)){
        if(getMonth(date) == 12){
            return ((getYear(date) + 1) << YEAR_POS)
                    + (newWeek << WEEK_POS)
                    + (1 << MONTH_POS) + (1 << DATE_POS);
        }

        return (getYear(date) << YEAR_POS)
                + (newWeek << WEEK_POS)
                + ((getMonth(date) + 1) << MONTH_POS)
                + (1 << DATE_POS);
    }

    return (getYear(date) << YEAR_POS)
            + (newWeek << WEEK_POS)
            + (getMonth(date) << MONTH_POS)
            + ((getDate(date) + 1) << DATE_POS);
}

QString getYiByDate(int date)
{
    int sz = yiji.size();

    if(date < 0)
        date = -date;

    return yiji.at((date + 1) % sz) + "、"
            + yiji.at(((date >> WEEK_POS) + 7) % sz) + "、"
            + yiji.at(((date >> 1) + 13 + 11 * (date & 1)) % sz);
}

QString getJiByDate(int date)
{
    int sz = yiji.size();

    if(date < 0)
        date = -date;

    return yiji.at((date + 2) % sz) + "、"
            + yiji.at(((date >> WEEK_POS) + 9) % sz) + "、"
            + yiji.at(((date >> 1) + 17 + 11 * (date & 1)) % sz);
}

int getMaxDay(int date)
{
    if(getMonth(date) == 2){
        int year = getYear(date);
        if(!(year % 4) || (!(year % 100) && (year % 400))){
            return daysPerMonth.at(getMonth(date));
        }
        return daysPerMonth.at(getMonth(date)) + 1;
    }
    return daysPerMonth.at(getMonth(date));
}

//bool readJsonFiles(QList<DateValue> &dateValues)
//{
//    std::ifstream ifs;
//    QString dir = "/mnt/hgfs/VMShare/caljsons/";
//    const int MIN_YEAR = 1900;
//    const int MAX_YEAR = 2100;
//    Json::Reader reader;
//    Json::Value root;

//    for(int i = MIN_YEAR; i < MAX_YEAR; i++){
//        QString fileName = dir + "year" + QString::number(i) + ".json";

//        ifs.open(fileName.toLatin1().data());

//        if(!ifs.is_open()){
//            qDebug() << QString("Error: failed to open file \"%1\".").arg(fileName);
//            return FAILURE;
//        }

//        ifs.close();
//    }

//    return SUCCESS;
//}

bool readJsonFiles(QList<DateValue> &dateValues)
{
    const int MIN_YEAR = 1901;
    const int MAX_YEAR = 2100;
    const QString dir = "/mnt/hgfs/VMShare/caljsons/";

    for(int i = MIN_YEAR; i < MAX_YEAR; i++){
        QString fileName = dir + "year" + QString::number(i) + ".json";
        QFile file(fileName);
//        qDebug() << fileName;

        if(!file.open(QIODevice::ReadOnly)){
            qDebug() << "Error: failed to open json file.";
            return FAILURE;
        }

        QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll());
        QJsonArray jsonArray = jsonDoc.array();

        for(auto it = jsonArray.begin(); it != jsonArray.end(); it++){
            auto jsonMap = it->toVariant().toMap();
            int date = jsonMap["day"].toInt();
            int month = jsonMap["month"].toInt();
            int year = jsonMap["year"].toInt();
            QString yi = jsonMap["yi"].toString();
            QString ji = jsonMap["ji"].toString();

            DateValue dateValue;

            dateValue.date = (date << DATE_POS) | (month << MONTH_POS) | (year << YEAR_POS);
            dateValue.lunarDate = 0;
            dateValue.suitable = yi;
            dateValue.unsuitable = ji;

            dateValues << dateValue;
        }
    }

    return SUCCESS;
}
