#include "widget.h"
#include "ui_widget.h"

#include <QDate>
#include <QDebug>
#include <QStyleOption>
#include "qpainter.h"
#include <QTimer>

static const QString s_strWeek[] = {
    QObject::tr("周一"), QObject::tr("周二"),QObject::tr("周三"),
    QObject::tr("周四"), QObject::tr("周五"),
    QObject::tr("周六"), QObject::tr("周日"),
};

static int site = -1;
//static int xia = 0;
static int clickone = -1;
static int enterone = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //dbOp = DatabaseOperator();
    dbOp.m_query("DROP TABLE dates;");
    dbOp.m_query("DROP TABLE schedules;");
    dbOp.m_createTables();
//    dbOp.m_query("DELETE FROM dates;");
//    qDebug() << "delete";

    //dbOp.m_insert(dateValues);
    dbOp.m_loadData();
    qDebug()<< "Have Loaded the data.";

    m_nYear  = QDate::currentDate().year();
    qDebug() << m_nYear;
    m_nMonth = QDate::currentDate().month();
    qDebug() << m_nMonth;
    m_nDay = QDate::currentDate().day();
    qDebug() << m_nDay;

          dbOp.m_update(DATE_TABLE, 24, m_nMonth, m_nYear, "info", "夏至");
                    dbOp.m_update(DATE_TABLE, 24, m_nMonth, m_nYear, "suitable", "学习");
                              dbOp.m_update(DATE_TABLE, 24, m_nMonth, m_nYear, "unsuitable", "颓圮");
          qDebug() << "Update 夏至";
              //dbOp.m_loadData();

          //dbOp.m_query("SELECT * FROM sqlite_master;");
          //while(dbOp.query.next()){
          //    qDebug() << dbOp.query.value(1).toString();
          //}

    dbOp.m_query(DATE_TABLE, 23, m_nMonth, m_nYear);
    //dbOp.query.record().value("info").toString();
    //dbOp.query.next();

    dbOp.query.first();
    qDebug() << getInfo(dbOp.query.record());
    qDebug() << dbOp.query.record().value("suitable").toString();

    QString yijiInfo = getYiji(dbOp.query.record());
    //qDebug() << yijiInfo;
//    QTime ct = QTime::currentTime(); // 获取当前时间
//    qDebug()<<ct;
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(showTime()));
    timer->start(1000);

    this->setFixedSize(440, 610);
    this->setObjectName("Calendar");
    this->setWindowTitle("Calendar");
    this->setAttribute(Qt::WA_TranslucentBackground);//背景透明
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowStaysOnTopHint);//隐藏标题栏
    this->setStyleSheet("QWidget#Calendar{border-radius: 5px; background-color:rgba(88,88,88,88%);}\
                         QLabel#labelTime{color: white; font-size: 30px; background:transparent;}\
                         QLabel#nowdate, #nowweek, #nowlunar{color: white; font-size: 16px;}\
                         QLabel#showCanlendarYearMonth{color: white; font-size: 15px;}\
                         QWidget#widgetTime{background:transparent}\
                         QWidget#widgetSecond{background:transparent}\
                         QPushButton#lastMonth, #nextMonth, #nian, #yue, #today{background:transparent;color: white; font-size: 15px;border: 0px solid #dcdfe6;border-radius: 5px;}\
                         QPushButton#lastMonth:hover{background:transparent;}\
                         QPushButton#lastMonth:pressed{background:transparent;}\
                         QPushButton#nian:hover{background-color:rgba(169,169,169,90%);}\
                         QPushButton#nian:pressed{background-color:rgba(90,90,90,90%);}\
                         QPushButton#yue:hover{background-color:rgba(169,169,169,90%);}\
                         QPushButton#yue:pressed{background-color:rgba(90,90,90,90%);}\
                         QPushButton#today:hover{background-color:rgba(169,169,169,90%);}\
                         QPushButton#today:pressed{background-color:rgba(90,90,90,90%);}\
                         QWidget#overcontrol{background:transparent}\
                         QLabel#labelWeek{color: white;}\
                         QWidget#caBody{background:transparent}\
                         QWidget#doAndNotdo{background:transparent}\
                         QWidget#nianList{background:transparent;}\
                         QWidget#yueList{background:transparent;}\
                         QLabel#yiji, #lunarDate, #whatToDo{color: white;}\
                         QWidget#addYiji{background:transparent;}\
                         QWidget#weekTitle{background:transparent}  ");
//                         QLabel#labelTime{font: bold; color: white; font-size: 40px; background:black;}");
//                         QWidget#widgetTime{background:blue}\
//                         QWidget#widgetSecond{background:green}\
//                         QWidget#overcontrol{background:pink}\
//                         QWidget#caBody{background:red}\
//                         QWidget#doAndNotdo{background:orange}\
//                         QWidget#nianList{background:red;}\
//                         QLabel#labelNian{color: white;font-size: 17px;border: 1px solid #FFFFFF;font: bold;}\
//                         QWidget#yueList{background:red;}\
//                         QLabel#labelYue{color: white;font-size: 17px;border: 1px solid #FFFFFF;font: bold;}\
//                         QWidget#addYiji{background:purple;}\
//                         QWidget#weekTitle{background:yellow}  ");
//                         DayLabel#labelDay{color: white;border: 1px solid #FFFFFF;font: bold;font-size: 17px;}\
//                        DayLabel#TODAY{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;background:rgb(55,143,250);border-radius: 3px;}\
//                        DayLabel#labelDay{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}\
//                        QLabel#labelYue{color: white;font-size: 17px;border: 0px solid #FFFFFF;font: bold;}\
//                        QLabel#labelNian{color: white;font-size: 17px;border: 0px solid #FFFFFF;font: bold;}\

