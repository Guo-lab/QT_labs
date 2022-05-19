#include "calculator.h"
#include <QApplication>

//@ https://blog.csdn.net/weixin_48180029/article/details/116405223

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Calculator w;
    w.show();

    return a.exec();
}
