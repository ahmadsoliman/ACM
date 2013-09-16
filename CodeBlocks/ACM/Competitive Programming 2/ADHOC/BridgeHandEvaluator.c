#include <stdio.h>
#include <string.h>

#define max(x,y) ((x>y)?x:y)

int main(){
    int i,j, nS[4], stopped[4], allStopped, maxN, score4, score7, sn[13];
    char v[13], s[13], maxSuit, in[2];
    while(scanf("%s", in)>0){

        memset(stopped, 0, sizeof stopped);
        memset(nS, 0, sizeof nS);
        memset(sn, 0, sizeof sn);

        for(i=0; i<13; i++) {
            if(i>0) scanf("%s", in);
            v[i]=in[0]; s[i]=in[1];
            switch(s[i]){
                case 'S': nS[0]++; sn[i]=0; break;
                case 'H': nS[1]++; sn[i]=1; break;
                case 'D': nS[2]++; sn[i]=2; break;
                case 'C': nS[3]++; sn[i]=3; break;
            }
        }

        maxN = max(nS[0], max(nS[1], max(nS[2], nS[3])));
        if(maxN==nS[0]) maxSuit='S';
        else if(maxN==nS[1]) maxSuit='H';
        else if(maxN==nS[2]) maxSuit='D';
        else if(maxN==nS[3]) maxSuit='C';

        score4 = score7 = 0;
        for(i=0; i<13; i++) {
            switch(v[i]){
                case 'A': score4+=4; stopped[sn[i]]=1; break;
                case 'K': score4+=3; if(nS[sn[i]]<2) score4--; if(nS[sn[i]]>1) stopped[sn[i]]=1; break;
                case 'Q': score4+=2; if(nS[sn[i]]<3) score4--; if(nS[sn[i]]>2) stopped[sn[i]]=1; break;
                case 'J': score4+=1; if(nS[sn[i]]<4) score4--; break;
                default: continue;
            }
        }
        score7 = score4;
        allStopped=1;
        for(i=0; i<4; i++){
            if(nS[i]==2) score7+=1;
            else if(nS[i]==1 || nS[i]==0) score7+=2;
            allStopped &= stopped[i];
        }

        if(allStopped && score4>=16){
            printf("BID NO-TRUMP\n");
        }else if(score7>=14) {
            printf("BID %c\n", maxSuit);
        } else{
            printf("PASS\n");
        }
    }
    return 0;
}
