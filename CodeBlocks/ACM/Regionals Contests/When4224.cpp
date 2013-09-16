#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000010

#define PRINT 1
#define SET 2

#define VAR 1
#define NUM 2

typedef struct {
    string name;
    int var_index;
} variable;

typedef struct {
    int type;
    variable var;
    int num_value;
} expr;

typedef struct {
    char op;
} op;

typedef struct {
    vector<expr> exprs;
    vector<op> operators;
} expression_list;

typedef struct {

} assignment;

typedef struct {
    int type; //PRINT || SET
    expression_list expr_list;
    vector<assignment> assign_list;
} statement;

typedef struct {
    expr condition;
    vector<statement> statements;
} when;

queue<when> whens;

int main(){

    return 0;
}
