#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

typedef struct trie{
    char c;
    trie *elems[26];
};

typedef struct trie * ptrie;

ptrie getptrie() {
    ptrie tmp = (ptrie)malloc(sizeof(trie)) ;
    return tmp;
}

char in[50];

ptrie thetrie;

void add(ptrie t, string s, int i){
    if(i==s.size()) return;
    printf("a7a\n");
    if((*t).elems[s[i]-'a']==NULL){
        ptrie t2 = getptrie();
        (*t2).c=s[i];
        for(i=0; i<26; i++) (*t2).elems[i]=NULL;

        (*t).elems[s[i]-'a']=t2;
        add((*t).elems[s[i]-'a'], s, i+1);
    }else{
        add((*t).elems[s[i]-'a'], s, i+1);
    }
}

void traverse(trie *t){
    printf("%c\n", (*t).c);
    for(int i=0; i<26; i++){
        if((*t).elems[i]!=NULL) traverse((*t).elems[i]);
    }
}

int main(){
    int n, m, i,j,k;
    thetrie = getptrie();
    (*thetrie).c = '$';
    for(i=0; i<26; i++) (*thetrie).elems[i]=NULL;

    scanf("%d", &n);
    for(i=0; i<n; i++){
        scanf("%s", in);
        add(thetrie, string(in), 0);
    }
    traverse(thetrie);
    return 0;
}
