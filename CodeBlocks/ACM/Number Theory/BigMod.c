#include <stdio.h>

int powmod(int a, int b, int c){
  long long result = 1;
  long long base = a;
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
    int B, P, M;
    while(scanf("%d", &B)>0){
        scanf("%d", &P);
        scanf("%d", &M);
        printf("%d\n", powmod(B, P, M));
    }
    return 0;
}
