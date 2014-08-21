    #include <stdio.h>
    #include <stdlib.h>
    #include <map>
    #include <set>

    using namespace std;

    #define max(x,y) ((x>y)?x:y)
    #define INF 1000000000

    #define N 400005
    #define SIZE 1048576

    int tree[SIZE], nElems;

    void update(int index, int v){
        index += nElems ;
        tree[index] = v;
        while(index > 1){
            index >>= 1;
            tree[index] = tree[index << 1] + tree[(index << 1) + 1];
        }
    }

    int count(int node, int b, int e, int i, int j){
        if(i>e || j<b)
            return 0;
        if(b>=i && e<=j)
            return tree[node];
        int p1, p2;

        p1 = count(2*node, b, (b+e)/2, i, j);
        p2 = count(2*node+1, (b+e)/2+1, e, i, j);
        return p1 + p2;
    }

    int count(int i, int j){
        if(j<i)
            return 0;
        return count(1, 0, nElems-1, i, j);
    }

    int last[SIZE];

    int main(){
        int t, n, m, i, q, pow2, maxNM;
        scanf("%d", &t);
        while(t--){
            scanf("%d %d", &n, &m);

            nElems = maxNM = max(n, m);
            pow2=1;
            while(pow2<nElems)pow2 <<= 1;
            nElems = pow2<<1;

            for(i=0; i<=(nElems<<1); i++){
                tree[i]=0;
                last[i]=-1;
            }

            for(i=1; i<=n; i++)update(i+maxNM, 1);

            /*for(i=1; i<=nElems*4; i++)printf("t: %d\n", tree[i]);
            printf("c: %d\n", count(0,2*n));
            printf("c: %d\n", count(0,n-1));*/

            for(i=0; i<m; i++){
                scanf("%d", &q);

                q+=maxNM;
                while(last[q]!=-1){
                    q = last[q];
                }

                update(q, 0);
                printf("%d", count(1, q-1));

                last[q] = maxNM-i;
                update(maxNM-i, 1);

                if(i<m-1)printf(" ");
            }
            printf("\n");
        }
        return 0;
    }
