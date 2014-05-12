#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef long long ll;

int cnt[15];
int grid[15][15];

int main(){
    int i,j,k;


    int h,w,c;
    while(scanf("%d %d %d", &h, &w, &c)>0){

        for(i=0; i<c; i++) scanf("%d", &cnt[i]);

        k=1;
        for(i=h-1; i>=0; i--){
            if(i%2==0){
                for(j=0; j<w; j++){
                    if(cnt[k-1]==0) k++;
                    grid[i][j]= k;
                    cnt[k-1]--;
                }
            }else{
                for(j=w-1; j>=0; j--){
                    if(cnt[k-1]==0) k++;
                    grid[i][j]= k;
                    cnt[k-1]--;
                }
            }
        }

        for(i=0; i<h; i++){
            for(j=0; j<w; j++){
                printf("%d", grid[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
