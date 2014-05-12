/*j ID: ahmadad1
PROG: pprime
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

vector<int> palins;

unsigned long long powmod(long long a, long long b, long long  c){
  unsigned long long result = 1;
  unsigned long long base = a;
  while (b){
    if (b & 1){
      result = result*base%c;
    }
    b >>= 1;
    base = base*base%c;
  }
  return result;
}

int millerIsPrime(long long n, int itr){
    if(n==2) return 1;
    if(n<2||n%2==0) return 0;
    unsigned long long b,res;
    while(itr--){
        b = rand()%(n-1) + 1;
        res = powmod(b, n, n);
        if(res!=b) return 0;
        res = powmod(b, (n-1)/2, n);
        if(!(res==1||res==n-1)) return 0;
    }
    return 1;
}

void recur(int num, int dig){
    if(dig==5) return;

    int fullnum=num, fullnum2=num, add=num, add2=num/10;

    while(add>0) fullnum*=10,fullnum+=add%10, add/=10;
    while(add2>0) fullnum2*=10,fullnum2+=add2%10, add2/=10;

    if(millerIsPrime(fullnum, 5)) palins.push_back(fullnum);
    if(millerIsPrime(fullnum2, 5)) palins.push_back(fullnum2);

    for(int i=((dig)?0:1); i<10; i++) recur(num*10+i, dig+1);
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    int i,j,k,l, r;

    int a,b, num=0;
    scanf("%d %d", &a, &b);

    recur(0, 0);


    sort(palins.begin(), palins.end());

    i=lower_bound(palins.begin(), palins.end(), a)-palins.begin();


    for(; i<palins.size() && palins[i]<=b; i++) printf("%d\n", palins[i]);

    return 0;
}
