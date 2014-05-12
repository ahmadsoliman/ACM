#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

char arr[15][15];

int isMine(int i, int j, int r, int c){
    if(i<0||i>=r||j<0||j>=c) return 0;
    return arr[i][j]=='*';
}

int countAdj(int i, int j, int r, int c){
    return isMine(i-1,j-1,r,c)+isMine(i-1,j,r,c)+isMine(i-1,j+1,r,c)+
            isMine(i,j-1,r,c)+isMine(i,j+1,r,c)+
            isMine(i+1,j-1,r,c)+isMine(i+1,j,r,c)+isMine(i+1,j+1,r,c);
}

bool check(int r, int c, int m){
    vector<vector<bool> > revealed(r,vector<bool>(c,false));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            revealed[i][j] = (arr[i][j]=='*');
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(arr[i][j]=='*') continue;

            vector<bool> vis(r*c, false);
            vector<vector<bool> > revealedTmp=revealed;
            queue<int> q;
            q.push(i*c+j);

            while(!q.empty()){
                int cur=q.front(); q.pop();
                if(vis[cur]) continue;
                vis[cur]=true;

                int curI=cur/c, curJ=cur%c;

                revealedTmp[curI][curJ]=true;

                if(countAdj(curI, curJ,r,c)==0){
                    for(int k=max(curI-1,0); k<=min(curI+1, r-1); k++){
                        for(int l=max(curJ-1,0); l<=min(curJ+1, c-1); l++){
                            if(arr[k][l]=='*') continue;
                            int z = k*c+l;
                            if(!vis[z]){
                                q.push(z);
                            }
                        }
                    }
                }
            }
            bool allRevealed=true;
            for(int k=0; k<r && allRevealed; k++){
                for(int l=0; l<c; l++){
                    if(!revealedTmp[k][l]){ printf("%d %d\n", k, l);
                        allRevealed=false;
                        break;
                    }
                }
            }
            if(allRevealed) {
                arr[i][j]='c';
                return true;
            }
        }
    }
    return false;
}

bool found;

void recur(int cur, int r, int c, int m){
    if(found) return;
    if(m==0){
        for(; cur<r*c; cur++){
            arr[cur/c][cur%c]='.';
        }
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
        if(check(r,c,m)){
            found=true;
            return;
        }
        return;
    }
    if(r*c-cur<m) return;

    int i=cur/c, j=cur%c;
    arr[i][j]='*';
    recur(cur+1, r,c,m-1);
    if(found) return;
    arr[i][j]='.';
    recur(cur+1, r,c,m);
}

void solve(int r, int c, int m){
    found=false;
    recur(0,r,c,m);
    if(!found){
        printf("Impossible\n");
        return;
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }
}

int main(){
    //freopen("C-small.in","r",stdin);
    //freopen("C-small.out", "w", stdout);
    int t, kase=1;
    scanf("%d", &t);
    while(t--){
        int r,c,m;
        scanf("%d %d %d", &r,&c,&m);


        printf("Case #%d:\n", kase++);
        solve(r,c,m);

        if(m==r*c-1){
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(i==r-1&&j==c-1) printf("c");
                    else printf("*");
                }
                printf("\n");
            }
        }else if(r>1&c>1){
            if(m>r*c-4) printf("Impossible\n");
            else{
                for(int i=0; i<r; i++){
                    for(int j=0; j<c; j++){
                        if(i==r-1&&j==c-1) printf("c");
                        else if((i==r-1&&j==c-2) || (i==r-2&&j==c-1) || (i==r-2&&j==c-2)) printf(".");
                        else{
                            if(m) printf("*"), m--;
                            else printf(".");
                        }
                    }
                    printf("\n");
                }
            }
        }else{
            for(int i=0; i<r; i++){
                for(int j=0; j<c; j++){
                    if(i==r-1&&j==c-1) printf("c");
                    else{
                        if(m) printf("*"), m--;
                        else printf(".");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
