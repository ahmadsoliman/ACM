#include <stdio.h>
#include <math.h>

using namespace std;

int main(){
    int t, i;
    long long n;

    scanf("%d", &t);
    while(t--) {
        scanf("%ld", &n);
        printf("%ld\n", (long long)(2*sqrt(1+(double)n/2)-0.5));
    }
    return 0;
}
