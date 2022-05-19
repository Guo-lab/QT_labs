#include <QCoreApplication>
#include <iostream>

#include "machine.h"

using namespace std;


//@ https://blog.csdn.net/dancheng1/article/details/52200861
//// Rule:
/// Red (1-33) Blue(1-16)
/// 一等奖：7个号码相符（6个红色球号码和1个蓝色球号码）（红色球号码顺序不限，下同）
/// 二等奖：6个红色球号码相符；
/// 三等奖：5个红色球号码和1个蓝色球号码相符；
/// 四等奖：5个红色球号码或4个红色球号码和1个蓝色球号码相符；
/// 五等奖：4个红色球号码或3个红色球号码和1个蓝色球号码相符；
/// 六等奖：1个蓝色球号码相符（有无红色球号码相符均可）


int main() {
    cout << "Welcome! Duotone Ball Lottery!" <<endl;
    while(true) {
        cout << "Generate Lottery ..."<< endl;

        Machine lottery;
        lottery.Generate();

        int lott[7];
        cout << "You want which 6 red numbers? [1-33]";
        for(int i=0;i<6;i++)
            cin>>lott[i];

        cout << "You want which blue numbers? [1-16]";
        cin >> lott[6];


        lottery.Check(lott);

        // EXIT
        cout << "Do you want to exit? [y|n] " << endl;
        char e;
        cin >> e;
        if(e=='y')
            break;
    }
}
