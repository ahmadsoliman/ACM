#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int nums[100000];

int LIS_Len(vector<int> A){
    int N = A.size(),i;
    set<int> s;
    set<int>::iterator k;
    for (i=0;i<N;i++) {
        if (s.insert(A[i]).second) {
           k = s.find(A[i]);
           k++;
           if (k!=s.end())
              s.erase(k);
        }
    }
    return s.size();
}

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

int main(){
    int i, j, n, k, maxlis, zero=0;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d", &nums[i]);
    }


   // vector<int> lis = LIS(vi(nums, nums+n));

    printf("%d\n", LIS_Len(vi(nums, nums+n)));
    return 0;
}

/*
8
-7 10 9 2 3 8 8 1
*/
