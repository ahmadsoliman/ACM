#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

char startchar='a';
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

int len;
string res, curWord;

void recur(trie *t, string s, string cur, bool looking, int curlen){
    if(looking){
        if(s=="") {
            recur(t, s, cur, false, curlen);
            return;
        }
        if(t->edges[s[0]-'a']==NULL){
            recur(t, s, cur, false, curlen);
        }else{
            if(t->edges[s[0]-'a']==NULL || (t->prefixes>1 && t->edges[s[0]-'a']->prefixes==1)) recur(t, s, cur, false, curlen);
            recur(t->edges[s[0]-'a'], s.substr(1), cur+s[0], looking, curlen+1);
        }
    }else{
        if(curlen<len) return;
        if(t->words && curWord!=cur){
            if(curlen>len){
                len=curlen;
                res=cur;
            }else{
                string rt=res, curt=cur;
                reverse(rt.begin(), rt.end());
                reverse(curt.begin(), curt.end());
                if(curt<rt) res=cur;
            }
        }
        for(int i=0; i<26; i++){
            if(t->edges[i]!=NULL){
                recur(t->edges[i], s, cur+(char)('a'+i), looking, curlen);
            }
        }
    }
}

int main(){
    trie *t=NULL;
    t=initialize(t);

    char s[50], e[1];
    while(gets(s)){
        int curlen=strlen(s);
        if(curlen==0) break;
        reverse(s, s+curlen);
        t = addWord(t, s);
    }

    while(gets(s)){
        int curlen=strlen(s);
        if(curlen==0) break;
        reverse(s, s+curlen);

        len=0;
        curWord=string(s);
        res="";
        recur(t, curWord, "", true, 0);
        reverse(res.begin(), res.end());
        printf("%s\n", res.c_str());
    }


    return 0;
}
