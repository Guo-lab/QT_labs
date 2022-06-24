#include "databaseoperator.h"

DatabaseOperator::DatabaseOperator()
{
    if(QSqlDatabase::contains("qt_sql_default_connection")){
        database = QSqlDatabase::database("qt_sql_default_connection");
    }

    else{
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("calendarDb");
    }

    if(!database.open()){
        qDebug() << "Error: Failed to connect database." << database.lastError();
    }

    query = QSqlQuery(database);
}

DatabaseOperator::~DatabaseOperator()
{
    if(!database.isOpen()){
        qDebug() << "Error: Database has been already closed." << database.lastError();
    }
    else{
        database.close();
    }
}

bool DatabaseOperator::m_createTables()
{
    QString createDates = QString(
        "CREATE TABLE dates (\
             date INT PRIMARY KEY NOT NULL,\
             lunarDate INT NOT NULL,\
             suitable VARCHAR(60),\
             unsuitable VARCHAR(60),\
             info VARCHAR(60)\
         );"
        );
    QString createSchedules = QString(
        "CREATE TABLE schedules (\
             no INT PRIMARY KEY NOT NULL,\
             date INT,\
             time INT NOT NULL,\
             schedule VARCHAR(600) NOT NULL,\
             CONSTRAINT fk_date FOREIGN KEY(date) REFERENCES dates(date)\
         );"
        );

    if(!query.exec(createDates)){
        qDebug() << "Error: Failed to create table \"dates\"." << query.lastError();
        return FAILURE;
    }

    if(!query.exec(createSchedules)){
        qDebug() << "Error: Failed to create table \"schedules\"." << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}

bool DatabaseOperator::m_insert(QList<DateValue> &dateValues)
{
    QVariantList dateList = QVariantList();
    QVariantList lunarDateList = QVariantList();
    QVariantList suitableList = QVariantList();
    QVariantList unsuitableList = QVariantList();
    QVariantList infoList = QVariantList();

    query.prepare("INSERT INTO dates VALUES(?,?,?,?,?)");

    for(int i = 0; i < dateValues.size(); i++){
        dateList << dateValues.at(i).date;
        lunarDateList << dateValues.at(i).lunarDate;
        suitableList << dateValues.at(i).suitable;
        unsuitableList << dateValues.at(i).unsuitable;
        infoList << dateValues.at(i).info;
    }

    query.addBindValue(dateList);
    query.addBindValue(lunarDateList);
    query.addBindValue(suitableList);
    query.addBindValue(unsuitableList);
    query.addBindValue(infoList);

    if(!query.execBatch()){
        qDebug() << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}

bool DatabaseOperator::m_insert(QList<ScheduleValue> &scheduleValues)
{
    QVariantList noList = QVariantList();
    QVariantList dateList = QVariantList();
    QVariantList timeList = QVariantList();
    QVariantList scheduleList = QVariantList();

    query.prepare("INSERT INTO schedules VALUES(?,?,?,?)");

    for(int i = 0; i < scheduleValues.size(); i++){
        noList << scheduleValues.at(i).no;
        dateList << scheduleValues.at(i).date;
        timeList << scheduleValues.at(i).time;
        scheduleList << scheduleValues.at(i).schedule;
    }

    query.addBindValue(noList);
    query.addBindValue(dateList);
    query.addBindValue(timeList);
    query.addBindValue(scheduleList);

    if(!query.execBatch()){
        qDebug() << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}

bool DatabaseOperator::m_loadData()
{
    QList<DateValue> dateValues = QList<DateValue>();
    const uint MIN_DATE = 0x76d01201; // 1901.1.1
    const uint MAX_DATE = 0x8330c41f; // 2099.12.31

    for(int date = MIN_DATE; date <= MAX_DATE; date = getNextDate(date)){
        DateValue dateValue;

//        qDebug() << "m: " + QString::number(date, 16);

        dateValue.date = date;
        dateValue.lunarDate = 0;
        dateValue.suitable = getYiByDate(date);
        dateValue.unsuitable = getJiByDate(date);
        dateValue.info = "";

        dateValues << dateValue;
    }

    if(!m_insert(dateValues)){
        return FAILURE;
    }

    return SUCCESS;
}

bool DatabaseOperator::m_query(int table)
{
    QString queryStr;

    switch(table){
    case DATE_TABLE:
        queryStr = QString("SELECT * FROM dates;");
        break;

    case SCHEDULE_TABLE:
        queryStr = QString("SELECT * FROM schedules;");
        break;

    default:
        qDebug() << "Error: Table does not exist.";
        return FAILURE;
    }

    if(!query.exec(queryStr)){
        qDebug() << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}

bool DatabaseOperator::m_query(int table, int date, int month, int year)
{
    QString queryStr;

    switch(table){
    case DATE_TABLE:
        queryStr = QString("SELECT * FROM dates WHERE (date >> 20) & 0xfff = %1 AND (date >> 12) & 0xf = %2 AND date & 0xff = %3;").arg(
                    QString::number(year), QString::number(month), QString::number(date));
        break;

    case SCHEDULE_TABLE:
        queryStr = QString("SELECT * FROM schedules WHERE (date >> 20) & 0xfff = %1 AND (date >> 12) & 0xf = %2 AND date & 0xff = %3;").arg(
                    QString::number(year), QString::number(month), QString::number(date));
        break;

    default:
        qDebug() << "Error: Table does not exist.";
        return FAILURE;
    }

    if(!query.exec(queryStr)){
        qDebug() << query.lastError();
        return FAILURE;
    }
    //qDebug() << query.exec(queryStr);
    //qDebug() << query.value("info").toString();
    return SUCCESS;
}

bool DatabaseOperator::m_query(const QString &queryStr)
{
    if(!query.exec(queryStr)){
        qDebug() << QString("Error: Failed to execute SQL query \"%1\".").arg(queryStr) << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}



bool DatabaseOperator::m_update(int table, int date, int month, int year, const QString &field, const QString &newStr, int time)
{
    QString queryStr;

    switch(table){
    case DATE_TABLE:
        if(!(field == "info" || field == "suitable" || field == "unsuitable")){
            qDebug() << "Error: Field does not exist.";
            return FAILURE;
        }
        queryStr = QString("UPDATE dates SET \"%1\" = \"%2\"\
                       WHERE (date >> 20) & 0xfff = %3 AND (date >> 12) & 0xf = %4 AND date & 0xff = %5;").arg(
                field, newStr, QString::number(year), QString::number(month), QString::number(date));
        qDebug() << queryStr;
        break;

    case SCHEDULE_TABLE:
        if(!(field == "date" || field == "schedule")){
            qDebug() << "Error: Field does not exist.";
            return FAILURE;
        }
        if(field == "date"){
            queryStr = QString("UPDATE schedules SET date = %1\
                           WHERE (date >> 20) & 0xfff = %2 AND (date >> 12) & 0xf = %3 AND date & 0xff = %4;").arg(
                    QString::number(time), QString::number(year), QString::number(month), QString::number(date));
        }
        if(field == "schedule"){
            queryStr = QString("UPDATE schedules SET schedule = %1\
                           WHERE (date >> 20) & 0xfff = %2 AND (date >> 12) & 0xf = %3 AND date & 0xff = %4;").arg(
                    newStr, QString::number(year), QString::number(month), QString::number(date));
        }
        break;

    default:
        qDebug() << "Error: Table does not exist.";
        return FAILURE;
    }
    //qDebug() << query.exec(queryStr);
    if(!query.exec(queryStr)){
        qDebug() << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}





bool DatabaseOperator::m_delete(int no)
{
    if(!query.exec(QString("DELETE FROM schedules WHERE no = %1;").arg(QString::number(no)))){
        qDebug() << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}

bool DatabaseOperator::m_selectDatesByMonth(int date)
{
    const int TOTAL_DATES = 42;
    int firstDayWeek = 8 - ((date - getWeek(date)) % 7);
    if(firstDayWeek > 7){
        firstDayWeek %= 7;
    }

    int lastMonthDaysDisplay = firstDayWeek - 1;

    int mindate = date;
    for(int i = 0; i < lastMonthDaysDisplay; i++)
        mindate = getPrevDate(mindate);

    int maxdate = mindate;
    for(int i = 0; i < TOTAL_DATES; i++)
        maxdate = getNextDate(maxdate);

    QString queryStr = QString("SELECT * FROM dates WHERE date >= %1 AND date <= %2;").arg(
                QString::number(mindate), QString::number(maxdate));

    qDebug() << queryStr;


    if(!query.exec(queryStr)){
        qDebug() << query.lastError();
        return FAILURE;
    }

    return SUCCESS;
}
