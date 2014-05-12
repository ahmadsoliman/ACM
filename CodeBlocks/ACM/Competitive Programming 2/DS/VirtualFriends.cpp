#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

#define MAX_SIZE 200005

struct disjoint_set{
    int arr[MAX_SIZE+1], found[MAX_SIZE+1];

    disjoint_set(){
        memset(arr, -1, sizeof arr);
        memset(found, 0, sizeof found);
    }

    void set(int e){
        arr[e]=-1;
        found[e]=1;
    }

    int find(int e){
        if(arr[e]<0) return e;
        int r=find(arr[e]);
        arr[e]=r;
        return r;
    }

    int size(int e){
        return -1*arr[find(e)];
    }

    void union_set(int e1, int e2){
        if(!found[e1]) set(e1);
        if(!found[e2]) set(e2);
        int r1=find(e1), r2=find(e2);
        int s1=-1*arr[r1], s2=-1*arr[r2];
        if(r1==r2) return;
        if(s1>s2) arr[r1]+=arr[r2], arr[r2]=r1;
        else arr[r2]+=arr[r1], arr[r1]=r2;
    }
/*
    void print(int e){
        int ds=find(e);

        for(int i=0; i<MAX_SIZE; i++){
            if(find(i)==ds) printf("%d ", i);
        }
        printf("\n");
    }
*/
};

char n1[100], n2[100];
map<string, int> m;
disjoint_set ds;
string ns1, ns2;

int main(){
    int t, n, c, i,j;
    scanf("%d", &t);
    while(t--){
        m.clear();

        ds=disjoint_set();
        scanf("%d", &n);
        c=0;
        for(i=0; i<n; i++){
            scanf("%s %s", n1, n2);
            ns1=string(n1);
            ns2=string(n2);
            if(m.find(ns1)==m.end()) m[ns1]=c++;
            if(m.find(ns2)==m.end()) m[ns2]=c++;
            ds.union_set(m[ns1], j=m[ns2]);
            printf("%d\n", ds.size(j));
        }
    }
    return 0;
}
