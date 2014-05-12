#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char e[100010], p[100010];
int freq[30], origf[30];

int val(char c){return c-'a';}

int main(){
    int t, i,j,k, n,m, f;
    scanf("%d", &t);
    while(t--){
        scanf("%s", e);
        scanf("%s", p);
        n=strlen(e);
        m=strlen(p);

        memset(freq, 0, sizeof freq);
        memset(origf, 0, sizeof origf);

        for(i=0; i<m; i++){
            freq[val(e[i])]++;
            origf[val(p[i])]++;
        }

        f=1;
        for(j=0; j<26; j++) if(freq[j]!=origf[j]) {f=0; break;}

        if(f) { printf("YES\n"); continue; }

        f=0;
        for(i=1; m+i-1<n; i++){
            freq[val(e[m+i-1])]++;
            freq[val(e[i-1])]--;

            f=1;
            for(j=0; j<26; j++) if(freq[j]!=origf[j]) {f=0; break;}
            if(f) break;
        }

        if(f) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
