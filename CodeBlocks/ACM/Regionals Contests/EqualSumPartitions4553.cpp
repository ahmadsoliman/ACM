#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;


int arr[10010];
vector<int> cumm;

int main(){
    int t, i, j, n, d, maxnum, kase=1;
    bool found;

    vector<int>::iterator low;

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &i , &n);
        scanf("%d", &arr[0]);
        cumm.clear();
        cumm.push_back(maxnum=arr[0]);
        for(i=1; i<n; i++) {
            scanf("%d", &arr[i]);
            if(arr[i]>maxnum) maxnum=arr[i];
            cumm.push_back(cumm[i-1]+arr[i]);
        }
        for(i=0; i<n; i++) {
            d = 2*cumm[i];
            j=i+1;
            found = 1;
            while(1){
                if(binary_search(cumm.begin()+j, cumm.end(), d)){
                    low=lower_bound(cumm.begin()+j, cumm.end(), d);
                    j=low-cumm.begin();
                    if(j==n-1) break;
                    d+=cumm[i];
                }else{
                    found=0;
                    break;
                }
            }
            if(found){
                found = true;
                printf("%d %d\n", kase++, cumm[i]);
                break;
            }
        }
        if(!found){
            printf("%d %d\n", kase++, cumm[n-1]);
        }
    }
    return 0;
}
