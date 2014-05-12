#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <math.h>

using namespace std;

char in[10000005], op;

int main(){
    int i,j,k, kase=1, a, b, c, len;
    while(scanf("%s", in)>0){
        if(in[0]=='.') return 0;
        len=strlen(in);

        a=0;
        for(i=0; i<len; i++){
            if(in[i]>='0' && in[i]<='9') a+=in[i]-'0', a%=9;
            else break;
        }

        op=in[i++];

        b=0;
        for(; i<len; i++){
            if(in[i]>='0' && in[i]<='9') b+=in[i]-'0', b%=9;
            else break;
        }

        i++;

        c=0;
        for(; i<len; i++){
            if(in[i]>='0' && in[i]<='9') c+=in[i]-'0', c%=9;
            else break;
        }

        if(op=='+'){
            if((a+b)%9==c%9) printf("%d. PASS\n", kase++);
            else printf("%d. NOT!\n", kase++);
        }else {
            if((a*b)%9==c%9) printf("%d. PASS\n", kase++);
            else printf("%d. NOT!\n", kase++);
        }
    }
    return 0;
}
