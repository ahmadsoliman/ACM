#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

ll recur(vi &arr){
    if(arr.size()==1||arr.size()==0) return 0;
    vi left, right;
    int i,j, mid = ceil(arr.size()/2.0);

    for(i=0; i<mid; i++) left.push_back(arr[i]);
    for(; i<arr.size(); i++) right.push_back(arr[i]);
    ll inv=recur(left)+recur(right);
    arr.clear();
    for(i=0, j=0; i<left.size()&&j<right.size(); ){
        if(left[i]<=right[j]) arr.push_back(left[i++]);
        else { arr.push_back(right[j++]); inv+=left.size()-i;}
    }
    while(i<left.size()) arr.push_back(left[i++]);
    while(j<right.size()) arr.push_back(right[j++]);

   /* for(i=0; i<arr.size(); i++) printf("%d ", arr[i]);
    printf("%d\n", inv);
*/
    return inv;
}

map<string, int> sti;
map<string, int>::iterator it;
char in[1000];
vi elems;

int main(){
    int n, i,j,k, ind;

    while(scanf("%d", &n)>0){
        if(n==0) return 0;

        sti.clear();
        ind=0;
        for(i=0; i<n; i++){
            scanf("%s", in);
            sti.insert(make_pair(in, ind++));
        }
        elems.clear();
        for(i=0; i<n; i++){
            scanf("%s", in);
            elems.push_back(sti[in]);
        }
        printf("%lld\n", recur(elems));
    }
    return 0;
}
