#define m(x,y) ((x>y)?x:y)
#define s(b) scanf("%d",&b)
int main(){int t,n,i,j,a,d[102][102],x;s(t);while(t--){memset(d,0,sizeof d);x=0;s(n);for(i=0;i<n;i++)for(j=0;j<=i;j++){s(a);d[i+1][j+1]=a+m(d[i][j+1],d[i][j]);x=m(x,d[i+1][j+1]);}printf("%d\n",x);}}
