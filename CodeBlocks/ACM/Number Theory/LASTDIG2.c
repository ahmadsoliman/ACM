#include <string.h>
#include <stdio.h>
#include <math.h>

long long powmod(long long a, long long b, long long  c){
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

char in[1010];

int main() {
    int t, len;
    long long b;
    scanf("%d", &t);
    while(t--){
        scanf("%s %lld", in, &b);
        len = strlen(in);
        printf("%d\n", powmod(in[len-1]-'0',b,10));
    }
    return 0;
}
