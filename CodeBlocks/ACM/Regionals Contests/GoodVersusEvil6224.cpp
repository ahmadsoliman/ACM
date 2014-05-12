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

int good[10]={1,2,3,3,4,10}, bad[10]={1,2,2,2,3,5,10};
int main(){
    int t, i,j,k, s1, s2, kase=1;
    scanf("%d", &t);
    while(t--){
        s1=s2=0;
        for(i=0; i<6; i++) scanf("%d", &k), s1+=k*good[i];
        for(i=0; i<7; i++) scanf("%d", &k), s2+=k*bad[i];
        if(s1==s2) printf("Battle %d: No victor on this battle field\n", kase++);
        else if(s1>s2) printf("Battle %d: Good triumphs over Evil\n", kase++);
        else if(s1<s2) printf("Battle %d: Evil eradicates all trace of Good\n", kase++);
    }
    return 0;
}
