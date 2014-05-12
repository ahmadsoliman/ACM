/*
ID: ahmadad1
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;

char s[100];

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    scanf("%s", s);
    int i,len=strlen(s), v=1, v2=1;
    for(i=0; i<len; i++) v=(v*(s[i]-'A'+1))%47;

    scanf("%s", s);
    len=strlen(s);
    for(i=0; i<len; i++) v2=(v2*(s[i]-'A'+1))%47;

    if(v==v2) printf("GO\n");
    else printf("STAY\n");
    return 0;
}
