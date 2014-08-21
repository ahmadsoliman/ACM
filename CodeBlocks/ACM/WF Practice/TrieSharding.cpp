#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int mod = 1000000007;
int nCk[1010][1010];

char startchar='A';
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
        ver->prefixes=(ver->prefixes)+1;
        ver->words=ver->words+1;
        ver-> root = true;
    } else{
        ver->prefixes=(ver->prefixes)+1;
        char k;
        k=str[0];
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

vi tree[1000010];
int n, K[1000010], W[1000010], f;

int constructTree(trie *t, int node){
    if(t==NULL) return node+1;
    K[node] = min(t->prefixes, n);
    int lastnode=node+1;
    for(int i=0; i<26; i++){
        if(t->edges[i]!=NULL){
            tree[node].push_back(lastnode);
            lastnode = constructTree(t->edges[i], lastnode);
        }
    }
    if(lastnode!=node+1 && t->root) tree[node].push_back(lastnode++);
    return lastnode;
}

int OC[20000], Count[20000];

int recur(int node){
    if(tree[node].size()==0) return W[node]=1;

    int c2=1;
    vi Ks;
    for(int i=0; i<tree[node].size(); i++) {
        recur(tree[node][i]);
        Ks.push_back(K[tree[node][i]]);
        c2 = ((ll)c2*W[tree[node][i]])%mod;
    }

    for(int i=1; i<=K[node]; i++){
        OC[i]=1;
        for(int j=0; j<Ks.size(); j++) OC[i] = ((ll)OC[i]*nCk[i][Ks[j]])%mod;
    }

    Count[1]=OC[1];
    for(int i=2; i<=K[node]; i++){
        Count[i] = OC[i];
        for(int j=1; j<i; j++){
            Count[i] = ((Count[i]-((ll)Count[j]*nCk[i][i-j])%mod)+mod)%mod;
        }
    }
    return W[node]=((ll)Count[K[node]]*c2)%mod;
}

char s[1000];

int main(){
    freopen("trie.in","r",stdin);
    freopen("trie.out", "w", stdout);

    memset(nCk, 0, sizeof nCk);
    for(int i=1; i<1010; i++){
        for(int j=0; j<=i; j++){
            if(j==0||j==i) {nCk[i][j]=1; continue;}
            nCk[i][j] = ((ll)nCk[i-1][j-1] + nCk[i-1][j])%mod;
        }
    }

    int t, kase=1, m;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);

        for(int i=0; i<1000*m; i++) tree[i].clear(), K[i]=W[i]=0;

        trie *start=NULL;
        start=initialize(start);
        for(int i=0; i<m; i++){
            scanf("%s", s);
            start = addWord(start, s);
        }

        int nodes = constructTree(start, 0);

        int maxNodes=0;
        for(int i=0; i<nodes; i++) {
            maxNodes=((ll)maxNodes+K[i])%mod;
            K[i]=((K[i]==0)?1:K[i]);
        }

        printf("Case #%d: %d %d\n", kase++, maxNodes, recur(0));

        //kill(start);
    }

    return 0;
}





