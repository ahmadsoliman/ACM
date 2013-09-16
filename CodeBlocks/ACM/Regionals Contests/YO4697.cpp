#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef int ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

string word, dic[200010];
vii occ[200010];

void recur(int s, int i, int j, int a){
    if(j==dic[s].size()){
        occ[s].push_back(ii(a+1,i));
        return;
    }
    if(i==word.size()) return;
    if(word[i]==dic[s][j]) recur(s, i+1, j+1, a);
    recur(s, i+1, j, a);
}

char in[35];

int main(){
    int t, n, i,j,k, cnt;
    scanf("%d", &t);
    while(t--){
        scanf("%d %s", &n, in);
        word = string(in);
        transform(word.begin(), word.end(), word.begin(), ::tolower);

        for(i=0; i<n; i++) {
            occ[i].clear();
            scanf("%s", in);
            dic[i] = string(in);
            transform(dic[i].begin(), dic[i].end(), dic[i].begin(), ::tolower);
            if(word.size()==dic[i].size()) continue;
            for(j=0; j<word.size(); j++){
                if(word[j]==dic[i][0]) recur(i, j, 1, j);
            }
        }
        cnt=0;

        printf("%d\n", cnt);
    }
    return 0;
}

/*
1
2 CHEVROLET
he
vet
*/
