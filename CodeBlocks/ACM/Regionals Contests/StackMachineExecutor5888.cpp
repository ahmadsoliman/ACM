#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

#define NUM 1
#define POP 2
#define INV 3
#define DUP 4
#define SWP 5
#define ADD 6
#define SUB 7
#define MUL 8
#define DIV 9
#define MOD 10

vi program, var;
char in[1000];

int main(){
    int i,j,k,n, error;
    while(scanf("%s", in)>0){
        if(strcmp(in, "QUIT")==0) return 0;
        program.clear();
        var.clear();
        while(strcmp(in, "END")!=0) {
            var.push_back(0);
            if(strcmp(in, "NUM")==0){
                program.push_back(NUM);
                scanf("%d", &k);
                var[var.size()-1]=k;
            } else if(strcmp(in, "POP")==0) program.push_back(POP);
              else if(strcmp(in, "INV")==0) program.push_back(INV);
              else if(strcmp(in, "DUP")==0) program.push_back(DUP);
              else if(strcmp(in, "SWP")==0) program.push_back(SWP);
              else if(strcmp(in, "ADD")==0) program.push_back(ADD);
              else if(strcmp(in, "SUB")==0) program.push_back(SUB);
              else if(strcmp(in, "MUL")==0) program.push_back(MUL);
              else if(strcmp(in, "DIV")==0) program.push_back(DIV);
              else if(strcmp(in, "MOD")==0) program.push_back(MOD);
            scanf("%s", in);
        }
        scanf("%d", &n);
        while(n--){
            scanf("%d", &k);
            stack<int> s;
            s.push(k);
            error=0;
            for(i=0; i<program.size(); i++){
                switch(program[i]){
                case NUM: s.push(var[i]); break;
                case POP: if(s.empty()) { error=1; break; }
                    else s.pop(); break;
                case INV: if(s.empty()) { error=1; break; } k=-1*s.top(); s.pop(); s.push(k); break;
                case DUP: if(s.empty()) { error=1; break; } s.push(s.top()); break;
                case SWP: if(s.empty()) { error=1; break; } j=s.top(); s.pop(); if(s.empty()) { error=1; break; }
                            k=s.top(); s.pop(); s.push(j); s.push(k); break;
                case ADD: if(s.empty()) { error=1; break; } j=s.top(); s.pop(); if(s.empty()) { error=1; break; } k=s.top(); s.pop();
                    if(abs(k+j)>1e9) { error=1; break; }
                    s.push(k+j);
                    break;
                case SUB: if(s.empty()) { error=1; break; } j=s.top(); s.pop(); if(s.empty()) { error=1; break; } k=s.top(); s.pop();
                    if(abs(k-j)>1e9) { error=1; break; }
                    s.push(k-j);
                    break;
                case MUL: if(s.empty()) { error=1; break; }
                    j=s.top(); s.pop();  if(s.empty()) { error=1; break; } k=s.top(); s.pop();
                    if((ll)abs(j)*abs(k)>1e9) { error=1; break; }
                    s.push(k*j);
                    break;
                case DIV: if(s.empty()) { error=1; break; } j=s.top(); s.pop(); if(s.empty()) { error=1; break; } k=s.top(); s.pop();
                    if(j==0) { error=1; break; }
                    s.push(k/j);
                    break;
                case MOD: if(s.empty()) { error=1; break; } j=s.top(); s.pop(); if(s.empty()) { error=1; break; } k=s.top(); s.pop();
                    if(j==0) { error=1; break; }
                    s.push(((k<0)?-1:1)*abs(k)%abs(j));
                    break;
                }
                if(error) break;
            }
            if(error || s.size()!=1) printf("ERROR\n");
            else printf("%d\n", s.top());
        }
        printf("\n");
    }
    return 0;
}
