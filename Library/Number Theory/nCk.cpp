
final int mod = 1000000007;
int nCk[1010][1010];

int main(){

    memset(nCk, 0, sizeof nCk);
    for(int i=1; i<1010; i++){
        for(int j=0; j<=i; j++){
            if(j==0||j==i) {nCk[i][j]=1; continue;}
            nCk[i][j] = ((ll)nCk[i-1][j-1] + nCk[i-1][j])%mod;
        }
    }


    return 0;
}
