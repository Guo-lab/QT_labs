#include <iostream>
#include "sortclass.h"

using namespace std;

///////////////////////////
////////  Day6-4 //////////
/// ///////////////////////
int getIndex(int *s, int *sign, int n) {
    int cin = 0;
    sign[cin++] = 0;
    for(int i = 0; i < n-1; i++)
        if(s[i] > s[i+1])
            sign[cin++] = i+1;
    return cin;
}

void merge(int *s, int *b, int start1, int endl, int start2, int end2) {
    int b_i = start1;
    while( start1<=endl && start2<=end2 ) {
        if(s[start1]<s[start2])
            b[b_i++] = s[start1++];
        else
            b[b_i++] = s[start2++];
    }
    while(start1<=endl)
        b[b_i++] = s[start1++];
    while(start2<=end2)
        b[b_i++] = s[start2++];
}

void mergePass(int *s, int n, int *b, int *sign, int num, int jump) {
    int sign_i = 0;
    while((sign_i+2*jump) < num) {
        merge(s, b, sign[sign_i], sign[sign_i+jump]-1,sign[sign_i+jump] , sign[sign_i + 2*jump]-1);
        sign_i = sign_i + 2*jump;
    }
    if( sign_i+jump < num)
        merge(s, b, sign[sign_i], sign[sign_i+jump]-1, sign[sign_i+jump], n-1);

    else if(sign_i < num)
        for(int j = sign[sign_i];j<n;j++)
            b[j] = s[j];
}

void mergeSort(int *s, int n, int *sign, int num) {
    int jump = 1;
    int b[10];
    while(jump < num) {
        mergePass(s, n, b, sign, num, jump);
        jump+=jump;
        for(int i=0;i<10;i++)
            s[i] = b[i];
    }
}
/// //////////////////////////
////// ///////////////////////




int main() {
    int array[10];
    int sign[10];

    for(int i=0;i<10;i++)
        cin >> array[i];

    //// Day6-4  /////
    int num = getIndex(array, sign, 10);
    mergeSort(array, 10, sign, num);

    printf("%s", "Natural Sort:\n");

    for(int i=0;i<10;i++)
        cout << array[i] << " ";
    cout << endl;

    SortClass X;
    printf("%s", "Bubble Sort:\n");
    X.paoSort(array, 10);

    printf("%s", "Select Sort:\n");
    X.xuanSort(array, 10);

    return 0;
}
