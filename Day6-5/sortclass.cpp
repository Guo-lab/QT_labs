#include "sortclass.h"
#include<stdio.h>

SortClass::SortClass()
{

}


void SortClass::paoSort(int *s, int n) {
    for (int i = n-1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (s[j] > s[j + 1]) {
                s[j] = s[j] ^ s[j + 1];
                s[j + 1] = s[j] ^ s[j + 1];
                s[j] = s[j] ^ s[j + 1];
            }

    for(int i=0;i<n;i++)
        printf("%d ", s[i]);
    printf("\n");
}
void SortClass::xuanSort(int *s, int n) {
    int maxIndex = 0;
    int temp;
    for (int i = n-1; i > 0; i--) {
        maxIndex = 0;
        for (int j = 0; j <= i; j++)
            if (s[maxIndex] < s[j])
                maxIndex = j;

        if (maxIndex != i) {
            temp = s[maxIndex];
            s[maxIndex] = s[i];
            s[i] = temp;
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ", s[i]);
    printf("\n");
}



SortClass::~SortClass(){

}

