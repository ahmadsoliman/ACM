/*j ID: ahmadad1
PROG: sprime
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

vector<int> sprimes;
int n;

void recur(int num, int dig){
    if(dig==n){
        if(millerIsPrime(num, 5)) sprimes.push_back(num);
        return;
    }
    int nnum;
    for(int i=(dig?0:1); i<10; i++){
        nnum=num*10+i;
        if(millerIsPrime(nnum, 5)) recur(nnum, dig+1);
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);

    int i,j,k,l, r;

    int a,b, num=0;
    scanf("%d", &n);

    recur(0, 0);


    for(i=0; i<sprimes.size(); i++) printf("%d\n", sprimes[i]);

    return 0;
}
