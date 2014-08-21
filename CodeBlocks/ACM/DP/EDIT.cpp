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

char in[2001], len;

int main(){
    while(scanf("%s", in)>0){
        len = strlen(in);
        int small=0, capital=0;
        for(int i=0; i<len; i++){
            if(i%2==1){
                if(in[i]>='a'&&in[i]<='z') small++;
                else capital++;
            }else{
                if(!(in[i]>='a'&&in[i]<='z')) small++;
                else capital++;
            }
        }
        printf("%d\n", min(small, capital));
    }
    return 0;
}
