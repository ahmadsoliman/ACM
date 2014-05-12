/*
ID: ahmadad1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>

using namespace std;

int isLeap(int y){
    if(y%100==0) return y%400==0;
    return y%4==0;
}

int daysInMonth(int m, int y){
    switch(m){
        case 2: if(isLeap(y)) {return 29;} return 28;
        case 9: case 4: case 6: case 11: return 30;
        default: return 31;
    }
}

int freq[10];

int main() {
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);

    int n, i;

    scanf("%d", &n);

    int y,m,d, day=2, numOfDays;
    for(y=1900; y<1900+n; y++){
        for(m=1; m<=12; m++){
            numOfDays=daysInMonth(m,y);
            for(d=1; d<=numOfDays; d++){
                if(d==13) freq[day]++;
                day=(day+1)%7;
            }
        }
    }

    printf("%d", freq[0]);
    for(i=1; i<7; i++) printf(" %d", freq[i]);
    printf("\n");

    return 0;
}
