#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long mod(long long a, long long b)
{ return (a%b+b)%b; }

int main(){
    long long a,b, aT, bT;
    char s[101];
    scanf("%ld %ld", &aT, &bT);
    scanf("%s", s);
    if(aT==0&&bT==0){
        printf("Yes\n");
        return 0;
    }
    int n = strlen(s);
    int i;
    for(i=0, a=0, b=0; i<n; i++){
        switch(s[i]){
            case 'U': b++;break;
            case 'D': b--;break;
            case 'L': a--;break;
            case 'R': a++;break;
        }
        if(aT==a&&bT==b){
            printf("Yes\n");
            return 0;
        }
    }
    if(mod(aT,a)==0&&mod(bT,b)==0&&(a+b!=0||mod(aT+bT, a+b)==0))
        printf("Yes\n");
    else{
        if(a>aT||b>bT||a==0||b==0){
            printf("No\n");
            return 0;
        }
        for(i=0, a=(aT/a)*a, b=(bT/b)*b; i<n; i++){
            switch(s[i]){
                case 'U': b++;break;
                case 'D': b--;break;
                case 'L': a--;break;
                case 'R': a++;break;
            }
            if(aT==a&&bT==b){
                printf("Yes\n");
                return 0;
            }
        }
        printf("No\n");
    }
    return 0;
}
