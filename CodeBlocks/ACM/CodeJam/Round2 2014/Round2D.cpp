#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <map>
#include <algorithm>

using namespace std;

char in[100];

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

int cntNodes(trie *t){
    if(t==NULL) return 0;
    int cnt = 1;
    for(int i=0; i<26; i++) cnt += cntNodes(t->edges[i]);
    return cnt;
}

int maxVal, maxCnt;

int calc(vector<string> words){
    trie *start=NULL;
    start=initialize(start);
    for(int i=0; i<words.size(); i++) start = addWord(start, (char*)words[i].c_str());
    int v= cntNodes(start);
    kill(start);
    return v;
}

vector<string> origWords;

void recur(vector<int> words, vector<vector<int> > combs, int n){
    if(n==0 || (words.size()==0&&n==1)){
        if(words.size()!=0) return;
        int val=0;
        for(int i=0; i<combs.size(); i++){
            vector<string> s;
            for(int j=0; j<combs[i].size(); j++) s.push_back(origWords[combs[i][j]]);
            val += calc(s);
        }
        if(val>maxVal) maxVal = val, maxCnt=0;
        else if(val==maxVal) maxCnt++;
        return;
    }
    if(words.size()<n-1) return;
    if(words.size()==0) return;

    if(combs.size()==0) combs.push_back(vector<int>());
    if(combs.back().size()>0){
        vector<vector<int> > tmp = combs;
        tmp.push_back(vector<int>());
        recur(words, tmp, n-1);
    }
    for(int i=0; i<words.size(); i++){
        vector<vector<int> > tmp = combs;
        if(tmp.back().size()>0 && words[i]<tmp.back().back()) continue;
        tmp.back().push_back(words[i]);
        vector<int> tmpw = words;
        tmpw.erase(tmpw.begin()+i);
        recur(tmpw, tmp, n);
    }
}

int main(){
    freopen("D-small.in","r",stdin);
    freopen("D-small.out", "w", stdout);

    startchar = 'A';
    int t, m,n, kase=1;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &m, &n);

        vector<string> words;
        vector<int> left;
        for(int i=0; i<m; i++) {
            scanf("%s", in);
            words.push_back(in);
            left.push_back(i);
        }

        maxVal = 0;
        origWords = words;

        recur(left, vector<vector<int> >(), n);
        printf("Case #%d: %d %d\n", kase++, maxVal, maxCnt+1);
    }
    return 0;
}
