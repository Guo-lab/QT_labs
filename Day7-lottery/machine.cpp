#include "machine.h"
#include <iostream>

#include <ctime>
#include <cstdlib>
#include <cstring>

#include <QDebug>

using namespace std;

Machine::Machine() {
    for(int i=0; i<7; i++)
        color[i] = 0;
}




// Generate red
int Machine::hq() {
    int a = (rand()%33)+1;
    if(a==color[0]||a==color[1]||a==color[2]||a==color[3]||a==color[4]||a==color[5])
        Machine::hq();
    else
        return a;
}
// Generate blue
int Machine::lq() {
    int a = rand()%17;
    if(a)
        return a;
    else
        Machine::lq();
}
// Generate top-module
void Machine::Generate() {
    srand(time(NULL));

    for(int i=0;i<6;i++)
        color[i]= hq();
    color[6] = lq();

    /*cout << "The machine generates the lottery: " <<endl;
    for(int i=0;i<7;i++)
        cout << color[i] << " ";
    cout <<endl;*/
}




// Check the prize
void Machine::Check(int a[]) {
    cout << "The machine generates the lottery: " <<endl;
    for(int i=0;i<7;i++)
        cout << color[i] << " ";
    cout <<endl;

    int r=0, b=0;
    for(int i=0;i<6;i++)
        for(int j=0;j<6;j++)
            if(a[i] == color[i]) {
                r++;
                break;
            }
    if(color[6]==a[6])
        b = 1;


    if(r==6 && b==1){
        cout<<endl<<"----------------"<<endl<<" 您获得了一等奖!  "<<endl<<"----------------"<<endl;
    } else {
        if(r==6 && b==0) {
            cout<<endl<<"----------------"<<endl<<" 您获得了二等奖！  "<<endl<<"----------------"<<endl;
        } else {
            if(r==5 && b==1) {
                cout<<endl<<"----------------"<<endl<<" 您获得了三等奖！  "<<endl<<"----------------"<<endl;
            } else {
                if((r==5 && b==0) || (r==4 && b==1)) {
                    cout<<endl<<"----------------"<<endl<<" 您获得了四等奖！  "<<endl<<"----------------"<<endl;
                } else {
                    if((r==4 && b==0) || (r==3 && b==1)) {
                        cout<<endl<<"----------------"<<endl<<" 您获得了五等奖！ "<<endl<<"----------------"<<endl;
                    } else {
                        if((r==2 && b==1) || (r==1 && b==1) || (r==0 && b==1)) {
                            cout<<endl<<"----------------"<<endl<<" 您获得了六等奖！  "<<endl<<"----------------"<<endl;
                        } else {
                            cout<<"很遗憾！你没有中奖！"<<endl;
                        }
                    }
                }
            }
        }
    }

}










Machine::~Machine() {

}
