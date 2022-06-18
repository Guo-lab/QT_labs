#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


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
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
