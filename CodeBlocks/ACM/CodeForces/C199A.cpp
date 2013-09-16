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

int arr[100010], freq[8];
int groups[33500][3];

int main(){
    int n, gc, i, j, k, f2, f3, f4;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &arr[i]);
        freq[arr[i]]++;
    }
    //sort(arr, arr+n);
    gc=n/3;

    if(freq[5]>0 || freq[7]>0){
        printf("-1\n");
        return 0;
    }
    if(freq[1]!=gc){
        printf("-1\n");
        return 0;
    }
    if(freq[2]+freq[3]!=gc){
        printf("-1\n");
        return 0;
    }
    if(freq[4]+freq[6]!=gc){
        printf("-1\n");
        return 0;
    }
    f2 = freq[2]-max(0, freq[2]-gc);
    f3 = (gc-f2);

    for(i=0; i<gc; i++) groups[i][0]=1;
    for(i=0; i<freq[2]; i++) groups[i][1]=2;
    for(; i<gc; i++) groups[i][1]=3;

    i=0;
    while(groups[i][1]==2 && freq[4]--) groups[i++][2]=4;
    while(freq[6]--) groups[i++][2]=6;

    if(i!=gc){
        printf("-1\n");
        return 0;
    }

    for(i=0; i<gc; i++) {
        for(j=0; j<3; j++) {
            printf("%d", groups[i][j]);
            if(j<2) printf(" ");
        }
        if(i<gc-1) printf("\n");
    }
    return 0;
}
