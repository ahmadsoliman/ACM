#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>

#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

string el[1000]={"h", "he",
                "li", "be", "b", "c", "n", "o", "f", "ne",
                "na", "mg", "al", "si", "p", "s", "cl", "ar",
                "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr",
                "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe",
                "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn",
                "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv",
                "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu",
                "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};
set<string> ss;

char s[100000];
int len, dp[50005];

int recur(int i){
    if(i==len) return 1;

    if(dp[i]!=-1)  return dp[i];

    string cur(" ");
    cur[0]=s[i];

    if(ss.find(cur)!=ss.end() && recur(i+1)) return dp[i]=1;
    if(i==len-1) return dp[i]=0;
    cur = "  ";
    cur[0]=s[i];
    cur[1]=s[i+1];

    if(ss.find(cur)!=ss.end() && recur(i+2)) return dp[i]=1;
    return dp[i]=0;
}

int main(){
    int t, i,j,k;

    for(i=0; i<131; i++){
        ss.insert(el[i]);
    }
    scanf("%d", &t);
    while(t--){
        scanf("%s", s);
        len = strlen(s);

        memset(dp, -1, sizeof dp);
        if(recur(0)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
