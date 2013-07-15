#include <stdio.h>
#include <string.h>

char s[505];
int last[26];

int main(){
    int t, kase=1,index , n, k, i, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%d", &k);
        scanf("%s", s);
        memset(last, -1, sizeof last);
        c = 0;
        for(i=0; i<n; i++){
            index = s[i]-'A';
            if(last[index]==-1)
                last[index] = i;
            else{
                if(i-last[index]<=k)
                    c++;
                last[index] = i;
            }
        }
        printf("Case %d: %d\n", kase++, c);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>

char s[505];
int last[26];

int main(){
    int t, kase=1,index , n, k, i, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%d", &k);
        scanf("%s", s);
        memset(last, -1, sizeof last);
        c = 0;
        for(i=0; i<n; i++){
            index = s[i]-'A';
            if(last[index]==-1)
                last[index] = i;
            else{
                if(i-last[index]<=k)
                    c++;
                last[index] = i;
            }
        }
        printf("Case %d: %d\n", kase++, c);
    }
    return 0;
}#include <stdio.h>
#include <string.h>

char s[505];
int last[26];

int main(){
    int t, kase=1,index , n, k, i, c;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        scanf("%d", &k);
        scanf("%s", s);
        memset(last, -1, sizeof last);
        c = 0;
        for(i=0; i<n; i++){
            index = s[i]-'A';
            if(last[index]==-1)
                last[index] = i;
            else{
                if(i-last[index]<=k)
                    c++;
                last[index] = i;
            }
        }
        printf("Case %d: %d\n", kase++, c);
    }
    return 0;
}
