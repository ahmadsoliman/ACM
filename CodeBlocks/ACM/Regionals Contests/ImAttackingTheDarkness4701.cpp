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

char expr[1000], p2s[100];
vector<string> prts, prts2;
vi dice;

int target, cnt;

void recur(int i, int sum){
    if(i==dice.size()) {
        if(sum>=target) cnt++;
        return;
    }
    if(sum>=target){
        int k = 1;
        for(int j=i; j<dice.size(); j++) k*=dice[j];
        cnt+=k;
        return;
    }
    int k=0;
    for(int j=i; j<dice.size(); j++) k+=dice[j];
    if(k+sum<target) return;
    for(int j=0; j<dice[i]; j++) recur(i+1, sum+j+1);
}

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
    int t, i,j,k, len, entered, v, ds,totalv, d;
    ll totalch;
    scanf("%d", &t);
    while(t--){
        scanf("%d %s", &target, expr);

        prts.clear();
        prts2.clear();
        dice.clear();

        char *p = strtok(expr, "+");
        while(p!=NULL){
            prts.push_back(p);
            p = strtok(NULL, "+");
        }
        for(i=0; i<prts.size(); i++){
            char *p2 = strtok((char*)prts[i].c_str(), "-");
            entered=0;
            while(p2!=NULL){
                prts2.push_back(p2);
                if(!entered) entered=1;
                else prts2[prts.size()-1]="-"+prts2[prts.size()-1];
                p2 = strtok(NULL, "-");
            }
        }
        totalv=0;
        totalch=1;
        for(i=0; i<prts2.size(); i++) {
            int found = prts2[i].find("d");
            if (found!=std::string::npos){
                char *p = strtok((char*)prts2[i].c_str(), "d");
                sscanf(p, "%d", &ds);
                p = strtok(NULL, "d");
                sscanf(p, "%d", &v);
                while(ds--){
                    dice.push_back(v);
                    totalv+=v;
                    totalch*=v;
                }
            }else{
                sscanf(prts2[i].c_str(), "%d", &v);
                target-=v;
            }
        }
        if(target<=dice.size()) printf("1\n");
        else if(target>totalv) printf("0\n");
        else{
            cnt=0;
            recur(0, 0);
            d=gcd(cnt, totalch);
            if(cnt==0) printf("0\n");
            else if(cnt==totalch) printf("1\n");
            else printf("%d/%lld\n", cnt/d, totalch/d);
        }
    }
    return 0;
}
/*
2
2 1d4-5+2d8
*/
