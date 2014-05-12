#include <stdio.h>
#include <string.h>
#include <math.h>

int powmod(int a, int b, int  c){
  int result = 1;
  int base = a;
  while (b){
    if (b & 1){
      result = result*base % c;
    }
    b >>= 1;
    base = base*base % c;
  }
  return result;
}

int main(){
    int n,m,k, i, cur, cnt=0;
    scanf("%d %d %d", &n, &m, &k);
    while(n--){
        scanf("%d", &cur);
        if(powmod(cur, m, k)==0) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
