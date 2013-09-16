#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include<map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

vector<int> LIS(vector<int> A) {
    int N = A.size(),i,j=-1,t;
    vector<int> pre(N,-1),res;
    map<int,int> m;
    map<int,int>::iterator k,l;
    for (i=0;i<N;i++) {
        if (m.insert(ii(A[i],i)).second) {
           k = m.find(A[i]);
           l = k;
           k++;
           if (l==m.begin()) pre[i]=-1;
           else {
               l--;
               pre[i]=l->second;
           }
           if (k!=m.end())
              m.erase(k);
        }
    }
    k=m.end();
    k--;
    j = k->second;
    while (j!=-1) {
      res.push_back(A[j]);
      j = pre[j];
    }
    reverse (res.begin(),res.end());
    return res;
}

vi nums, lis;

int main(){
    int i, j, n, k, d;

    //scanf("%d", &n);
    while(scanf("%d", &d)>0){
        nums.push_back(d);
    }

    lis = LIS(nums);
    printf("%d\n-\n", lis.size());
    for(i=0; i<lis.size(); i++) printf("%d\n", lis[i]);
    return 0;
}
