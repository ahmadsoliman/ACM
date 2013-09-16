#include <stdio.h>

int main(){
    int t, conv, i,j, kase=1;
    double v, res;
    char in[10];
    scanf("%d", &t);
    while(t--){
        scanf("%lf %s", &v, in);
        if(strcmp(in, "kg")==0) conv=0;
        else if(strcmp(in, "lb")==0) conv=1;
        else if(strcmp(in, "l")==0) conv=2;
        else if(strcmp(in, "g")==0) conv=3;
        switch(conv){
        case 0: res = v*2.2046; printf("%d %.4lf lb\n", kase++, res); break;
        case 1: res = v*0.4536; printf("%d %.4lf kg\n", kase++, res); break;
        case 2: res = v*0.2642; printf("%d %.4lf g\n", kase++, res); break;
        case 3: res = v*3.7854; printf("%d %.4lf l\n", kase++, res); break;
        }
    }
    return 0;
}
