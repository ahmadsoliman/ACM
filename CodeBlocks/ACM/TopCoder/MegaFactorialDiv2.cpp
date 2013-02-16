#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class MegaFactorialDiv2 {
    #define MAX (1001)
    #define MOD (1000000009)

    int isPrime[MAX];//, primes[MAX];

    void sieve(){
        memset(isPrime, 1, sizeof isPrime);
        int i,j, sqrtM=(int)sqrt(MAX), numOfPrimes=0;
        for(i=2; i<sqrtM; i++){
            if(!isPrime[i])continue;
            for(j=i*i; j<MAX; j+=i)isPrime[j]=0;
        }
        //for(i=2; i<MAX; i++)if(isPrime[i])primes[numOfPrimes++]=i;
    }

    int visited[1005][105], dp[1005][105][168];
    void factK(int N, int K){
        if(N==0)return;
        if(K==0 && isPrime[N]){
            dp[N][K][N]++;
        }
        if(!visited[N][K]){
            fact(N,K-1);
            fact(N-1,K-1);
            visited[N][K]=1;
        }
        int i;
        for(i=0;i<168;i++)dp[N][K][i]=dp[N][K-1][i]+dp[N-1][K-1][i];
    }

public:
	int countDivisors(int N, int K) {
        sieve();
        factK(N,K);
        int i;
        long long countDiv=1ll;
        for(i=2; i<168; i++)if(isPrime[i])countDiv=(countDiv*(dp[N][K][i]+1))%MOD;
        return countDiv;
	}
};


//<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
