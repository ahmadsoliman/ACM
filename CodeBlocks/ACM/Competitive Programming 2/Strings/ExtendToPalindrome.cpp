#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <algorithm>


#define INF 1000000000

using namespace std;

char in[100005];

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
    while(scanf("%s", in)>0){
        string s(in);
        string srev(s);
        reverse(srev.begin(), srev.end());

        srev+=s;
        vector<int> z = zfn(srev);
        int palinLen=s.size();
        for(int i=s.size(); i<z.size(); i++){
            if(i+z[i]==z.size()){
                palinLen = i-s.size();
                break;
            }
        }
        for(int i=palinLen-1; i>=0; i--) s+=s[i];
        printf("%s\n", s.c_str());
    }
    return 0;
}
