#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

pair<int,int> nums[100005];

int pows[100005];

int binarySearch(int i, int j, int k){
    if(i>=j){
        return i;
    }
    int mid = (j+i)/2;
    if(nums[mid].first==k){
        while(mid>-1 && nums[mid--].first==k);
        return mid+1;
    }
    if(nums[mid].first>k){
        if(mid>0 && nums[mid-1].first>=k)
            return binarySearch(i,mid,k);
        return mid;
    }else{
        if(mid<=j && nums[mid+1].first<k)
            return binarySearch(mid,j,k);
        return mid+1;
    }
}

int main(){
    int n,i,j, a,b, m=100000000, countN, digits, countTmp;
    long power;
    pows[0]=1;
    for(i=1; i<100005; i++){
        power=pows[i-1]*2;
        if(power>=m)
            pows[i]=(int)power%m;
        else
            pows[i]=(int)power;
    }

    while(scanf("%d", &n)>0){
        if(n==-1)
            break;
        for(i=0; i<n; i++){
            scanf("%d %d", &a, &b);
            nums[i]=make_pair(a,b);
        }
        sort(nums, nums+n);
        printf("%d\n", binarySearch(0,n-1, 3));
        countN=0;
        for(i=n-2; i>0; i--){
            j=binarySearch(i+1, n, nums[i].second);
            countN+=pows[n-j];
            if(countN>=m)
                countN%=m;
        }
        digits=0;
        countTmp=countN;
        while(countTmp>0){
            countTmp/=10;
            digits++;
        }
        for(i=0; i<8-digits; i++){
            printf("0");
        }
        if(countN>0)printf("%d\n", countN);
    }
    return 0;
}

/*
5
1 3
2 4
3 5
4 6
5 7
*/
