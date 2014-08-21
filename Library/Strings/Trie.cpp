#include<stdio.h>
#include<malloc.h>
#include <iostream>
using namespace std;

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

int countWords(trie *ver,char *str){
    if(str[0]=='\0')
        return ver->words;
    else{
        int k=str[0]-startchar;
        str++;
        if(ver->edges[k]==NULL)
            return 0;
        return countWords(ver->edges[k],str);
    }
}

int countPrefix(trie *ver,char *str){
    if(str[0]=='\0')
        return ver->prefixes;
    else{
        int k=str[0]-startchar;
        str++;
        if(ver->edges[k]==NULL)
            return 0;
        return countPrefix(ver->edges[k],str);
    }
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

int main()
{
    int t, n;
    char s[11];
    cin >> t;
    while(t--){
        cin >> n;
        trie *start=NULL;
        start=initialize(start);
        while(n--){
            scanf("%s", s);
            start = addWord(start, s);
        }
    }

}
