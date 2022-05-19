#ifndef QQSTRING_H
#define QQSTRING_H

#include <QString>
using namespace std;

class QQString
{
public:
    QQString(const QString &s);
    ~QQString();

    QString append2(const QString &s);
    QString insert2(int n, const QString &s);
    bool startsWith2(const QString &s);
    QString replace2(int a, int b, const QString &s);


private:
    QString self;
};

#endif // QQSTRING_H
