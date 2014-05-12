/*j ID: ahmadad1
PROG: msquare
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

vc goal;
char res[100];
int done, len;
vc cur;

void recur(int last, int cnt, int d){
    if(done ||d==0) return;
    if(cur==goal){
        printf("%d\n", len);
        res[len]='\0';
        printf("%s\n", res);
        done=1;
        return;
    }

    vc tmp=cur;
    if(last==1 && cnt<1){
        cur[0]=tmp[4], cur[1]=tmp[5], cur[2]=tmp[6], cur[3]=tmp[7],
        cur[4]=tmp[0], cur[5]=tmp[1], cur[6]=tmp[2], cur[7]=tmp[3];

        res[len++]='A';
        recur(1, cnt+1, d-1);
        len--;
    }else if(last!=1){
        cur[0]=tmp[4], cur[1]=tmp[5], cur[2]=tmp[6], cur[3]=tmp[7],
        cur[4]=tmp[0], cur[5]=tmp[1], cur[6]=tmp[2], cur[7]=tmp[3];

        res[len++]='A';
        recur(1, 1, d-1);
        len--;
    }

    if(done) return;

    if(last==2 && cnt<3){
        cur[0]=tmp[3], cur[1]=tmp[0], cur[2]=tmp[1], cur[3]=tmp[2],
        cur[4]=tmp[7], cur[5]=tmp[4], cur[6]=tmp[5], cur[7]=tmp[6];

        res[len++]='B';
        recur(2, cnt+1, d-1);
        len--;
    }else if(last!=2){
        cur[0]=tmp[3], cur[1]=tmp[0], cur[2]=tmp[1], cur[3]=tmp[2],
        cur[4]=tmp[7], cur[5]=tmp[4], cur[6]=tmp[5], cur[7]=tmp[6];

        res[len++]='B';
        recur(2, 1, d-1);
        len--;
    }

    if(done) return;

    if(last==3 && cnt<3){
        cur[0]=tmp[0], cur[1]=tmp[5], cur[2]=tmp[1], cur[3]=tmp[3],
        cur[4]=tmp[4], cur[5]=tmp[6], cur[6]=tmp[2], cur[7]=tmp[7];

        res[len++]='C';
        recur(3, cnt+1, d-1);
        len--;
    }else if(last!=3){
        cur[0]=tmp[0], cur[1]=tmp[5], cur[2]=tmp[1], cur[3]=tmp[3],
        cur[4]=tmp[4], cur[5]=tmp[6], cur[6]=tmp[2], cur[7]=tmp[7];

        res[len++]='C';
        recur(3, 1, d-1);
        len--;
    }
}

int main() {
    freopen("msquare.in", "r", stdin);
    freopen("msquare.out", "w", stdout);

    int i,j,r, k;

    vc mcur, ns, p1, p2;
    for(i=0; i<4; i++) scanf("%d", &k), goal.push_back('0'+k);
    for(i=0; i<4; i++) scanf("%d", &k), p2.push_back('0'+k);
    reverse(p2.begin(), p2.end());
    for(i=0; i<4; i++) goal.push_back(p2[i]);

    for(i=1; i<=4; i++) mcur.push_back('0'+i);
    for(i=8; i>=5; i--) mcur.push_back('0'+i);

    done=0;
    for(i=6; i<100; i+=2){
        if(done) break;
        len=0;
        cur=mcur;
        recur(0, 0, i);
    }

    return 0;
}




