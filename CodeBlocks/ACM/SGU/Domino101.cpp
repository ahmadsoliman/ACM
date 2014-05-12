#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, int> ii;

vector<ii> dominos;
int freq[10], dir[105];

int main(){
    int n, i,j,k, a,b, odd, f;
    scanf("%d", &n);
    memset(freq, 0, sizeof freq);
    for(i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        dominos.push_back(ii(a,b));
        freq[a]++;
        freq[b]++;
    }

    odd=0;
    for(i=0; i<7; i++) if(freq[i]%2==1) odd++;
    memset(dir, 0, sizeof dir);

    vector<int> res;
    if(odd==0){
        for(i=0; i<7; i++) if(freq[i]>2) break;
        if(i==7){


        }else{
            for(i=0; i<7; i++) {
                if(freq[i]==2){
                    for(j=0; j<n; j++){
                        if(dominos[j].first!=dominos[j].second && (dominos[j].first==i||dominos[j].second==i)){
                            res.push_back(j);
                            dominos.erase(dominos.begin()+j);
                            break;
                        }
                    }
                }
                if(res.size()==1) break;
            }
            if(i==7) { printf("No solution\n"); return 0; }

            int side=i;
            ii lastDom;
            for(i=0; i<dominos.size(); i++){
                if(dominos[i].first==side||dominos[i].first==side){
                    lastDom=dominos[i];
                    dominos.erase(dominos.begin()+i);
                    break;
                }
            }


        }
    }else if(odd==2){
        ii lastDom;
        for(i=0; i<7; i++){
            if(freq[i]%2==1){
                for(j=0; j<dominos.size(); j++){
                    if(dominos[j].first!=dominos[j].second && (dominos[j].first==i||dominos[j].second==i)){
                        if(res.size()==0){
                            res.push_back(j);
                            dominos.erase(dominos.begin()+j);
                            j--;
                        }else{
                            lastDom=dominos[j];
                            dominos.erase(dominos.begin()+j);
                            break;
                        }
                    }
                }
            }
        }

        while(dominos.size()>0){
            f=0;
            for(i=0; i<dominos.size(); i++){

            }
        }
    }else{
        printf("No solution\n");
    }

    return 0;
}