//    QPalette palette(this->palette());
//    palette.setColor(QPalette::Background, Qt::black);
//    this->setPalette(palette);
//    setAutoFillBackground(true);


    //垂直结构
    verlayout = new QVBoxLayout;
    verlayout->setContentsMargins(0, 5, 0, 5);
    verlayout->setSpacing(0);
    this->setLayout(verlayout);

    //显示时间部分
    widgetTime = new QWidget(this);
    widgetTime->setObjectName("widgetTime");
    widgetTime->setFixedSize(440,50);
    labelTime = new QLabel(widgetTime);
    labelTime->setObjectName("labelTime");
    labelTime->setAlignment(Qt::AlignCenter);
    labelTime->setGeometry(120,0,200,50);
    //labelTime->setFixedSize(200, 50);
//    labelTime->setStyleSheet("font: bold;"
//                             "color: white"
//                             "font-size: 40px;"
                             //"background:transparent;"
//                             );
    verlayout->addWidget(widgetTime);

    //显示日期、星期、农历
//    QString current_week = QDateTime::currentDateTime().toString("dddd");
//    qDebug() << "week: "<<current_week; //获取星期
    widgetSecond = new QWidget(this);
    widgetSecond->setObjectName("widgetSecond");
    widgetSecond->setFixedSize(440,50);

    //日期
    QLabel *nowdate = new QLabel(widgetSecond);
    nowdate->setObjectName("nowdate");
    nowdate->setAlignment(Qt::AlignCenter);
    nowdate->setGeometry(87,0,100,50);
    nowdate->setText(QDateTime::currentDateTime().toString("yyyy/MM/dd"));
    //星期
    QLabel *nowweek = new QLabel(widgetSecond);
    nowweek->setObjectName("nowweek");
    nowweek->setAlignment(Qt::AlignCenter);
    nowweek->setGeometry(187,0,66,50);
    nowweek->setText(QDateTime::currentDateTime().toString("dddd"));
    //农历,待补充
    QLabel *nowlunar = new QLabel(widgetSecond);
    nowlunar->setObjectName("nowlunar");
    nowlunar->setAlignment(Qt::AlignCenter);
    nowlunar->setGeometry(253,0,100,50);
    QString lunar = "五月廿一";
    nowlunar->setText(lunar);
    //分割线1
    QPushButton *line1 = new QPushButton(widgetSecond);
    line1->setFocusPolicy(Qt::NoFocus);
    line1->setGeometry(0,49,440,1);
    verlayout->addWidget(widgetSecond);

    //日历主体上一行控制栏
    overcontrol = new QWidget(this);
    overcontrol->setObjectName("overcontrol");
    overcontrol->setFixedSize(440,50);
    //显示年.月
    showCanlendarYearMonth = new QLabel(overcontrol);
    showCanlendarYearMonth->setObjectName("showCanlendarYearMonth");
    //showCanlendarYearMonth->setAlignment(Qt::AlignCenter);
    showCanlendarYearMonth->setText(QString::number(m_nYear)+"."+QString::number(m_nMonth));
    showCanlendarYearMonth->setGeometry(20,10,60,30);
    //上月控制
    lastMonth = new QPushButton(overcontrol);
    lastMonth->setObjectName("lastMonth");
    lastMonth->setText(tr("上"));
    lastMonth->setGeometry(110,10,35,30);
    connect(lastMonth, SIGNAL(clicked()), this, SLOT(showLastMonth()));
    //下月控制
    nextMonth = new QPushButton(overcontrol);
    nextMonth->setObjectName("nextMonth");
    nextMonth->setText(tr("下"));
    nextMonth->setGeometry(70,10,35,30);
    connect(nextMonth, SIGNAL(clicked()), this, SLOT(showNextMonth()));
    //年控制
    nian = new QPushButton(overcontrol);
    nian->setObjectName("nian");
    nian->setText(tr("年"));
    nian->setGeometry(265,10,50,30);
    connect(nian, SIGNAL(clicked()), this, SLOT(nianPanel()));
    //月控制
    yue = new QPushButton(overcontrol);
    yue->setObjectName("yue");
    yue->setText(tr("月"));
    yue->setGeometry(325,10,50,30);
    connect(yue, SIGNAL(clicked()), this, SLOT(yuePanel()));
    //跳转到今天
    today = new QPushButton(overcontrol);
    today->setObjectName("today");
    today->setText(tr("今天"));
    today->setGeometry(380,10,40,30);
    connect(today, SIGNAL(clicked()), this, SLOT(toToday()));
    verlayout->addWidget(overcontrol);

    //周一周二周三周四周五周六周日
    weekTitle = new QWidget(this);
    weekTitle->setObjectName("weekTitle");
    weekTitle->setFixedSize(440,35);
    for (int i = 0; i < Week; i++)
    {
        labelWeek[i] = new QLabel(weekTitle);
        labelWeek[i]->setText(s_strWeek[i]);
        labelWeek[i]->setObjectName("labelWeek");
        labelWeek[i]->setGeometry(10+i*60,0,60,35);
        labelWeek[i]->setAlignment(Qt::AlignCenter);
        if ((0 == (i % 7)) || (6 == (i% 7)))
        {
            labelWeek[i]->setProperty("weekend", true);
        }
    }
    verlayout->addWidget(weekTitle);

    //日历主体
    caBody = new QWidget(this);
    caBody->setObjectName("caBody");
    caBody->setFixedSize(440,360);
    gridLayout = new QGridLayout(caBody);
    gridLayout->setHorizontalSpacing(0);
    gridLayout->setVerticalSpacing(0);
    gridLayout->setContentsMargins(10, 0, 10, 0);
    for (int i = 0; i < 42; i++){
        labelDay[i] = new DayLabel(caBody);
        //labelDay[i]->setObjectName("labelDay");
        labelDay[i]->setAlignment(Qt::AlignCenter);
        labelDay[i]->setText(QString::number(i));
        if ((5 == (i % 7)) || (6 == (i% 7))){
            labelDay[i]->setProperty("weekend", true);
        }
        gridLayout->addWidget(labelDay[i], i / 7, i % 7);
        connect(labelDay[i], SIGNAL(signalClicked(int)), this, SLOT(sltDayClicked(int)));
        connect(labelDay[i], SIGNAL(signalEnter(int)), this, SLOT(sltDayEnter(int)));
        connect(labelDay[i], SIGNAL(signalLeave(int)), this, SLOT(sltDayLeave(int)));
        //connect(labelDay[i], SIGNAL(signalPlan(QString)), this, SIGNAL(signalPlan(QString)));
    }
    initDate();
    //labelDay[10]->setSelected(true);
    verlayout->addWidget(caBody);

    //nian面板
    nianList = new QWidget(this);
    nianList->setObjectName("nianList");
    nianList->setFixedSize(440,395);
    gridLayoutNian = new QGridLayout(nianList);
    gridLayoutNian->setHorizontalSpacing(0);
    gridLayoutNian->setVerticalSpacing(0);
    gridLayoutNian->setContentsMargins(10, 0, 10, 0);
    for (int i = 0; i < 12; i++)
    {
        labelNian[i] = new QLabel(nianList);
        //labelNian[i]->setObjectName("labelNian");
        labelNian[i]->setAlignment(Qt::AlignCenter);
        labelNian[i]->setText(QString::number(m_nYear+i)+"年");
        gridLayoutNian->addWidget(labelNian[i], i / 3, i % 3);
    }
    verlayout->addWidget(nianList);
    nianList->hide();

    //yue面板
    yueList = new QWidget(this);
    yueList->setObjectName("yueList");
    yueList->setFixedSize(440,395);
    gridLayoutYue = new QGridLayout(yueList);
    gridLayoutYue->setHorizontalSpacing(0);
    gridLayoutYue->setVerticalSpacing(0);
    gridLayoutYue->setContentsMargins(10, 0, 10, 0);
    for (int i = 0; i < 12; i++)
    {
        labelYue[i] = new QLabel(yueList);
        //labelYue[i]->setObjectName("labelYue");
        labelYue[i]->setAlignment(Qt::AlignCenter);
//        if( i==0 ){labelYue[i]->setProperty("year",m_nYear);}
//        else if( (i!=0) && ((m_nMonth+i)%12!=0) &&((m_nMonth+i)%12 < m_nMonth) )
//        {labelYue[i]->setProperty("year",m_nYear+1);}
//        else{labelYue[i]->setProperty("year",m_nYear);}
        if((m_nMonth+i)%12 == 0){labelYue[i]->setText("12月");}
        else{labelYue[i]->setText(QString::number((m_nMonth+i)%12)+"月");}
        gridLayoutYue->addWidget(labelYue[i], i / 3, i % 3);
    }
    site = 0;
    verlayout->addWidget(yueList);
    yueList->hide();

    //宜忌
    doAndNotdo = new QWidget(this);
    doAndNotdo->setObjectName("doAndNotdo");
    doAndNotdo->setFixedSize(440,55);
    //分割线2
    QPushButton *line2 = new QPushButton(doAndNotdo);
    line2->setFocusPolicy(Qt::NoFocus);
    line2->setGeometry(0,1,440,1);
    //选中日农历年月日，默认今天
    lunarDate = new QLabel(doAndNotdo);
    lunarDate->setObjectName("lunarDate");
    //lunarDate->setAlignment(Qt::AlignCenter);
    lunarDate->setText("选中日农历年月日，默认今天");
    lunarDate->setGeometry(30,10,180,20);
    //"宜忌"
    yiji = new QLabel(doAndNotdo);
    yiji->setObjectName("yiji");
    yiji->setText("宜忌");
    yiji->setGeometry(380,10,30,20);
    //是否展开宜忌，默认否
    onlyOne = new QCheckBox(doAndNotdo);
    onlyOne->setObjectName("onlyOne");
    onlyOne->move(415,13);
    connect(onlyOne, SIGNAL(stateChanged(int)), this, SLOT(onyiji(int)));
    verlayout->addWidget(doAndNotdo);

    addYiji = new QWidget(this);
    addYiji->setObjectName("addYiji");
    addYiji->setFixedSize(440,70);
    verlayout->addWidget(addYiji);
    whatToDo = new QLabel(addYiji);
    whatToDo->setObjectName("whatToDo");
    whatToDo->setGeometry(30,0,200,40);
