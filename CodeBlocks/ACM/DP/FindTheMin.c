#include <stdio.h>

int m[100005], found[100005];

int main(){
    int t,k,n,b,c,r,i,foundN,caseNum=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &k);
        scanf("%d %d", &m[0], &b, &c, &r);
        found[m[0]]=1;
        for(i=1; i<k; i++){
            m[i]=(b*m[i-1]+c)%r;
            found[m[i]]=1;
        }
        //n-=k+1;
        for(i=0; i<k; i++){
            if(!found[i]){
                if(n==0){
                    foundN=i;
                    break;
                }
                n--;
            }
        }
        if(n>0)
            foundN=n+k;
        printf("Case #%d: %d\n", caseNum++, n);
    }
}
