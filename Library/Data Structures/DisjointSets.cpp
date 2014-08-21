#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

#define MAX_SIZE 100000

struct disjoint_set{
    int arr[MAX_SIZE+1], found[MAX_SIZE+1], setscnt;

    disjoint_set(){
        memset(arr, -1, sizeof arr);
        memset(found, 0, sizeof found);
        setscnt=MAX_SIZE;
    }

    disjoint_set(int n){
        memset(arr, -1, sizeof arr);
        memset(found, 0, sizeof found);
        setscnt=n;
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
        int r1=find(e1), r2=find(e2), s1=-1*arr[r1], s2=-1*arr[r2];
        if(r1==r2) return;
        setscnt--;
        if(s1>s2) arr[r1]+=arr[r2], arr[r2]=r1;
        else arr[r2]+=arr[r1], arr[r1]=r2;
    }

    void print(int e){
        int ds=find(e);

        for(int i=0; i<MAX_SIZE; i++){
            if(find(i)==ds) printf("%d ", i);
        }
        printf("\n");
    }
};

int main(){
    disjoint_set ds;

    ds.union_set(1, 2);
    ds.union_set(1, 3);

    ds.union_set(4, 5);
    ds.union_set(5, 6);

    ds.union_set(8, 7);
    ds.union_set(7, 9);

    ds.print(5);
    printf("%d\n", ds.size(7));

    ds.union_set(5, 9);

    printf("%d\n", ds.size(7));
    ds.print(5);

    return 0;
}
