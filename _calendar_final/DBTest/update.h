#ifndef UPDATE_H
#define UPDATE_H


#include <QMainWindow>

//TODO -------------------------------------------
#include <QDebug>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTextCodec>
#include <QFile>
#include <QTextStream>
#include <QDateTime>
// ------------------------------------------------


namespace Ui {
class Update;
}

class Update : public QMainWindow
{
    Q_OBJECT

public:
    explicit Update(QWidget *parent = nullptr);
    ~Update();


// TODO -------------------------------------------
private:
    QUrl url;
    QNetworkRequest req;
    QNetworkReply *reply;
    QNetworkAccessManager *manager;
    int year;

private slots:
    void startRequestGet(const QUrl &requestedUrl, int num);
    void startRequestPost(const QUrl &requestedUrl, int num);
    void replyFinished(int num);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
// ------------------------------------------------



private:
    Ui::Update *ui;
};


#endif // UPDATE_H
