#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>


#define INF 1000000000

using namespace std;

int s[1500], n , len, moves[1000005];

bool check(){
    for(int i=0; i<n; i++) if(s[i]!=2) return false;
    if(s[n]!=0) return false;
    for(int i=n+1; i<len; i++) if(s[i]!=1) return false;
    return true;
}

void printCase(){
    for(int i=0; i<len; i++) printf("%d ", s[i]);
    printf("\n");
}

bool checkb(int space){
    for(int i=0; i<space; i++) if(s[i]!=2) return false;
    return true;
}

bool checkw(int space){
    for(int i=len-1; i>space; i--) if(s[i]!=1) return false;
    return true;
}


int main(){
    freopen("frogs.in","r",stdin);
    scanf("%d", &n);

    len=2*n+1;
    for(int i=0; i<n; i++) s[i]=1;
    s[n]=0;
    for(int i=n+1; i<len; i++) s[i]=2;

    int dir=1, space=n, m=0;

    while(1){
//        printf("dir: %d %d:: ", dir, space);
//        printCase();
        if(space==n && check()){
            break;
        }
        if(m==1000000){
            printf("-1\n");
            return 0;
        }
        if(dir){
            if(s[space+1]==2){
                s[space+1]=0;
                s[space]=2;
                space++;
            }else {
                s[space+2]=0;
                s[space]=2;
                space+=2;
            }
        }else{
            if(s[space-1]==1){
                s[space]=1;
                s[space-1]=0;
                space--;
            }else{
                s[space]=1;
                s[space-2]=0;
                space-=2;
            }
        }
        moves[m++]=space;
        if(space==0 || space==len-1) dir=!dir;
        else if(dir && s[space-1]==s[space+1] && s[space-1]==2) dir=!dir;
        else if(!dir && s[space-1]==s[space+1] && s[space-1]==1) dir=!dir;
        else if(space<len-1 && !dir && checkb(space) && s[space+1]==2) dir=!dir;
        else if(space>0 && dir && checkw(space) && s[space-1]==1) dir=!dir;
    }
    printf("%d\n", m);
    printf("%d", moves[0]);
    for(int i=1; i<m; i++) printf(" %d", moves[i]);

    return 0;
}
