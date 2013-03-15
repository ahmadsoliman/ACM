#include <stdio.h>

int arr[201000], tmp[201000];

long long mergeSort(int begin, int end){
    if(begin>=end)return 0ll;

    int half = (begin+end)/2;
    long long countInv = mergeSort(begin,half);
    countInv += mergeSort(half+1,end);

    int i=begin, j=half+1, iTmp=begin;
    while(1){
        if (i>half){
            if (j>end)
                break;
            else{
                tmp[iTmp++]=arr[j++];
            }
        }else{
            if (j>end){
                tmp[iTmp++]=arr[i++];
            }else{
                if (arr[i]==arr[j]){
                    tmp[iTmp++]=arr[i++];
                    tmp[iTmp++]=arr[j++];
                }else{
                    if (arr[i] < arr[j]){
                        tmp[iTmp++]=arr[i++];
                    }else{
                        tmp[iTmp++]=arr[j++];
                        countInv++;
                    }
                }
            }
        }
    }
    for(i=begin; i<end; i++)arr[i]=tmp[i];
    return countInv;
}

int main(){
    int t,n,i;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++)scanf("%d", &arr[i]);
        printf("%lld\n", mergeSort(0,n-1));

        for(i=0; i<n; i++)printf("%d\n", arr[i]);
    }
    return 0;
}
