#include <stdio.h>
#include <string.h>

int nums[20];

int main(){
    int t, i,j,k,f, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &k);
        for(i=0; i<15; i++) scanf("%d", &nums[i]);

        int cnt=0;
        for(i=1; i<14; i++){
            for(j=i; j<14; j++){
                f=1;
                for(k=i; k<=j; k++){
                    if(nums[k]<=nums[i-1] || nums[k]<=nums[j+1]) {
                        f=0;
                        break;
                    }
                }
                if(f) cnt++;
            }
        }
        printf("%d %d\n", kase++, cnt);
    }
    return 0;
}
