#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef long long ll;

vector<ll> sumSqrs;
vector<ll>::iterator it;

void initSumSqrs(){
    ll i=2;
    sumSqrs.push_back(1);
    while(sumSqrs.back()<1000000000000000000ll){
        sumSqrs.push_back(sumSqrs.back()+i*i);
        i++;
    }
}

ll sumOdds[2000000];

void initSumOdds(){
    ll i=1;
    sumOdds[0]=1;
    for(int j=1; j<2000000; j++){
        sumOdds[j]=sumOdds[j-1]+2*j+1;
    }
}

int main(){
    freopen("army.in", "r", stdin);
    int i,j,k, t;
    ll n, row, midsum, len, x, rest, kase=1;

    initSumSqrs();
    initSumOdds();

    cin >> t;
    while(t--){
        cin >> n;

        it = lower_bound(sumSqrs.begin(), sumSqrs.end(), n);
        row = it-sumSqrs.begin();

        if(binary_search(sumSqrs.begin(), sumSqrs.end(), n)){
            cout << "Case " << kase++ << ": " << sumOdds[row] << endl;
            continue;
        }

        len = 2*row+1;
        midsum = (len/2+1)*(len/2+2)/2;

        if(row>0) n-=sumSqrs[row-1];

        if(n<=midsum){
            x = ceil(sqrt(2*n+0.25)-0.5);
            cout << "Case " << kase++ << ": " << (ll)(sumOdds[row-1]+x) << endl;
        }else{
            n-=midsum;
            midsum = (len/2)*(len/2+1)/2;
            rest = midsum-n;
            x = floor(sqrt(2*rest+0.25)-0.5);
            cout << "Case " << kase++ << ": " << (ll)(sumOdds[row-1]+len/2+1+len/2-x) << endl;
        }
    }
    return 0;
}
