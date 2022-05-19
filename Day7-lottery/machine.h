#ifndef MACHINE_H
#define MACHINE_H


class Machine
{
public:
    Machine();
    ~Machine();

    void Generate();
    int hq();
    int lq();
    void Check(int a[]);

private:
    int color[7];
};

#endif // MACHINE_H
