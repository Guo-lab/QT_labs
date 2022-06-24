#ifndef DATABASEOPERATOR_H
#define DATABASEOPERATOR_H

#include "data.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>

// 数据库操作类
class DatabaseOperator
{
public:
    // 构造函数，初始化数据库
    DatabaseOperator();
    // 析构函数，关闭数据库
    ~DatabaseOperator();

    // 创建所有数据表
    bool m_createTables();

    // 向数据表dates中插入数据
    bool m_insert(QList<DateValue> &dateValues);
    // 向数据表schedules中插入数据
    bool m_insert(QList<ScheduleValue> &scheduleValues);
    // 载入数据
    bool m_loadData();

    // 查询指定数据表中的所有数据
    bool m_query(int table);
    // 查询指定数据表中符合特定条件的数据
    bool m_query(int table, int date, int month, int year);
    // 自定义查询语句，进行查询操作
    bool m_query(const QString &queryStr);

    // 更新某一项的字符串类型字段
    bool m_update(int table, int date, int month, int year, const QString &field, const QString &newStr = QString(), int time = 0);

    // 删除某事项
    bool m_delete(int no);

    // 查询整月页面的日期
    bool m_selectDatesByMonth(int date);

    // 查询对象
    QSqlQuery query;


private:
    QSqlDatabase database;

};

#endif // DATABASEOPERATOR_H
