#include <stdio.h>
#include <string.h>

struct number { int digits;
                int values[105];};

void print(struct number *what) {
  int i;
  if (!what->digits) { printf("0"); exit(0); }
  printf("%d",what->values[what->digits-1]);
  for (i=what->digits-2; i>=0; i--) printf("%03d",what->values[i]);
  }

void unit(struct number *result) {
  result->digits=1;
  result->values[0]=1;
  }
void addbig(struct number *result, struct number *what) {
  int k;
  while (result->digits<what->digits) result->values[result->digits++]=0;
  for (k=0; k<what->digits; k++) {
    if (k&&(result->values[k-1]>=1000)) {
      result->values[k]+=result->values[k-1]/1000;
      result->values[k-1]%=1000;
      }
    result->values[k]+=what->values[k];
    }
  if (!k) return;
  for (; (result->values[k-1]>=1000)&&(k<result->digits); k++) {
    result->values[k]+=result->values[k-1]/1000;
    result->values[k-1]%=1000;
    }
  if (result->values[k-1]>=1000) {

    result->values[k]=result->values[k-1]/1000;
    result->values[k-1]%=1000;
    result->digits++;
    }
  }

void zero(struct number *result) {
  result->digits=0;
  }

void mul(struct number *result, struct number *what) {
  int i,j;
  struct number aux,what2;
  zero(&what2); addbig(&what2,result); // copy
  zero(result);
  for (i=0; i<what->digits; i++) {
    for (j=0; j<what2.digits; j++) aux.values[i+j]=what->values[i]*what2.values[j];
    for (j=0; j<i; j++) aux.values[j]=0;
    aux.digits=what2.digits+i;
    addbig(result,&aux);
    }
  }

int eq(struct number *a, struct number *b){
    if(&a->digits!=&b->digits) return 0;
    int i;
    for(i=0; i<a->digits; i++) if(a->values[i]!=b->values[i]) return 0;
    return 1;
}

#define big number

char a[10005], b[105];

big dp[10005][105];
int aC, bC;

struct big recur(int i, int j){
    if(j==bC){
        struct big one;
        unit(&one);
        return one;
    }
    if(i==aC){
        struct big zero;
        zero(&zero);
        return zero;
    }
    if(!(dp[i][j].digits==1 && dp[i][j].values[0]==-1))
        return dp[i][j];

    struct big c = recur(i+1,j);
    if(eq(a[i],b[j]))
        addbig(&c, &recur(i+1, j+1));
    return dp[i][j] = c;
}


int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%s", a);
        scanf("%s", b);

        memset(dp, -1, sizeof dp);

        aC = strlen(a);
        bC = strlen(b);

        print(&recur(0,0));
    }
    return 0;
}
