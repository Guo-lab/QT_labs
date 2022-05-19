#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QLineEdit>
#include <QMovie>
#include <QDesktopServices>
#include <QUrl>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QLabel");
//    //纯文本显示
    QLabel *pLabel = new QLabel(this);
    pLabel->setGeometry(160,60,150,150);
//    pLabel->setText("窗前明月光， 疑似地上霜。举头望明月，低头思故乡。");
//    pLabel->setWordWrap(true);
//    //对齐方式
////    pLabel->setAlignment(Qt::AlignCenter);
//    //使用样式表来控制（水平居右、垂直居下）：
////    pLabel->setStyleSheet("qproperty-alignment: 'AlignBottom | AlignRight';");

    QString strHTML = QString("<html> \
                               <head> \
                               <style> \
                               font{color:black;} #f{font-size:18px; color: red;} \
                               </style> \
                               </head> \
                               <body>\
                               <font>%1</font><font id=\"f\">%2</font> \
                               <br/><br/> \
                               <img src=\":/4.5-1.png\" width=\"100\" height=\"100\"> \
                               </body> \
                               </html>").arg("I am ").arg("KylinOS");
//    pLabel->setText(strHTML);
//    pLabel->setAlignment(Qt::AlignCenter);

// PixMap Setting
//    QPixmap pixmap(":/4.5-1.png");
//    pLabel->setPixmap(pixmap);
//    pLabel->setFixedSize(50, 50);
//    pLabel->setScaledContents(true);

    //QMovie setting

    QMovie *pMovie = new QMovie(":/8.2-5.gif");
    pLabel->setMovie(pMovie);
    pLabel->setFixedSize(200, 200);
    pLabel->setScaledContents(true);
    pMovie->start();

    // href setting

//    pLabel->setText(QString("<a href = \"%1\">%2</a>").arg("https://www.baidu.com/").arg(QStringLiteral("百度一下")));
//    pLabel->setOpenExternalLinks(true);
//    connect(pLabel,SIGNAL(linkActivated(QString)),this,SLOT(openUrl(QString)));

}

void Widget::openUrl(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}

Widget::~Widget()
{
    delete ui;
}
