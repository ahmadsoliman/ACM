#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

int h,w, curc;

int img[500][500], holes[1000000];

char in[100];

int color[500][500];

void dfsW(int x, int y){
    if(img[x][y]) return;
    if(color[x][y]==curc) return;
    color[x][y]=curc;
    if(x>0) dfsW(x-1, y);
    if(y>0) dfsW(x, y-1);
    if(x<=h) dfsW(x+1, y);
    if(y<=w) dfsW(x, y+1);
}

void dfsB(int x, int y){
    if(!img[x][y]) {
        if(color[x][y]==0){
            holes[curc]++;
            dfsW(x,y);
        }
        return;
    }
    if(color[x][y]==curc) return;
    color[x][y]=curc;
    if(x>0) dfsB(x-1, y);
    if(y>0) dfsB(x, y-1);
    if(x<=h) dfsB(x+1, y);
    if(y<=w) dfsB(x, y+1);
}

int main(){
    int kase=1;
    int v;
    while(scanf("%d %d", &h, &w)){
        if(w==0&h==0) break;

        memset(img, 0, sizeof img);
        for(int i=0; i<h; i++){
            scanf("%s", in);
            for(int j=0; j<w; j++){
                if(in[j]>='0'&&in[j]<='9') v = in[j]-'0';
                else v = in[j] = 10+(in[j]-'a');
                for(int k=0; k<4; k++){
                    img[i+1][1+j*4+3-k]=v&(1<<k);
                }
            }
        }
        w*=4;

        memset(holes, 0, sizeof holes);
        memset(color, 0, sizeof color);
        curc=1;
        dfsW(0,0);
        curc++;
        for(int i=1; i<=h; i++){
            for(int j=1; j<=w; j++){
                if(img[i][j] && color[i][j]==0){
                    dfsB(i,j);
                    curc++;
                }
            }
        }

        string s="";
        for(int i=2; i<curc; i++){
            switch(holes[i]){
            case 0: s+="W"; break;
            case 1: s+="A"; break;
            case 2: s+="K"; break;
            case 3: s+="J"; break;
            case 4: s+="S"; break;
            case 5: s+="D"; break;
            }
        }
        sort(s.begin(), s.end());
        printf("Case %d: %s\n", kase++, s.c_str());

    }
    return 0;
}
