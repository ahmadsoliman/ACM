#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>

using namespace std;

char in[1000006];
string s;

vector<int> zfn(string s){
    int L = 0, R = 0, n=s.size();
    vector<int> z(n);

    for (int i = 1; i < n; i++) {
      if (i > R) {
        L = R = i;
        while (R < n && s[R-L] == s[R]) R++;
        z[i] = R-L; R--;
      } else {
        int k = i-L;
        if (z[k] < R-i+1) z[i] = z[k];
        else {
          L = i;
          while (R < n && s[R-L] == s[R]) R++;
          z[i] = R-L; R--;
        }
      }
    }
    return z;
}

int main(){
    scanf("%s", in);
    s=in;

    vector<int> z = zfn(s);

    int maxv=0, lastf=0;
    for(int i=z.size()-1; i>0; i--){
        if(z[i]>=lastf) maxv=max(maxv, lastf);
        if(i+z[i]==z.size()) lastf=z[i];
    }
    if(maxv==0) printf("Just a legend\n");
    else printf("%s\n", s.substr(0, maxv).c_str());

    return 0;
}
