#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

int days(int m, int y){
    switch(m){
        case 0: case 2: case 4: case 6: case 7: case 9: case 11: return 31;
        case 3: case 5: case 8: case 10: return 30;
        case 1: if(y%100==0) {
                    if(y%400==0) return 29;
                    else return 28;
                } else if(y%4==0) return 29;
                    else return 28;
    }
}

int main(){
    int i,j, d, m, y, cnt=0;
    d = 0; y=1901;
    while(y<2001){
        m=0;
        while(m<12){
            if(d==5) cnt++;
            d = (d+days(m, y))%7;
            m++;
        }
        y++;
    }
    printf("%d\n", cnt);
    return 0;
}
