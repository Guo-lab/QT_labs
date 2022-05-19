#include "mainwindow.h"
#include <QApplication>

//@ https://www.cnblogs.com/Forever-Kenlen-Ja/p/4985133.html

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
