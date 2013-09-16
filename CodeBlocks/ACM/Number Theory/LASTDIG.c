#include <string.h>
#include <stdio.h>
#include <math.h>

int powmod2(int a, int b, int  c){
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

int main() {
    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &a, &b);
        printf("%d\n", powmod2(a,b,10));
    }
    return 0;
}
