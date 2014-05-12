#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int needed[5005], selfCnt;
set<int> notSelf;

vector<int> self;

int pre(int n, int k){
    int i, tmp, sum, cumm;

    selfCnt=0;
    cumm=0;

    for(i=1; i<=n; i++){
        if(notSelf.empty() || *notSelf.begin()!=i) {
            cumm++;
            if(selfCnt<k && cumm==needed[selfCnt]) self.push_back(i), selfCnt++;
        }else notSelf.erase(notSelf.begin());

        sum=tmp=i;
        while(tmp>0) sum+=tmp%10, tmp/=10;
        if(sum<=n) notSelf.insert(sum);
    }
    return cumm;
}

int main(){
    int i,k,  n, cur;
    scanf("%d %d", &n, &k);

    for(i=0; i<k; i++) {
        scanf("%d", &needed[i]);
    }
    printf("%d\n", pre(n, k));

    for(i=0; i<k; i++) {
        printf("%d", self[i]);
        if(i<k-1) printf(" ");
    }
    //printf("\n");
    return 0;
}
