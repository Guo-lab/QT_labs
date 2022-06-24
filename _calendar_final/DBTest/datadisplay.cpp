#include "datadisplay.h"

QList<QString> lunarYearNames = {
    "", "甲子", "乙丑", "丙寅", "丁卯", "戊辰", "己巳", "庚午", "辛未", "壬申", "癸酉",
    "甲戌", "乙亥", "丙子", "丁丑", "戊寅", "己卯", "庚辰", "辛巳", "壬午", "癸未",
    "甲申", "乙酉", "丙戌", "丁亥", "戊子", "己丑", "庚寅", "辛卯", "壬辰", "癸巳",
    "甲午", "乙未", "丙申", "丁酉", "戊戌", "己亥", "庚子", "辛丑", "壬寅", "癸卯",
    "甲辰", "乙巳", "丙午", "丁未", "戊申", "己酉", "庚戌", "辛亥", "壬子", "癸丑",
    "甲寅", "乙卯", "丙辰", "丁巳", "戊午", "己未", "庚申", "辛酉", "壬戌", "癸亥"
};

QList<QString> lunarMonthNames = {
    "", "正月", "二月", "三月", "四月", "五月", "六月", "七月", "八月", "九月", "十月", "十一月", "腊月"
};

QList<QString> lunarDateNames = {
    "", "初一", "初二", "初三", "初四", "初五", "初六", "初七", "初八", "初九", "初十",
    "十一", "十二", "十三", "十四", "十五", "十六", "十七", "十八", "十九", "二十",
    "廿一", "廿二", "廿三", "廿四", "廿五", "廿六", "廿七", "廿八", "廿九", "三十"
};

QList<QString> lunarAnimals = {
    "猪", "鼠", "牛", "虎", "兔", "龙", "蛇", "马", "羊", "猴", "鸡", "狗"
};

QString getLunarYearName(QSqlRecord record)
{
    int lunarDate = record.value("lunarDate").toInt();

    return "农历" + lunarYearNames.at(getYear(lunarDate))
            + lunarAnimals.at(getYear(lunarDate) % lunarAnimals.size()) + "年";
}

QString getInfo(QSqlRecord record)
{
    if(record.value("info").toString().size() == 0){
        int lunarDate = record.value("lunarDate").toInt();
        if(lunarDate == 0)
            return "农历";

        if(lunarDate == 1)
            return lunarMonthNames.at(getMonth(lunarDate));

        return lunarDateNames.at(getDate(lunarDate));
    }

    return record.value("info").toString();
}

QString getYiji(QSqlRecord record)
{
    QString yijiInfo = QString();

    yijiInfo.append("宜：" + record.value("suitable").toString() + "\n");
    yijiInfo.append("忌：" + record.value("unsuitable").toString());

    return yijiInfo;
}
