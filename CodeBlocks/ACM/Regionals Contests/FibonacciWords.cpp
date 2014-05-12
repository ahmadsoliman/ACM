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

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<string, bool> sb;
typedef vector<int> vi;
typedef vector<ii> vii;

char p[100005];
int fib[105], plen;

int suffix(int n, int len){
    // str = p.substr(0, len)

    if(fib[n-2]<len){
        return suffix(n-2, len);
    }
    return suffix(n-2, len);
}

int prefix(int n, int start){
    int len = plen-start;
    // str = p.substr(start)

    return prefix(n-1, start);
}

ll recur(int n){
    if(n==0) return plen==1&&p[0]=='0';
    if(n==1) return plen==1&&p[0]=='1';

    ll res = recur(n-1)+recur(n-2);
    for(int i=1; i<len-1; i++){
        res += suffix(n-1, i)*prefix(n-2, i);
    }
    return res;
}

int main(){
    fib[0]=1;
    fib[1]=1;
    for(int i=2; i<105; i++) fib[i]=fib[i-1]+fib[i-2];

    int n;
    while(scanf("%d", &n)>0){
        scanf("%s", &p);
        plen = strlen(p);

    }

    return 0;
}
