#include <stdio.h>

using namespace std;

int gcd(int a, int b, int& x, int& y)
{
  if (a < b) return gcd(b, a, y, x);
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1, y1;
  int g = gcd(b, a % b, x1, y1);
  x = y1;
  y = (x1 - a / b * y1);
  return g;
}

int main(){
    int A,B,D;
    while(scanf("%d %d", &A, &B)>0){
        int X,Y;
        D = gcd(A, B, X, Y);
        printf("%d %d %d\n", X,Y,D);
    }
    return 0;
}
