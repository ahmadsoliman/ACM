#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

#include <iostream>
using namespace std;

const int N = 333;

struct BigInteger {
    int length;
    int digit[N];

    BigInteger(): length(0) {
        memset(digit, 0, sizeof(digit));
    }

    const int &operator[](int i) const {
        return digit[i];
    }

    int &operator[](int i) {
        return digit[i];
    }
};

istream &operator >>(istream &in, BigInteger &a) {
    string buffer;
    in >> buffer;
    a.length = ((int)buffer.size() + 3) >> 2;
    for (int i = 0; i < (int)buffer.size(); ++ i) {
        int &memory = a[((int)buffer.size() - i - 1) >> 2];
        memory = memory * 10 + buffer[i] - '0';
    }
    return in;
}

ostream &operator <<(ostream &out, BigInteger &a) {
    out << a[a.length - 1];
    for (int i = a.length - 2; i >= 0; -- i) {
        for (int j = 1000; j >= 10; j /= 10) {
            if (a[i] < j) {
                out << 0;
            }
        }
        out << a[i];
    }
    return out;
}

bool operator<(const BigInteger &a, const BigInteger &b) {
    if (a.length == b.length) {
        for (int i = a.length - 1; i >= 0; -- i) {
            if (a[i] != b[i]) {
                return a[i] < b[i];
            }
        }
        return false;
    }
    return a.length < b.length;
}

BigInteger operator*(const BigInteger &a, const BigInteger &b) {
    BigInteger c;
    for (int i = 0; i < a.length; ++ i) {
        int delta = 0;
        for (int j = 0; j <= b.length; ++ j) {
            delta += a[i] * b[j] + c[i + j];
            c[i + j] = delta % 10000;
            delta /= 10000;
        }
    }
    c.length = a.length + b.length;
    while (c.length > 0 && c[c.length - 1] == 0) {
        c.length --;
    }
    return c;
}


BigInteger powmod2(const BigInteger &a, const BigInteger &b, const BigInteger &c){
  BigInteger result; result.length=21;
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


long long ans[21];
BigInteger ans2[21];

int main(){
    int t;
    long long n,r, i,j;
    scanf("%d", &t);

    ans[1]=1;ans[2]=9; ans[3]=89; ans[4]=89; ans[5]=589; ans[6]=3089; ans[7]=3089;
    for(n=8; n<21; n++){

    }

    while(t--){
        scanf("%d", &r);
        printf("%lld\n", ans[r]);
    }
    return 0;
}
