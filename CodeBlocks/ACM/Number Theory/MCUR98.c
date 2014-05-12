#define M 1000000
int f[M+200];
int main(){
    int i,j,k, s;
    for(i=1; i<M; i++){
        s=j=i;
        while(j) {s+=j%10; j/=10;}
        f[s]=1;
    }
    for(i=1; i<M; i++)if(!f[i])printf("%d\n", i);
    return 0;
}