//    QString str = "宜：破屋.";
//    str = str+"\n"+"忌：.";
    whatToDo->setText(yijiInfo);
    addYiji->hide();
}

void Widget::paintEvent(QPaintEvent *) {
  QStyleOption opt;
  opt.init(this);
  QPainter p(this);
  style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
  //p.fillRect(this->rect(), QColor(90, 90, 90, 90));
  //QWidget::paintEvent(event);
}

void Widget::showTime()
{
    QTime time = QTime::currentTime();
    QString txtTime = time.toString("hh:mm:ss");
    //qDebug()<<txtTime;
    //static int i = 0;
    labelTime->setText(txtTime);
    //labelTime->setText(QTime::currentTime().toString()+"     "+QString::number(i++));
    //ui->lbl_timer->setText(txtTime);
}

void Widget::onyiji(int a)
{
    if(a == Qt::Checked)
    {
        qDebug()<<"宜忌选择框被选中";

        this->setFixedSize(440, 680);
        addYiji->show();

    }
    else if(a == Qt::Unchecked)
    {
        qDebug()<<"宜忌选择框未被选中";
//        verlayout->removeWidget(addYiji);
//        addYiji->deleteLater();
        this->setFixedSize(440, 610);
        addYiji->hide();
    }
}

void Widget::showLastMonth()
{
    clickone = -1;
    enterone = 0;

    qDebug()<<"上一月";
    if((m_nMonth == 1) && (m_nYear != 1))
    {
        m_nMonth = 12;
        m_nYear = m_nYear -1;
        showCanlendarYearMonth->setText(QString::number(m_nYear)+"."+QString::number(m_nMonth));
        qDebug()<<QString::number(m_nYear)+"/"+QString::number(m_nMonth);
    }
    else if((m_nMonth == 1) && (m_nYear == 1))
    {
        showCanlendarYearMonth->setText(QString::number(m_nYear)+"."+QString::number(m_nMonth));
        qDebug()<<QString::number(m_nYear)+"/"+QString::number(m_nMonth);
    }
    else
    {
        m_nMonth = m_nMonth - 1;
        showCanlendarYearMonth->setText(QString::number(m_nYear)+"."+QString::number(m_nMonth));
        qDebug()<<QString::number(m_nYear)+"/"+QString::number(m_nMonth);
    }

    //判断当前面板状态
    if(caBody->isVisible() && nianList->isHidden() && yueList->isHidden())
    {
//        qDebug()<<caBody->isVisible();
//        qDebug()<<nianList->isHidden();
//        qDebug()<<yueList->isHidden();
        //刷新显示
        initDate();
    }
    else if(caBody->isHidden() && nianList->isVisible() && yueList->isHidden())
    {
        //刷新nian面板
        for(int i = 0; i < 12; i++)
        {
            labelNian[i]->setText(QString::number(m_nYear+i)+"年");

            if(  m_nYear+i == QDate::currentDate().year()  )
            {
                labelNian[i]->setObjectName("TONIAN");
                labelNian[i]->setStyleSheet("QLabel#TONIAN{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
            else
            {
                labelNian[i]->setObjectName("labelNian");
                labelNian[i]->setStyleSheet("QLabel#labelNian{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
        }

    }
    else if(caBody->isHidden() && nianList->isHidden() && yueList->isVisible())
    {
        site++;
        qDebug()<<site;

        //刷新yue面板
        for (int i = 0; i < 12; i++)
        {
            if((m_nMonth+i)%12 == 0)
            {
                labelYue[i]->setText("12月");
                if( i == site )
                {
                    labelYue[i]->setObjectName("TOYUE");
                    labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
                else
                {
                    labelYue[i]->setObjectName("labelYue");
                    labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
//                if( ( 12 == QDate::currentDate().month() ) && ( m_nYear == QDate::currentDate().year() ) )
//                {
//                    labelYue[i]->setObjectName("TOYUE");
//                    labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                }
//                else
//                {
//                    if( !(i==0) && ( m_nYear == QDate::currentDate().year()-1 ) && ( (m_nMonth+i)%12 == QDate::currentDate().month() ) && ( m_nMonth > QDate::currentDate().month() ) )
//                    {
//                        labelYue[i]->setObjectName("TOYUE");
//                        labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                    else
//                    {
//                        labelYue[i]->setObjectName("labelYue");
//                        labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                }
            }
            else
            {
                labelYue[i]->setText(QString::number((m_nMonth+i)%12)+"月");
                if( i == site )
                {
                    labelYue[i]->setObjectName("TOYUE");
                    labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
                else
                {
                    labelYue[i]->setObjectName("labelYue");
                    labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
//                if( ( ( m_nMonth+i)%12 == QDate::currentDate().month() ) && ( m_nYear == QDate::currentDate().year() ) )
//                {
//                    labelYue[i]->setObjectName("TOYUE");
//                    labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                }
//                else
//                {
//                    if( !(i==0) && ( m_nYear == QDate::currentDate().year()-1 ) && ( (m_nMonth+i)%12 == QDate::currentDate().month() ) && ( m_nMonth > QDate::currentDate().month() ) )
//                    {
//                        labelYue[i]->setObjectName("TOYUE");
//                        labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                    else
//                    {
//                        labelYue[i]->setObjectName("labelYue");
//                        labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                }
            }
        }
    }

}

void Widget::showNextMonth()
{
    clickone = -1;
    enterone = 0;

    qDebug()<<"下一月";
    if(m_nMonth == 12)
    {
        m_nMonth = 1;
        m_nYear = m_nYear +1;
        showCanlendarYearMonth->setText(QString::number(m_nYear)+"."+QString::number(m_nMonth));
        qDebug()<<QString::number(m_nYear)+"/"+QString::number(m_nMonth);
    }
    else
    {
        m_nMonth = m_nMonth + 1;
        showCanlendarYearMonth->setText(QString::number(m_nYear)+"."+QString::number(m_nMonth));
        qDebug()<<QString::number(m_nYear)+"/"+QString::number(m_nMonth);
    }

    //判断当前面板状态
    if(caBody->isVisible() && nianList->isHidden() && yueList->isHidden()){initDate();}
    else if(caBody->isHidden() && nianList->isVisible() && yueList->isHidden())
    {
        //刷新nian面板
        for (int i = 0; i < 12; i++)
        {
            labelNian[i]->setText(QString::number(m_nYear+i)+"年");

            if(  m_nYear+i == QDate::currentDate().year()  )
            {
                labelNian[i]->setObjectName("TONIAN");
                labelNian[i]->setStyleSheet("QLabel#TONIAN{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
            else
            {
                labelNian[i]->setObjectName("labelNian");
                labelNian[i]->setStyleSheet("QLabel#labelNian{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
        }

    }
    else if(caBody->isHidden() && nianList->isHidden() && yueList->isVisible())
    {
        site--;
        qDebug()<<site;

        //刷新yue面板
        for (int i = 0; i < 12; i++)
        {
            if((m_nMonth+i)%12 == 0)
            {
                labelYue[i]->setText("12月");
                if( i == site )
                {
                    labelYue[i]->setObjectName("TOYUE");
                    labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
                else
                {
                    labelYue[i]->setObjectName("labelYue");
                    labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
//                if( i==0 ){labelYue[i]->setProperty("year",m_nYear);}
//                else if( (i!=0) && ((m_nMonth+i)%12!=0) &&((m_nMonth+i)%12 < m_nMonth) )
//                {labelYue[i]->setProperty("year",m_nYear+1);}
//                else{labelYue[i]->setProperty("year",m_nYear);}


//                if( ( 12 == QDate::currentDate().month() ) && ( m_nYear == QDate::currentDate().year() ) )
//                {
//                    if( (!(i == 0)) && ( m_nMonth > QDate::currentDate().month() ) )
//                    {
//                        labelYue[i]->setObjectName("labelYue");
//                        labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                    else
//                    {
//                        labelYue[i]->setObjectName("TOYUE");
//                        labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                }
//                else
//                {
//                    labelYue[i]->setObjectName("labelYue");
//                    labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                }
            }
            else
            {
                labelYue[i]->setText(QString::number((m_nMonth+i)%12)+"月");
                if( i == site )
                {
                    labelYue[i]->setObjectName("TOYUE");
                    labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
                else
                {
                    labelYue[i]->setObjectName("labelYue");
                    labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
                }
//                if( i==0 ){labelYue[i]->setProperty("year",m_nYear);}
//                else if( (i!=0) && ((m_nMonth+i)%12!=0) &&((m_nMonth+i)%12 < m_nMonth) )
//                {labelYue[i]->setProperty("year",m_nYear+1);}
//                else{labelYue[i]->setProperty("year",m_nYear);}

//                if( ( ( m_nMonth+i)%12 == QDate::currentDate().month() ) && ( m_nYear == QDate::currentDate().year() ) )
//                {
//                    if( (!(i == 0)) && ( m_nMonth > QDate::currentDate().month() ) )
//                    {
//                        labelYue[i]->setObjectName("labelYue");
//                        labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                    else
//                    {
//                        labelYue[i]->setObjectName("TOYUE");
//                        labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                    if( !(i==0) && ( m_nYear == QDate::currentDate().year()-1 ) && ( (m_nMonth+i)%12 == QDate::currentDate().month() ) && ( m_nMonth > QDate::currentDate().month() ) )
//                    {
//                        labelYue[i]->setObjectName("TOYUE");
//                        labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                    }
//                }
//                else
//                {

//                    labelYue[i]->setObjectName("labelYue");
//                    labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
//                }
            }
        }
    }
}

void Widget::nianPanel()
{
    qDebug()<<"nian被点击了";

    //刷新nian面板
    for (int i = 0; i < 12; i++)
    {
        labelNian[i]->setText(QString::number(m_nYear+i)+"年");

        if(  m_nYear+i == QDate::currentDate().year()  )
        {
            labelNian[i]->setObjectName("TONIAN");
            labelNian[i]->setStyleSheet("QLabel#TONIAN{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
        }
        else
        {
            labelNian[i]->setObjectName("labelNian");
            labelNian[i]->setStyleSheet("QLabel#labelNian{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
        }
    }

    weekTitle->hide();
    caBody->hide();
    nianList->show();
    yueList->hide();
    //verlayout->removeWidget(doAndNotdo);
    //if(onlyOne->checkState() == Qt::Checked){verlayout->removeWidget(addYiji);}
    //verlayout->addWidget(nianList);
    //verlayout->addWidget(doAndNotdo);
    //if(onlyOne->checkState() == Qt::Checked){verlayout->addWidget(addYiji);}
}

void Widget::yuePanel()
{
    qDebug()<<"yue被点击了";

    //刷新yue面板
    for (int i = 0; i < 12; i++)
    {
        if((m_nMonth+i)%12 == 0)
        {
            labelYue[i]->setText("12月");
            if( ( 12 == QDate::currentDate().month() ) && ( m_nYear == QDate::currentDate().year() ) )
            {
                labelYue[i]->setObjectName("TOYUE");
                labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
            else
            {
                labelYue[i]->setObjectName("labelYue");
                labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
        }
        else
        {
            labelYue[i]->setText(QString::number((m_nMonth+i)%12)+"月");
            if( ( ( m_nMonth+i)%12 == QDate::currentDate().month() ) && ( m_nYear == QDate::currentDate().year() ) )
            {
                labelYue[i]->setObjectName("TOYUE");
                labelYue[i]->setStyleSheet("QLabel#TOYUE{background:rgb(55,143,250);border-radius: 4px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
            else
            {
                labelYue[i]->setObjectName("labelYue");
                labelYue[i]->setStyleSheet("QLabel#labelYue{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 17px;}");
            }
        }
    }

    weekTitle->hide();
    caBody->hide();
    nianList->hide();
    yueList->show();
}

void Widget::toToday()
{
    clickone = -1;
    enterone = 0;

    qDebug()<<"跳转到今天";
    site = 0;
    m_nYear  = QDate::currentDate().year();
    m_nMonth = QDate::currentDate().month();
    m_nDay = QDate::currentDate().day();
    showCanlendarYearMonth->setText(QString::number(m_nYear)+"."+QString::number(m_nMonth));
    qDebug()<<QString::number(m_nYear)+"/"+QString::number(m_nMonth)+"/"+QString::number(m_nDay);

    weekTitle->show();
    caBody->show();
    nianList->hide();
    yueList->hide();

    initDate();
}

void Widget::sltDayClicked(int n)
{
    //qDebug()<<n;
    //qDebug()<<clickone;

    if(caBody->isVisible() && nianList->isHidden() && yueList->isHidden())
    {
        if(n==5)
        {
            for(int i =0; i <42; i++)
            {
                labelDay[i]->setStyleSheet("QLabel#TODAY{border: 1px solid rgb(55,143,250);border-radius: 1px;color: white;font: bold;font-size: 16px;background:rgb(55,143,250);}"\
                                           "QLabel#labelDay{border: 0px solid rgb(55,143,250);border-radius: 2px;color: white;font: bold;font-size: 16px;}"\
                                           "QLabel#lastMonthDay{color: #999999;border: 0px solid #FFFFFF;font-size: 16px;}"\
                                           "QLabel#nextMonthDay{color: #999999;border: 0px solid #FFFFFF;font-size: 16px;}");
            }
        }
        else if(n==6)
        {
            for(int i =0; i <42; i++)
            {
                //qDebug()<<(labelDay[i]->property("clikedday") == clickone);
                if(labelDay[i]->property("clikedday") == clickone)
                {
                    labelDay[i]->setStyleSheet("QLabel#labelDay{border: 1px solid rgb(55,143,250);border-radius: 2px;color: white;font: bold;font-size: 16px;}"\
                                               "QLabel#lastMonthDay{border: 1px solid rgb(55,143,250);border-radius: 2px;color: #999999;font-size: 16px;}"\
                                               "QLabel#nextMonthDay{border: 1px solid rgb(55,143,250);border-radius: 2px;color: #999999;font-size: 16px;}");
                }
                else
                {
                    labelDay[i]->setStyleSheet("QLabel#labelDay{color: white;font: bold;font-size: 16px;}"\
                                               "QLabel#TODAY{background:rgb(55,143,250);border-radius: 3px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 16px;}"\
                                               "QLabel#lastMonthDay{color: #999999;font-size: 16px;}"\
                                               "QLabel#nextMonthDay{color: #999999;font-size: 16px;}");
                }
            }
        }
    }
    else if(caBody->isHidden() && nianList->isVisible() && yueList->isHidden())
    {
    }
    else if(caBody->isHidden() && nianList->isHidden() && yueList->isVisible())
    {
    }


}

void Widget::sltDayEnter(int m)
{
    if(caBody->isVisible() && nianList->isHidden() && yueList->isHidden())
    {
        if(m==5)
        {
            for(int i =0; i <42; i++)
            {
                labelDay[i]->setStyleSheet("QLabel#TODAY{border: 1px solid rgb(55,143,250);border-radius: 1px;color: white;font: bold;font-size: 16px;background:rgb(55,143,250);}"\
                                           "QLabel#labelDay{border: 0px solid rgb(55,143,250);border-radius: 2px;color: white;font: bold;font-size: 16px;}"\
                                           "QLabel#lastMonthDay{color: #999999;border: 0px solid #FFFFFF;font-size: 16px;}"\
                                           "QLabel#nextMonthDay{color: #999999;border: 0px solid #FFFFFF;font-size: 16px;}");
            }
        }
        else if(m==6)
        {
            for(int i =0; i <42; i++)
            {
                if(labelDay[i]->property("enterday") == enterone)
                {
                    labelDay[i]->setStyleSheet("QLabel#labelDay{border: 1px solid rgb(55,143,250);border-radius: 2px;color: white;font: bold;font-size: 16px;}"\
                                               "QLabel#lastMonthDay{border: 1px solid rgb(55,143,250);border-radius: 2px;color: #999999;font-size: 16px;}"\
                                               "QLabel#nextMonthDay{border: 1px solid rgb(55,143,250);border-radius: 2px;color: #999999;font-size: 16px;}");
                }
                else if(labelDay[i]->property("clikedday") != clickone)
                {
                    labelDay[i]->setStyleSheet("QLabel#labelDay{color: white;font: bold;font-size: 16px;}"\
                                               "QLabel#TODAY{background:rgb(55,143,250);border-radius: 3px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 16px;}"\
                                               "QLabel#lastMonthDay{color: #999999;font-size: 16px;}"\
                                               "QLabel#nextMonthDay{color: #999999;font-size: 16px;}");
                }
            }
        }
    }
    else if(caBody->isHidden() && nianList->isVisible() && yueList->isHidden())
    {
    }
    else if(caBody->isHidden() && nianList->isHidden() && yueList->isVisible())
    {
    }
}

void Widget::sltDayLeave(int l)
{
    if(caBody->isVisible() && nianList->isHidden() && yueList->isHidden())
    {
        for(int i =0; i <42; i++)
        {
            if(labelDay[i]->property("clikedday") != clickone)
            {
                labelDay[i]->setStyleSheet("QLabel#labelDay{color: white;font: bold;font-size: 16px;}"\
                                           "QLabel#TODAY{background:rgb(55,143,250);border-radius: 3px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 16px;}"\
                                           "QLabel#lastMonthDay{color: #999999;font-size: 16px;}"\
                                           "QLabel#nextMonthDay{color: #999999;font-size: 16px;}");
            }
        }
    }
    else if(caBody->isHidden() && nianList->isVisible() && yueList->isHidden())
    {
    }
    else if(caBody->isHidden() && nianList->isHidden() && yueList->isVisible())
    {
    }
}


Widget::~Widget()
{
    delete ui;
}

void Widget::initDate()
{
    qDebug()<<"当前显示"+QString::number(m_nYear)+"年";
    qDebug()<<"当前显示"+QString::number(m_nMonth)+"月";
    // 首先判断当前月的第一天是星期几
    int nWeek  = Date::getFirstDayOfWeek(m_nYear, m_nMonth);
    qDebug()<<"当前月第一天是星期"+QString::number(nWeek);
    int nMonthDays = Date::getMonthDays(m_nYear, m_nMonth);
    qDebug()<<"这个月有"+QString::number(nMonthDays)+"天";
    // 上月天数
    int nPreMonDays = Date::getMonthDays(1 == m_nMonth ? m_nYear - 1 : m_nYear, 1 == m_nMonth ? 12 : m_nMonth - 1);
    qDebug()<<"上个月有"+QString::number(nPreMonDays)+"天";

    if (0 == (nWeek-1)) {
        // 显示上月天数
        for (int i = 0; i < 7; i++) {
            dbOp.m_query(DATE_TABLE, nPreMonDays - 7 + i + 1, 1 == m_nMonth ? 12 : m_nMonth - 1, 1 == m_nMonth ? m_nYear - 1 : m_nYear);
            dbOp.query.next();
//            labelDay[i]->setText(QString::number(nPreMonDays - 7 + i + 1)+"\n"+"农历");
            labelDay[i]->setText(QString::number(nPreMonDays - 7 + i + 1)+"\n"+getInfo(dbOp.query.record()));
            labelDay[i]->setObjectName("lastMonthDay");
            labelDay[i]->setProperty("clikedday",0);
            labelDay[i]->setProperty("enterday",0);
            labelDay[i]->setStyleSheet("color: #999999;border: 0px solid #FFFFFF;font-size: 16px;");
//            QString strLunar = Date::getLunarMonAndDay(Widget.m_nYear, (Widget.m_nMonth)-1, nPreMonDays-7+i+1);
            //labelDay[i]->setColor(PREV_MONTH_DAY);

        }
        // 显示下月天数
        for (int i = 0; i < (42 - nMonthDays - 7); i++) {
            dbOp.m_query(DATE_TABLE, i + 1, 12 == m_nMonth ? 1 : m_nMonth + 1, 12 == m_nMonth ? m_nYear + 1 : m_nYear);
            dbOp.query.next();
//            labelDay[nMonthDays + 7 + i]->setText(QString::number(i + 1)+"\n"+"农历");
            labelDay[i]->setText(QString::number(i + 1)+"\n"+getInfo(dbOp.query.record()));
            labelDay[i]->setObjectName("nextMonthDay");
            labelDay[i]->setProperty("clikedday",0);
            labelDay[i]->setProperty("enterday",0);
            labelDay[nMonthDays + 7 + i]->setStyleSheet("color: #999999;border: 0px solid #FFFFFF;font-size: 16px;");
            //labelDay[nMonthDays + 7 + i]->setColor(NEXT_MONTH_DAY);
        }
    }
    else {
        // 显示上月天数
        for (int i = 0; i < (nWeek-1); i++) {
            dbOp.m_query(DATE_TABLE, nPreMonDays - (nWeek - 1) + i + 1, 1 == m_nMonth ? 12 : m_nMonth - 1, 1 == m_nMonth ? m_nYear - 1 : m_nYear);
            dbOp.query.next();
//            labelDay[i]->setText(QString::number(nPreMonDays - (nWeek - 1) + i + 1)+"\n"+"农历");
            labelDay[i]->setText(QString::number(nPreMonDays - (nWeek - 1) + i + 1)+"\n"+getInfo(dbOp.query.record()));
            labelDay[i]->setObjectName("lastMonthDay");
            labelDay[i]->setProperty("clikedday",0);
            labelDay[i]->setProperty("enterday",0);
            labelDay[i]->setStyleSheet("color: #999999;border: 0px solid #FFFFFF;font-size: 16px;");
//            QString strLunar = Date::getLunarMonAndDay(Widget.m_nYear, (Widget.m_nMonth)-1, nPreMonDays-(nWeek-1)+i+1);
            //labelDay[i]->setColor(PREV_MONTH_DAY);
        }

        // 显示下月天数
        for (int i = ((nWeek - 1) + nMonthDays); i < 42; i++) {
            dbOp.m_query(DATE_TABLE, i - ((nWeek-1) + nMonthDays) + 1, 12 == m_nMonth ? 1 : m_nMonth + 1, 12 == m_nMonth ? m_nYear + 1 : m_nYear);
            dbOp.query.next();
//            labelDay[i]->setText(QString::number(i - ((nWeek-1) + nMonthDays) + 1)+"\n"+"农历");
            labelDay[i]->setText(QString::number(i - ((nWeek-1) + nMonthDays) + 1)+"\n"+getInfo(dbOp.query.record()));
            labelDay[i]->setObjectName("nextMonthDay");
            labelDay[i]->setProperty("clikedday",0);
            labelDay[i]->setProperty("enterday",0);
            labelDay[i]->setStyleSheet("color: #999999;border: 0px solid #FFFFFF;font-size: 16px;");
            //labelDay[i]->setColor(NEXT_MONTH_DAY);
        }
    }

    // 显示当前月
    int index = 0;
    for (int i = (nWeek-1); i < (nMonthDays + (nWeek-1)); i++)
    {
        index = 0 == (nWeek-1) ? (i + 7) : i;
        dbOp.m_query(DATE_TABLE, i - (nWeek - 1) + 1, m_nMonth, m_nYear);
        dbOp.query.next();
//        labelDay[index]->setText(QString::number(i - (nWeek-1) + 1)+"\n"+"农历");
        labelDay[index]->setText(QString::number(i - (nWeek-1) + 1)+"\n"+getInfo(dbOp.query.record()));
//        if( ( i-(nWeek-1)+1 == QDate::currentDate().day() ) && ( m_nMonth == QDate::currentDate().month() ) )
//        {
//            labelDay[index]->setObjectName("TODAY");
//        }
//        else
//        {
//            labelDay[index]->setObjectName("labelDay");
//        }
        if( ( i-(nWeek-1)+1 == QDate::currentDate().day() ) && ( m_nMonth == QDate::currentDate().month() ) && ( m_nYear == QDate::currentDate().year() ) )
        {
            labelDay[index]->setObjectName("TODAY");
            labelDay[index]->setProperty("clikedday",0);
            labelDay[index]->setProperty("enterday",0);
            labelDay[index]->setStyleSheet("QLabel#TODAY{background:rgb(55,143,250);border-radius: 3px;color: white;border: 0px solid #FFFFFF;font: bold;font-size: 16px;}");
        }
        else
        {
            labelDay[index]->setObjectName("labelDay");
            labelDay[index]->setProperty("clikedday",0);
            labelDay[index]->setProperty("enterday",0);
            labelDay[index]->setStyleSheet("QLabel#labelDay{color: white;border: 0px solid #FFFFFF;font: bold;font-size: 16px;}");
        }
    }


}

DayLabel::DayLabel(QWidget *parent):
    QLabel(parent)
{
    labelIcon = new QLabel(this);
    labelIcon->setFixedSize(60,60);

}

void DayLabel::mousePressEvent(QMouseEvent *e)
{
    if(clickone==-1){
        clickone = 1;
    }
    else{
        clickone++;
    }

//    qDebug() << this->text() << this->property("type").toInt();
//    if(clickone%2 == 1)
//    {
//        this->setProperty("clikedday",1);
//    }
//    else if(clickone%2 == 0)
//    {
//        this->setProperty("clikedday",2);
//    }
    //QVariant isCurrentDay = this->property("currentday");
    //qDebug()<<this->objectName();
    //qDebug() << this->text();

    this->setProperty("clikedday",clickone);

    int a = 0;
    if(this->objectName() == "TODAY"){
        a = 5;
    }
    else{
        a =6;
    }
    Q_EMIT signalClicked(a);

    QLabel::mousePressEvent(e);
}

void DayLabel::enterEvent(QEvent *e)
{
    enterone++;
    this->setProperty("enterday",enterone);
    int a = 0;
    if(this->objectName() == "TODAY"){a = 5;}
    else{a =6;}
    Q_EMIT signalEnter(a);

    QLabel::enterEvent(e);
}

void DayLabel::leaveEvent(QEvent *e)
{
    int a = 0;
    if(this->objectName() == "TODAY"){a = 5;}
    else{a =6;}
    Q_EMIT signalLeave(a);

    QLabel::leaveEvent(e);
}

void Widget::wheelEvent(QWheelEvent *event)
{
    //qDebug()<<"aaa";

    // 当滚轮远离使用者时
    if(event->delta() > 0)
    {
        int a = 1;
        emit signalWheel(a);
        //qDebug()<<"aaa";
    }
    else//当滚轮向使用者方向旋转时
    {
        int a = 2;
        emit signalWheel(a);
        //qDebug()<<"aaa";
    }
    QWidget::wheelEvent(event);
}

void Widget::sltDayWheel(int m)
{
    qDebug()<<"bbb";

    if(m == 1){showLastMonth();}
    else if(m==2){showNextMonth();}
}

void Widget::updateData()
{
    QList<DateValue> dateValues;
    readJsonFiles(dateValues);
    // TODO
}


