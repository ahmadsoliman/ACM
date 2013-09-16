#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define INF 1000000000

using namespace std;

int compare (const void * a, const void * b)
{
  return ( *(double*)a - *(double*)b );
}

typedef struct trie
{
        int root;
        int words;
        int prefixes;
        struct trie *edges[26];
}trie;

trie * initialize(trie *node)
{
        int i;
        if(node==NULL)
                node=(trie *)malloc(sizeof(trie));
        node->root = 1;
        for(i=0;i<26;i++)
                node->edges[i]=NULL;
        return node;
}

trie * addWord(trie *ver,char *str)
{
        if(str[0]=='\0')
        {
                ver->words=ver->words+1;
                ver-> root = 0;
        }
        else
        {       ver->prefixes=(ver->prefixes)+1;
                char k;
                k=str[0];
                str++;
                int index=k-'a';
                if(ver->edges[index]==NULL)
                {
                        ver->edges[index]=initialize(ver->edges[index]);
                }
                ver->edges[index]=addWord(ver->edges[index],str);
        }

        return ver;
}

int countWords(trie *ver,char *str)
{
        if(str[0]=='\0')
                return ver->words;
        else
        {
                int k=str[0]-'a';
                str++;
                if(ver->edges[k]==NULL)
                        return 0;
                return countWords(ver->edges[k],str);
        }
}

int countPrefix(trie *ver,char *str)
{
        if(str[0]=='\0')
                return ver->prefixes;
        else
        {
                int k=str[0]-'a';
                str++;
                if(ver->edges[k]==NULL)
                        return 0;
                return countPrefix(ver->edges[k],str);
        }
}

char in[100], word[100];
double arr[100], nums[100];

int main(){
    int zero, one, avg;
    int n,m, i,j,k, charc, c, faks;
    long long res;
    while(scanf("%d %d", &n, &m)>0){
        trie *start=NULL;
        start=initialize(start);
        for(i=0; i<n; i++) {
            scanf("%s", in);
            start = addWord(start, in);
        }
        res=0ll;
        while(m--){
            scanf("%d", &charc);
            faks=0;
            for(i=0; i<charc; i++){
                one=-11111111;
				zero=100000000.0;
                for(j=0; j<8; j++) {
                    scanf("%lf", &arr[j]);
                    if(arr[j]>one) one = arr[j];
                    if(arr[j]<zero) zero = arr[j];
                }
                avg=(zero+one)/2;
                c=0;
                for(j=8;j>=1;--j){
					if(arr[j-1]>avg)
                        c+=(int)pow(2.0,8-j);
                }
                word[i]=c;
                if(word[i]<'a'||word[i]>'z') while(1);
            }
            word[charc]='\0';
            if(!faks) res += countPrefix(start, word);
        }
        printf("%lld\n", res);
    }
    return 0;
}
/*
1 2 2 1 1 1 1 2
0.0105 0.0201 0.0205 0.010 0.0099 0.0097 0.0100 0.0199
*/
