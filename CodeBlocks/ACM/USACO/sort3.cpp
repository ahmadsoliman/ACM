/*j ID: ahmadad1
PROG: sort3
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

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int arr[1005], freq[10];

int main() {
    freopen("sort3.in", "r", stdin);
    freopen("sort3.out", "w", stdout);

    int n, i,j,k, f, last1,last2,last3, cnt=0;

    memset(freq, 0, sizeof freq);

    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &arr[i]), freq[arr[i]]++;

    for(i=0; i<n; i++){
        switch(arr[i]){
        case 1:{
            if(i<freq[1]) continue;

            last2=last3=-1;
            for(j=0; j<freq[1]; j++){
                if(arr[j]==2 && last2==-1) last2=j;
                if(arr[j]==3 && last3==-1) last3=j;
            }
            if(i>=freq[1] && i<freq[1]+freq[2]){
                if(last2>-1) cnt++, swap(arr[i], arr[last2]);
                else cnt++, swap(arr[i], arr[last3]);
            }else if(i>=freq[1]+freq[2]){
                if(last3>-1) cnt++, swap(arr[i], arr[last3]);
                else cnt++, swap(arr[i], arr[last2]);
            }
            break;
        }
        case 2:{

            if(i>=freq[1]+freq[2]){

                last3=-1;
                for(j=freq[1]; j<freq[1]+freq[2]; j++){
                    if(arr[j]==3) { last3=j; break; }
                }
            //printf("aa: %d %d %d\n", arr[i], arr[last3], cnt);
                cnt++, swap(arr[i], arr[last3]);
            //printf("aa: %d %d %d\n", arr[i], arr[last3], cnt);
            }
            break;
        }
        case 3:{
            break;
        }
        }
    }
    for(i=0; i<n; i++){
        switch(arr[i]){
        case 1:{
            if(i<freq[1]) continue;

            last2=last3=-1;
            for(j=0; j<freq[1]; j++){
                if(arr[j]==2 && last2==-1) last2=j;
                if(arr[j]==3 && last3==-1) last3=j;
            }
            if(i>=freq[1] && i<freq[1]+freq[2]){
                if(last2>-1) cnt++, swap(arr[i], arr[last2]);
                else cnt++, swap(arr[i], arr[last3]);
            }else if(i>=freq[1]+freq[2]){
                if(last3>-1) cnt++, swap(arr[i], arr[last3]);
                else cnt++, swap(arr[i], arr[last2]);
            }
            break;
        }
        case 2:{

            if(i>=freq[1]+freq[2]){

                last3=-1;
                for(j=freq[1]; j<freq[1]+freq[2]; j++){
                    if(arr[j]==3) { last3=j; break; }
                }
            //printf("aa: %d %d %d\n", arr[i], arr[last3], cnt);
                cnt++, swap(arr[i], arr[last3]);
            //printf("aa: %d %d %d\n", arr[i], arr[last3], cnt);
            }
            break;
        }
        case 3:{
            break;
        }
        }
    }
//for(i=0; i<n; i++) printf("%d\n", arr[i]);
    printf("%d\n", cnt);

    return 0;
}
