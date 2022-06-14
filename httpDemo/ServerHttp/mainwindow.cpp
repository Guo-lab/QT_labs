#include "mainwindow.h"
#include "ui_mainwindow.h"

// TODO ---------------------------------
#include "sslserver.h"
#include <QCoreApplication>
#include <QHostAddress>
#include <QSslSocket>
#include <QThread>
#include <QDebug>
// --------------------------------------

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



// TODO ---------------------------------
void MainWindow::on_pushButton_clicked() {
    QHostAddress address = QHostAddress::Any;
    //QHostAddress address = QHostAddress("127.0.0.1");
    quint16 port = 22333;

    SslServer sslServer;  // : public QTcpServer
    //sslServer.setSslLocalCertificate("/home/sq/桌面/ServerHttp/sslserver.pem");
    //sslServer.setSslPrivateKey("/home/sq/桌面/ServerHttp/sslserver.key");
    sslServer.setSslLocalCertificate("../ServerHttp/certificates/red_local.pem");
    sslServer.setSslPrivateKey("../ServerHttp/certificates/red_local.key");
    //qDebug() << sslServer.setSslPrivateKey("../sslserver.key");
    sslServer.setSslProtocol(QSsl::TlsV1_2);

    if (sslServer.listen(address, port))
        qDebug().nospace() << "Now listening on " << qPrintable(address.toString()) << ":" << port;
    else
        qDebug().nospace() << "ERROR: could not bind to " << qPrintable(address.toString()) << ":" << port;

    if (sslServer.waitForNewConnection(-1)) { // Wait until a new connection is received, -1 means no timeout
        qDebug() << "New connection";
        qDebug() << sslServer.serverAddress();
        QSslSocket *sslSocket = dynamic_cast<QSslSocket*>(sslServer.nextPendingConnection());
        if (sslSocket->waitForReadyRead(1000)) { // Wait until some data is received, 5000 ms timeout
            QByteArray message = sslSocket->readAll(); // Read message
            qDebug() << "Message:" << QString(message);
            sslSocket->disconnectFromHost();    // Disconnect
            sslSocket->waitForDisconnected();   // Wait until disconnected
            qDebug() << "Disconnected";
        } else
            qDebug().nospace() << "ERROR: could not receive message (" << qPrintable(sslSocket->errorString()) << ")";
    } else
        qDebug().nospace() << "ERROR: could not establish encrypted connection (" << qPrintable(sslServer.errorString()) << ")";
    //this->deleteLater();
    //QThread::currentThread()->quit();
    //qApp->exit();
}
// --------------------------------------
