/*j ID: ahmadad1
PROG: range
LANG: C++
*/
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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef long long ll;

char in[300];
int grid[255][255], col[255][255], row[255][255], freq[250];

int main() {
    freopen("range.in", "r", stdin);
    freopen("range.out", "w", stdout);

    int i,j,k, n;

    memset(grid, 0, sizeof grid);
    memset(col, 0, sizeof col);
    memset(row, 0, sizeof row);

    scanf("%d", &n);

    for(i=0; i<n; i++) {
        scanf("%s", in);
        for(j=0; j<n; j++) grid[i+1][j+1]=in[j]-'0';
    }

    n++;

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            row[i][j]=row[i][j-1]+grid[i][j];
        }
    }

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            col[i][j]=col[i-1][j]+grid[i][j];
        }
    }

    memset(freq, 0, sizeof freq);

    for(i=1; i<n; i++){
        for(j=1; j<n; j++){
            if(!grid[i][j]) continue;
            for(k=1; i+k<n && j+k<n; k++){
                if(grid[i+k][j+k] && row[i+k][j+k-1]-row[i+k][j-1]==k && col[i+k-1][j+k]-col[i-1][j+k]==k)
                    freq[k+1]++;
                else break;
            }
        }
    }

    for(i=2; i<251; i++) if(freq[i]>0) printf("%d %d\n", i, freq[i]);

    return 0;
}





