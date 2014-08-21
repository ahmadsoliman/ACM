#include <stdio.h>
#include <vector>
#include <string>
#include <string.h>

#define min(x,y) ((x<y)?x:y)

using namespace std;


int z[1005];
void Zfunction(string s) {
    for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
}

vector<int> KMP(string s, string k){
    vector<int> T(k.size()  + 1, -1);
    int i;
    for(i=1; i<=k.size(); i++){
        int pos = T[i-1];
        while(pos != -1 && k[pos] != k[i-1]) pos = T[pos];
        T[i] = pos + 1;
    }

    vector<int> matches;
    int sp=0, kp=0;
    while(sp< s.size()){
        while(kp != -1 && (kp == k.size() || k[kp] != s[sp])) kp = T[kp];
        kp++;
        sp++;
        if(kp == k.size()) matches.push_back(sp - k.size());
    }
    return matches;
}

int main(){
    int t, i, j;
    scanf("%d", &t);
    while(t--){
        char a[1005];
        scanf("%s", a);
        string s(a);

        string res;
        res = "";
        int start = 0, end = 0, len = 0;
        for (int j = 0; j < s.length(); j++) {
            memset(z, 0, sizeof z);
            Zfunction(s.substr(j));
            for (int k = 0; k < s.size()-j; k++) {
                //printf("%d\n", z[k]);
                //printf("%s", s.substr(j, j+z[k]).c_str());
                if (z[k] >= len) {
                    if(z[k]==len && s.substr(start,end).compare(s.substr(j, j+z[k]))<0){
                        continue;
                    }
                    start = j;
                    end = z[k];
                    len = z[k];
                }
            }
        }
        res = s.substr(start, end);
        if (len == 0) {
            printf("No repetitions found!\n");
        } else {
            printf("%s %d\n", res.c_str(), KMP(s, res).size());
        }
    }
    return 0;
}
