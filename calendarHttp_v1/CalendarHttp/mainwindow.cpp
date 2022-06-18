#include "mainwindow.h"
#include "ui_mainwindow.h"

// TODO -------------------------------------------
#include <QSslSocket>
#include <QDebug>
#include <QString>
#include <QHostInfo>
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
void MainWindow::on_pushButton_clicked()
{
/*
    QString hostName = QHostInfo::localHostName();
    QList <QHostAddress> list = QNetworkInterface::allAddresses();
    foreach(QHostAddress address, list)
    if (address.protocol() == QAbstractSocket::IPv4Protocol) {
        qDebug() << "Hostname：" << hostName;
        qDebug() << "IP地址：" << address.toString();	// IPv4地址
    }
*/
    QString hostName = "127.0.0.1"; // DO NOT CHANGE THIS AS IT MUST MATCH THE FQDN OF THE CERTIFICATE
    quint16 port = 22333;

    //QList<QSslError> expectedSslErrors;
    //QSslCertificate cert = QSslCertificate::fromPath("/home/sq/桌面/CalendarHttp/sslserver.pem").value(0);
    //expectedSslErrors.append(QSslError(QSslError::SelfSignedCertificate, cert));

    //QSslSocket sslSocket;
    QSslSocket *sslSocket = new QSslSocket(this);
    //sslSocket.addCaCertificates("/home/sq/桌面/CalendarHttp/sslserver.pem");
    //sslSocket.ignoreSslErrors();

    //QFile certificateFile("/home/sq/桌面/CalendarHttp/sslserver.pem");
    /*QFile certificateFile("/home/sq/桌面/CalendarHttp/ca.pem");
    if (!certificateFile.open(QIODevice::ReadOnly))
        qDebug() << false;
    QSslCertificate m_sslLocalCertificate = QSslCertificate(certificateFile.readAll());
    //sslSocket->setLocalCertificate(m_sslLocalCertificate);
    sslSocket->addCaCertificate(m_sslLocalCertificate);
    //sslSocket->addDefaultCaCertificate(m_sslLocalCertificate);
    */
    sslSocket->addCaCertificates("../CalendarHttp/certificates/red_ca.pem");
    sslSocket->setPrivateKey("../CalendarHttp/certificates/blue_local.key");
    sslSocket->setLocalCertificate("../CalendarHttp/certificates/blue_local.pem");
    sslSocket->setPeerVerifyMode(QSslSocket::VerifyPeer);
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //sslSocket.setPeerVerifyMode(QSslSocket::VerifyNone);
    //sslSocket->setPeerVerifyMode(QSslSocket::VerifyNone);

    //sslSocket.connectToHostEncrypted(hostName, port);
    sslSocket->connectToHostEncrypted(hostName, port);
    //qDebug() << sslSocket.waitForEncrypted(-1);
    if (sslSocket->waitForEncrypted(-1)) { // Wait until encrypted connection is established, -1 no timeout
        qDebug() << "Connected";
        sslSocket->write("Hello, World!");    // Send message to the server
        if (sslSocket->waitForBytesWritten(-1))    // Wait until message is sent (also makes QSslSocket flush the buffer)
            qDebug() << "Message sent";
        else
            qDebug().nospace() << "ERROR: could not send message (" << qPrintable(sslSocket->errorString()) << ")";
        while (!sslSocket->waitForDisconnected());    // Wait until disconnected
        qDebug() << "Disconnected";
    } else
        qDebug().nospace() << hostName << " ERROR: could not establish encrypted connection (" << qPrintable(sslSocket->errorString()) << ")";
    //this->deleteLater();



    //startRequestGet(QUrl("https://www.baidu.com"));
    startRequestGet(QUrl("http://httpbin.org/get"));
    //startRequestGet(QUrl("http://127.0.0.1:22333"));
    //startRequestGet(QUrl("http://wthrcdn.etouch.cn/weather_mini?city="));
}
void MainWindow::on_pushButton_2_clicked()
{
    //startRequestPost(QUrl("https://www.baidu.com"));
    startRequestPost(QUrl("http://httpbin.org/post"));
    //startRequestPost(QUrl("http://wthrcdn.etouch.cn/weather_mini?city="));
}



