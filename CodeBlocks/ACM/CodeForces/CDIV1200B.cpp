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

char s[100010];

int main(){
    scanf("%s", s);
    int len=strlen(s), i,j,k, last, cnt, changed;

    vi v, tmp;
    for(i=0; i<len; i++) v.push_back((s[i]=='+')?1:0);

    changed=1;
    while(changed && v.size()>1){
        changed=0;
        tmp.clear();
        last=v[0];
        cnt=0;
        for(i=1; i<v.size(); i++){
            if(v[i]==last) { cnt++; continue; }
            if(cnt==0) tmp.push_back(last);
            cnt=0;
            last=v[i];
        }
        if(cnt%2==0) tmp.push_back(last);
        if(v.size()!=tmp.size()) changed=1;
        v = tmp;
    }


    if(v.size()%2==1) { printf("No\n"); return 0; }
    if(v.size()>1) { printf("No\n"); return 0; }
    if(v.size()==0) { printf("Yes\n"); return 0; }
    printf("No\n");
    return 0;
}
