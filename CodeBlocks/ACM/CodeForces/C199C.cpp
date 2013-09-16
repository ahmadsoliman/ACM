#include <stdio.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define INF 1000000000

double angleCosRule(double a, double b, double c){
    return acos((a*a+b*b-c*c)/(2*a*b));
}


int main(){
    int r, h;
    double PI = acos(-1);

    scanf("%d %d", &r, &h);
    double theta  = angleCosRule(r, r/2.0, r/2.0);
    double hsmall = r/2.0*sin(PI-theta);
    double hbig = hsmall + h;
    printf("%lf\n", (hbig/(r/2.0))+1);
    return 0;
}
