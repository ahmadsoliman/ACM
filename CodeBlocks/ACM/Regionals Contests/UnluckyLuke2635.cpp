#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <bitset>
#include <algorithm>

#define EPS 1e-9

using namespace std;

typedef pair<int, int> ii;

int w[105];
double v[105];

vector<pair<double, ii > >ratios;

int compare (const void * a, const void * b){
    pair<double, ii> ap=*(pair<double, ii>*)a, bp=*(pair<double, ii>*)b;
    if(ap.first<bp.first) return -1;
    if(ap.first>bp.first) return 1;

}

int main(){
    int t, n, i,j,k;
    double V;
    scanf("%d", &t);
    while(t--){
        scanf("%d %lf", &n, &V);
        for(i=0; i<n; i++){
            scanf("%d", &w[i]);
        }
        ratios.clear();
        for(i=0; i<n; i++){
            scanf("%lf", &v[i]);
            ratios.push_back(pair<double, ii>(v[i]/w[i], ii(w[i], i)));
        }
        sort(ratios.rbegin(), ratios.rend(), compare);
        double V1=V, V2=V, res=0;
        for(i=0; i<n; i++){
            j=ratios[i].second.second;
            if((w[j]>V1||fabs(w[j]-V1)<EPS) && (w[j]>V2||fabs(w[j]-V2)<EPS)){
                if(V1<V2){
                    res+=V2/w[j]*v[j];
                    V2=0;
                }else{
                    res+=V1/w[j]*v[j];
                    V1=0;
                }
            }else if(w[j]<V1 && w[j]<V2){
                res+=v[j];
                if(V1<V2){
                    V2-=w[j];
                }else{
                    V1-=w[j];
                }
            }else if(w[j]<V1 || fabs(w[j]-V1)<EPS){
                res+=v[j];
                V1-=w[j];
            }else if(w[j]<V2 || fabs(w[j]-V2)<EPS){
                res+=v[j];
                V2-=w[j];
            }else if(w[j]>V1 && V1>EPS){
                res+=V1/w[j]*v[j];
                V1=0;
            }else if(w[j]>V2 && V2>EPS){
                res+=V2/w[j]*v[j];
                V2=0;
            }
            if(V1<EPS && V2<EPS) break;
        }
        printf("%.4lf\n", res);
    }
    return 0;
}
