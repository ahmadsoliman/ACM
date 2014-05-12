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

int arr1[5][5], arr2[5][5];

int main(){
    freopen("A-small.in","r",stdin);
    freopen("A-small.out", "w", stdout);
    int t, kase=1, r1, r2;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &r1);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                scanf("%d", &arr1[i][j]);
            }
        }
        scanf("%d", &r2);
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                scanf("%d", &arr2[i][j]);
            }
        }
        r1--, r2--;
        int c=0, n=-1;
        set<int> s(arr1[r1], arr1[r1]+4);
        for(int i=0; i<4; i++){
            if(s.find(arr2[r2][i])!=s.end()) c++, n=arr2[r2][i];
        }
        printf("Case #%d: ", kase++);
        if(c==0) printf("Volunteer cheated!\n");
        else if(c==1) printf("%d\n", n);
        else printf("Bad magician!\n");
    }
    return 0;
}
