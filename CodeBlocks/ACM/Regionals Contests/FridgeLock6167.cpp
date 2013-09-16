#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdlib.h>
#include <algorithm>

using namespace std;

#define MAX_N 10                            // adjust this value as needed
struct AugmentedMatrix { double mat[MAX_N][MAX_N + 1]; };
struct ColumnVector { double vec[MAX_N]; };

ColumnVector GaussianElimination(int N, AugmentedMatrix Aug) {
  // input: N, Augmented Matrix Aug, output: Column vector X, the answer
  int i, j, k, l; double t;

  for (i = 0; i < N - 1; i++) {            // the forward elimination phase
    l = i;
    for (j = i + 1; j < N; j++)       // which row has largest column value
      if (fabs(Aug.mat[j][i]) > fabs(Aug.mat[l][i]))
        l = j;                                       // remember this row l
    // swap this pivot row, reason: minimize floating point error
    for (k = i; k <= N; k++)            // t is a temporary double variable
      t = Aug.mat[i][k], Aug.mat[i][k] = Aug.mat[l][k], Aug.mat[l][k] = t;
    for (j = i + 1; j < N; j++)     // the actual forward elimination phase
      for (k = N; k >= i; k--)
        Aug.mat[j][k] -= Aug.mat[i][k] * Aug.mat[j][i] / Aug.mat[i][i];
  }

  ColumnVector Ans;                          // the back substitution phase
  for (j = N - 1; j >= 0; j--) {                         // start from back
    for (t = 0.0, k = j + 1; k < N; k++) t += Aug.mat[j][k] * Ans.vec[k];
    Ans.vec[j] = (Aug.mat[j][N] - t) / Aug.mat[j][j]; // the answer is here
  }
  return Ans;
}

int vals[11][55], len[11];
char in[1000];

int main() {
    int i,j, tmp, k,n, flag;
    double d, tmpd;
    while(sscanf(gets(in), "%d", &k)>0){
        if(k==0) return 0;
        for(i=0; i<k; i++){
            gets(in);
            len[i]=0;
            char *pch = strtok(in, " ");
            while(pch!=NULL){
                sscanf(pch, "%d", &vals[i][len[i]++]);
                pch = strtok(NULL, " ");
            }
        }
        AugmentedMatrix Aug;
        for(i=0; i<k; i++){
            sort(vals[i], vals[i]+len[i]);
            gets(in);
            char *pch = strtok(in, " ");
            for(j=0; j<k; j++){
                sscanf(pch, "%d", &tmp);
                Aug.mat[i][j]=tmp;
                pch = strtok(NULL, " ");
            }
            pch = strtok(NULL, " ");
            sscanf(pch, "%d", &tmp);
            Aug.mat[i][j]=tmp;
        }

        ColumnVector X = GaussianElimination(k, Aug);

        for(i=0; i<len[0]; i++){
            d = X.vec[0]/vals[0][i];
            flag=1;
            for(j=1; j<k; j++){
                tmpd = d*X.vec[j];
                if(fabs(tmpd - (int)tmpd)>1e-8 || !binary_search(vals[j], vals[j]+len[j], (int)tmpd)){ flag=0; break;}
            }
            if(flag){
                for(i=0; i<k; i++){
                    printf("%d", (int)(d*X.vec[i]));
                    if(i<k-1) printf(" ");
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
