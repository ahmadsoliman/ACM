#include <stdio.h>

int arr[10010], cumm[10010];

int main(){
    int t, i, j, n, maxnum;

    std::vector<int>::iterator low;

    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &i , &n);
        scanf("%d", arr[0]);
        maxnum=cumm[0]=arr[0];
        for(i=1; i<n; i++) {
            scanf("%d", arr[i]);
            if(arr[i]>maxnum) maxnum=arr[i];
            cumm[i]=cumm[i-1]+arr[i];
        }
        for(i=0; i<n; i++) {

            low=std::lower_bound (v.begin(), v.end(), 20);
        }
    }
    return 0;
}
