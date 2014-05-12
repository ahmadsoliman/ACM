#include <stdio.h>
#include <string.h>
#include <set>

using namespace std;

typedef pair<int, int> ii;

set<ii> s;

int main(){
    int a,b, cnt;
    scanf("%d %d", &a, &b);

    if(a%b!=0&&b%a!=0) { printf("-1\n"); return 0; }


    s.insert(ii(a,b));
    ii x,y;

    cnt=1;
    while(1){
        if(a==b) { printf("%d\n", cnt); return 0; }

        if(a>b){
            a-=b, b<<=1;
        }else{
            b-=a, a<<=1;
        }
        x=ii(a,b), y=ii(b,a);
        if(s.find(x)!=s.end() || s.find(y)!=s.end()) { printf("-1\n"); return 0; }
        s.insert(x);
        cnt++;
    }

    return 0;
}
