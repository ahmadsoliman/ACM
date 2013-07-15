#include <stdio.h>
#include <math.h>

char b[4][4];

int fair[20000000], z;

int isPalin(long num){
    long n = num;
    long rev = 0;
    int dig;
    while (num > 0){
        dig = num % 10;
        rev = rev * 10 + dig;
        num = num / 10;
    }
    return rev==n;
}

int binarySearch(long key, int low, int high){
    int mid=-1;
    while(low<high && low<z && high<z && mid<z){
        mid = (low+high)/2;
        if(key==fair[mid])return 1;
        if(key<fair[mid])high=mid;
        else{
            low = mid;
        }
    }
    return 0;
}

int main(){
    long t, i, j, A, B, a, b, countF, kase=1;
    freopen("C-large-1.in","r",stdin);
    freopen("c.out", "w", stdout);

    z=0;
    for(i=1; i<10000000; i++){
        if(isPalin(i) && isPalin(i*i))fair[z++]=i*i;
    }

    /*
    for(i=0; i<z; i++){
        printf("%lld\n", fair[i]);
    }
    */

    scanf("%d", &t);
    while(t--){
        scanf("%lld %lld", &A, &B);
        countF=0;
        while(A<=B){
            //for(i=0; i<z; i++)
            if(binarySearch(0, z, A))countF++;
            A++;
        }
        printf("Case #%lld: %lld\n", kase++, countF);
    }
    return 0;
}
