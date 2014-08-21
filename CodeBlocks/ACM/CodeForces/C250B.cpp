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
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;


int lowbit(int x){
    return x&(-x);
}

int taken[100010];

vi pows2;


int main() {
    int sum, lim;
    scanf("%d %d", &sum, &lim);

//    pows2.push_back(1);
//    for(int i=0; ; i++){
//        if((pows2.back()<<1)>100000) break;
//        pows2.push_back((pows2.back()<<1));
//    }

//    for(int i=pows2.size()-1; i>=0 && sum>0; i--){
//        if(pows2[i]>lim) continue;
//        if(pows2[i]>sum) continue;
//        sum-=pows2[i];
//        taken[pows2[i]]=1;
//    }
    int cnt =0;
    for(int i=lim; sum>0 && i>0; i--){
        //if(taken[i]) continue;
        if(lowbit(i)>sum) continue;
        sum-=lowbit(i);
        taken[i]=1;
        cnt++;
    }
    if(sum==0){
        printf("%d\n", cnt);
        for(int i=1; i<=lim; i++){
            if(taken[i]){
                cnt--;
                if(cnt) printf("%d ", i);
                else printf("%d\n", i);
            }
        }
    } else printf("-1\n");

    return 0;
}