/* 发起HTTP请求
 * 功能描述：发送HTTP请求，并与请求响应的槽绑定
 *  @param requestedUrl：请求需要的URL地址
*/
void MainWindow::startRequestGet(const QUrl &requestedUrl){
    url = requestedUrl;
    manager = new QNetworkAccessManager(this);

    if(url.toString().startsWith("https")) {
        QSslConfiguration sslConfig = req.sslConfiguration();
        sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
        sslConfig.setProtocol(QSsl::AnyProtocol);   //具体以OpenSSL版本为准
        req.setSslConfiguration(sslConfig);
    }
    req.setUrl(url);
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    req.setRawHeader("Accept",
"text/html,application/json,application/xhtml+xml,application/xml;\
q=0.9,image/avif,image/webp,image/apng,*/*;\
q=0.8,application/signed-exchange;\
v=b3;\
q=0.9");

    req.setRawHeader("Accept-Language", "zh-CN,en-US;q=0.8");
    req.setRawHeader("User-Agent",
"Mozilla/5.0 (Windows NT 10.0)\
AppleWebKit/537.36 (KHTML, like Gecko)\
Chrome/86.0.4240.198\
Safari/537.36");

    reply = manager->get(req);
      //qDebug() << QSslSocket::sslLibraryBuildVersionString(); //依赖的ssl版本
      //qDebug() << manager->supportedSchemes();
      //qDebug() << QSslSocket::supportsSsl();//是否支持ssl
      //qDebug() << QSslSocket::sslLibraryVersionString();
    connect(reply,&QNetworkReply::finished,this,&MainWindow::replyFinished);
}

void MainWindow::startRequestPost(const QUrl &requestedUrl){
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

    connect(reply,&QNetworkReply::finished,this,&MainWindow::replyFinished);
}







/* 获取HTTP的请求响应
 * 功能描述：HTTP请求后，接收服务器的信息
 * 1 检测请求响应是否有错误
 * 2 获取请求响应的状态码
 * 3 判断是否需要重定向
 *   - 不需要，则保存数据
 *   - 需要重定向，则获取重定向的URL，然后通过这个URL再次发起请求
*/
void MainWindow::replyFinished(){
    // <1>判断有没有错误
    if (reply->error()){
        //qDebug() << "statusCode:" << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();;
        qDebug()<<reply->errorString();
          // qDebug() << "Here";
        reply->deleteLater();
        return;
    }
    // <2>检测状态码
    int statusCode  = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    qDebug() << "statusCode:" << statusCode;
    // <3>判断是否需要重定向
    if (statusCode >= 200 && statusCode <300){ // ok
        // 准备读数据
        QTextCodec *codec = QTextCodec::codecForName("utf8");
        QString all = codec->toUnicode(reply->readAll());
        qDebug() << all;
        // 保存HTTP响应内容
        // 组装保存的文件名 文件名格式： 路径/年_月_日 小时_分_秒 httpfile.html
        QDateTime current_date_time =QDateTime::currentDateTime();
        QString current_date =current_date_time.toString("yyyy_MM_dd hh_mm_ss");
        QString filePath = "/home/sq/桌面/CalendarHttp";
        QString fileName = filePath + '/' + current_date + " httpfile" + ".html";
        QFile file(fileName);
        if (!file.open(QIODevice::ReadWrite | QIODevice::Text)){
            qDebug() << "file open error!";
            return ;
        }
        QTextStream out(&file);
        out.setCodec("UTF-8");
        out<<all << endl;
        file.close();
        // 数据读取完成之后，清除reply
        reply->deleteLater();
        reply = nullptr;
    } else if (statusCode >=300 && statusCode <400){ // GET redirect
        // 获取重定向信息
        const QVariant redirectionTarget = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
        // 检测是否需要重定向，如果不需要则读数据
        if (!redirectionTarget.isNull()) {
            const QUrl redirectedUrl = url.resolved(redirectionTarget.toUrl());

            reply->deleteLater();
            reply = nullptr;
            startRequestGet(redirectedUrl);

            qDebug()<< "http redirect to " << redirectedUrl.toString();
            return;
        }
    }
    // <After statusCode>
}
// ------------------------------------------------
