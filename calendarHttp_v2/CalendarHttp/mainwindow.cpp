#include "mainwindow.h"
#include "ui_mainwindow.h"

// TODO -------------------------------------------
#include <QSslSocket>
#include <QDebug>
#include <QString>
#include <QHostInfo>
#include <QJsonObject>
// ------------------------------------------------

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}




// TODO -------------------------------------------
void MainWindow::on_pushButton_clicked() {
    QString ipAddress = "192.168.183.136";
    //startRequestGet(QUrl(QString("http://%1/remote/files/year%2.json").arg(ipAddress).arg(1903)), 1903);
    for(int i=1901; i<2100; i++) {
        startRequestGet(QUrl(QString("http://%1/remote/files/year%2.json").arg(ipAddress).arg(i)), i);
        // 开启一个局部的事件循环，等待响应结束，退出
        QEventLoop loop;
        QTimer::singleShot(100, &loop, SLOT(quit()));
        loop.exec();
    }
}
void MainWindow::on_pushButton_2_clicked() { // POST [ disabled ]
    startRequestPost(QUrl("http://httpbin.org/post"), 1901);
}



/* 发起HTTP请求，并与请求响应的槽绑定
 *  @param requestedUrl：请求需要的URL地址
*/
void MainWindow::startRequestGet(const QUrl &requestedUrl, int num){
    url = requestedUrl;
    //qDebug() << num;
    manager = new QNetworkAccessManager(this);

    if(url.toString().startsWith("https")) {
        QSslConfiguration sslConfig = req.sslConfiguration();
        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
        sslConfig.setProtocol(QSsl::AnyProtocol);
        req.setSslConfiguration(sslConfig);
    }
    req.setUrl(url);
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    req.setRawHeader("Accept","text/html,application/json");
    req.setRawHeader("Accept-Language", "zh-CN,en-US;q=0.8");

    reply = manager->get(req);
    year = num;

    connect(reply,&QNetworkReply::finished,this, [this](){
        replyFinished(this->year);
    });
}

void MainWindow::startRequestPost(const QUrl &requestedUrl, int num){
    url = requestedUrl;
    manager = new QNetworkAccessManager(this);
    if(url.toString().startsWith("https")) {
        QSslConfiguration sslConfig = req.sslConfiguration();
        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
        sslConfig.setProtocol(QSsl::AnyProtocol);
        req.setSslConfiguration(sslConfig);
    }
    req.setUrl(url);
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);

    QHttpMultiPart *multiPart=new QHttpMultiPart(QHttpMultiPart::FormDataType);
    QHttpPart namePart;
    namePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"the name\";"));
    namePart.setBody("gsq");
    multiPart->append(namePart);
    multiPart->setBoundary("qtdata");
    req.setRawHeader("Content-Type","multipart/form-data;boundary=qtdata");

    reply = manager->post(req, multiPart);
    multiPart->setParent(reply); //在删除reply时一并释放
    year = num;
    connect(reply,&QNetworkReply::finished,this, [this](){
        replyFinished(this->year);
    });
}







/* HTTP请求后，接收服务器的信息
 *  检测请求响应是否有误 获取请求响应状态码
 *  判断是否需要重定向
 *     - 不需要，则保存数据
 *     - 需要重定向，则获取重定向的URL，然后通过这个URL再次发起请求
*/
void MainWindow::replyFinished(int num){
    if (reply->error()) {                       // <1>判断有没有错误
        qDebug()<<reply->errorString();
        reply->deleteLater();
        return;
    }
    int statusCode  = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "statusCode:" << statusCode;    // <2>检测状态码
    if (statusCode >= 200 && statusCode <300){  // <3>判断是否需要重定向  // ok
        QTextCodec *codec = QTextCodec::codecForName("utf8");  // 准备读数据
        QString all = codec->toUnicode(reply->readAll());      // qDebug() << all;
        QByteArray responseData = all.toUtf8();

        QJsonParseError json_error;
        QString imageData, txt;
        QJsonDocument document = QJsonDocument::fromJson(responseData, &json_error);
        if (json_error.error == QJsonParseError::NoError)
            if (document.isObject())
              qDebug() << document.object();
              if (document.object().contains("data")) {
                QJsonObject object_data =  document.object().value("data").toObject();
                if (object_data.contains("base64Image"))
                    imageData = object_data.value("base64Image").toString();
                if (object_data.contains("text"))
                    txt = object_data.value("text").toString();
              }
        //qDebug() << document;

        QString current_date = QDateTime::currentDateTime().toString("yyyy_MM_dd hh_mm_ss");
        //TODO                                 // 保存HTTP响应内容
        QString filePath = "/home/q/桌面/CalendarHttp/data";
        QString fileName = filePath + "/year" + QString("%1").arg(num) + ".json";
        QFile file(fileName);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
            qDebug() << "file open error!";
            return ;
        } 
        file.write(document.toJson());
        file.close();

        reply->deleteLater();  // 数据读取完成之后
        reply = nullptr;
    } else if (statusCode >=300 && statusCode <400){  // GET redirect
        const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);  // 获取重定向信息
        if (!redirectionTarget.isNull()) {  // 需要重定向
            const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());
            reply->deleteLater();
            reply = nullptr;
            startRequestGet(redirectedUrl, num);
            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }
}
// ------------------------------------------------
