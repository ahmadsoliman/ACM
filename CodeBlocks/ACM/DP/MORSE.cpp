#include <stdio.h>
#include <iostream>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

char startchar;
typedef struct trie{
    bool root;
    int words;
    int prefixes;
    struct trie *edges[26];
}trie;

trie * initialize(trie *node){
    int i;
    if(node==NULL)
        node=(trie *)malloc(sizeof(trie));
    node->root = false;
    for(i=0;i<26;i++)
        node->edges[i]=NULL;
    return node;
}

trie * addWord(trie *ver,char *str){
    if(str[0]=='\0'){
        ver->words=ver->words+1;
        ver-> root = true;
    } else{
        ver->prefixes=(ver->prefixes)+1;
        char k=str[0];
        str++;
        int index=k-startchar;
        if(ver->edges[index]==NULL){
            ver->edges[index]=initialize(ver->edges[index]);
        }
        ver->edges[index]=addWord(ver->edges[index],str);
    }
    return ver;
}


void kill(trie *t){
    if(t==NULL) return;
    int i;
    for(i=0; i<26; i++){
        if(t->edges[i]!=NULL){
            kill(t->edges[i]);
        }
    }
    free(t);
}

typedef trie* triep;

int len;
char str[10010], in[50];
map<string, char> morse;
map<pair<int, triep>, ll> dp;
trie *start;

ll recur(int i, trie *t){
    if(i==len) {
        if(t==start) return 1;
        return 0;
    }

    pair<int, triep> state=make_pair(i, t);
    map<pair<int, triep>, ll>::iterator it=dp.find(state);
    if(it!=dp.end()) return it->second;

    map<string, char>::iterator itc;

    ll cnt=0;
    int c;
    string l;
    for(int j=0; j<4; j++){
        if(i+j>=len) break;
        l.push_back(str[i+j]);
        if((itc=morse.find(l))==morse.end()) continue;
        c=(itc->second)-startchar;
        if(t->edges[c]!=NULL) {
            cnt += recur(i+j+1, t->edges[c]);
            if(t->edges[c]->root) cnt+= recur(i+j+1, start);
        }
    }
    return dp[state]=cnt;
}

int main(){
    morse[".-"]='A';morse["-..."]='B';morse["-.-."]='C';morse["-.."]='D';morse["."]='E';morse["..-."]='F';morse["--."]='G';morse["...."]='H';
    morse[".."]='I';morse[".---"]='J';morse["-.-"]='K';morse[".-.."]='L';morse["--"]='M';morse["-."]='N';morse["---"]='O';morse[".--."]='P';
    morse["--.-"]='Q';morse[".-."]='R';morse["..."]='S';morse["-"]='T';morse["..-"]='U';morse["...-"]='V';morse[".--"]='W';morse["-..-"]='X';
    morse["-.--"]='Y';morse["--.."]='Z';

    startchar='A';

    int t, i,j,k, n;
    scanf("%d", &t);
    while(t--){
        scanf("%s", str);
        len = strlen(str);
        scanf("%d", &n);

        kill(start);
        start=NULL;
        start=initialize(start);

        for(i=0; i<n; i++){
            scanf("%s", in);
            addWord(start, in);
        }
        dp.clear();
        printf("%lld\n", recur(0,start));
    }
    return 0;
}

/*

5
.---.--.-.-.-.---...-.---.
6
AT
TACK
TICK
ATTACK
DAWN
DUSK
.---.--.-.-.-
6
AT
TACK
TICK
ATTACK
DAWN
DUSK
.---.--.-.-.-.---...-.---.
6
AT
TACK
TICK
ATTACK
DAWN
DUSK
.---...-.---.
6
AT
TACK
TICK
ATTACK
DAWN
DUSK
.---...-.---..---.--.-.-.-.---.--.-.-.-.---...-.---..---...-.---..---.--.-.-.-.---.--.-.-.-.---...-.---.
6
AT
TACK
TICK
ATTACK
DAWN
DUSK
.--.--.--.--.--
6
HAMADA
BEL
GAN
ZABEEL
AT
ATAT

*/
