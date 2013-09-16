#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

string steps[10010];
char in[1000010];

#define INF 1000000000

int main(){
    int ok, e1,e2,e3,e4,e5, c, hasdip, hastwirl, hashop, n, i, j, k, arr[5];
    char * pch;
    while(gets(in)!=NULL){
        pch = strtok (in," ");
        i=0;
        while (pch != NULL) {
            steps[i++]=string(pch);
            pch = strtok (NULL, " ");
        }
        n=i;

        e1=e2=e3=e4=e5=1;
        hashop=hastwirl=hasdip=0;
        for(i=0; i<n; i++){
            if(steps[i]=="dip"){
                hasdip=1;
                if((i<n-1&&steps[i+1]=="twirl")||(i>0&&steps[i-1]=="jiggle")||(i>1&&steps[i-2]=="jiggle")) continue;
                steps[i]="DIP";
                e1=0;
            } else if(steps[i]=="hop") hashop=1;
            else if(steps[i]=="twirl") hastwirl=1;
        }
        if(n<3||!(steps[n-1]=="clap"&&steps[n-2]=="stomp"&&steps[n-3]=="clap")) e2=0;
        if(hastwirl&&!hashop) e3=0;
        if(steps[0]=="jiggle") e4=0;
        if(!hasdip) e5=0;
        arr[0]=e1;arr[1]=e2;arr[2]=e3;arr[3]=e4;arr[4]=e5;

        c=0;
        ok=1;
        for(i=0; i<5; i++) {
            ok&=arr[i];
            c+=!arr[i];
        }
        k=--c;

        if(ok){
            printf("form ok:", in);
            for(i=0; i<n; i++) printf(" %s", steps[i].c_str());
            printf("\n");
        }else{
            if(c>0) printf("form errors ");
            else printf("form error ");

            for(i=0; i<5; i++){
                if(arr[i]==0){
                    if(c==k) printf("%d", i+1);
                    else if(c==0) printf(" and %d", i+1);
                    else printf(", %d", i+1);
                    c--;
                }
            }
            printf(":");
            for(i=0; i<n; i++) printf(" %s", steps[i].c_str());
            printf("\n");
        }
    }

    return 0;
}
