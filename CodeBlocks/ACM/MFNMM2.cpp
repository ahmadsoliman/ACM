#include <string>
#include <stdio.h>

#define MAX 5005

using namespace std;

int main(){
    int n, m, nA, nB, i, j, k;

    char a[MAX], b[MAX];
    gets(a);
    gets(b);


    string x(a), y(b), s;
    nA = x.size();
    nB = y.size();
    x+=x;
    y+=y;
    int palin=0;
    for(i=0; i<nA; i++){
        for(j=0; j<nB; j++){
            palin = 1;
            s = x.substr(i, nA);
            s += y.substr(j, nB);
            for(k=0; k<s.size()/2; k++){
                if(s[k]!=s[s.size()-k-1]){
                    palin=0;
                    break;
                }
            }
            if(palin)break;
        }
        if(palin)break;
    }
    if(palin)printf("Yes\n%d %d\n", i+1, j+1);
    else printf("No\n");
    return 0;
}
