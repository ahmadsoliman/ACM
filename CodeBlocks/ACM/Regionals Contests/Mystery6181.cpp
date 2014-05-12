#include <stdio.h>
#include <string.h>
#include <string>

using namespace std;

char s[1000], in[10000];

int mod(int n, int m){
    n%=m;
    if(n<0) n+=m;
    return n;
}

string res;

int main(){
    int t, i,j,k, d, n, m, sh, ind, kase=1;
    sscanf(gets(in), "%d", &t);
    while(t--){
        sscanf(gets(in), "%d", &d);
        gets(s);

        m=strlen(s);

        sscanf(gets(in), "%d", &n);
        ind=0;
        res="";

        gets(in);

        char *p=strtok(in, " ");
        for(i=0; i<n; i++){
            sscanf(p, "%d", &sh);
            ind=mod(ind+sh, m);
            res.push_back(s[ind]);
            p=strtok(NULL, " ");
        }
        printf("%d %s\n", kase++, res.c_str());
    }
    return 0;
}
/*
7
1
MAC
3
1 1 1
2
IW2C0NP3OS 1RLDFA
22
0 3 3 -3 7 -8 2 7 -4 3 8 7 4 1 1 -4 5 2 5 -6 -3 -4
3
G.IETSNPRBU
17
2 4 5 -6 -1 -3 -2 -4 -4 1 -1 5 -3 4 1 -2 4
4
PIBN MRDSYEO
16
-4 4 -1 4 5 3 -5 4 -3 -3 -2 -5 -5 -3 1 3
5
D^obV@k"W*B&#]4!NcF$'lj%(d6XG5fi<Hxz7)2Lt~=8aQuvh}r_m+C9eI`-.>EwYyngZRsJKpqO{[\U|MPS,;T?031/A
93
-1 11 44 39 -31 -44 10 5 24 14 1 -33 42 28 -34 7 -37 24 14 3 -7 18 4 19 37 4 20 2 41 -42 18 15 -3 10 7 12 -11 -41 14 8 31 -26 37 -19 -17 -9 -16 15 31 14 29 -22 1 -24 20 -30 6 1 16 -29 31 -30 6 17 -43 -10 7 7 4 -22 10 -2 15 13 14 2 6 -17 34 -27 28 29 -28 2 33 -13 -15 6 -31 24 41 29 26
6
I
1
0
7
I
13
0 0 0 0 0 0 0 0 0 0 0 0 0
*/