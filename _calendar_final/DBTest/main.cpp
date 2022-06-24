#include "mainwindow.h"
#include "widget.h"
#include "update.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Update *u = new Update();
    u->setAttribute(Qt::WA_DeleteOnClose, true);
    u->show();

    Widget w;
    w.show();

    return a.exec();
}
