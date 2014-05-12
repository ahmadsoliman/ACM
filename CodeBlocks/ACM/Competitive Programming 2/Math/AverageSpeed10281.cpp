#include <stdio.h>
#include <string.h>
#include <math.h>

char in[1000];

int main(){
    int i,j, h=0,m=0,s=0, nh,nm,ns, time, speed=0;
    double dist=0;
    while(gets(in)){
        if(strcmp(in, "")==0) continue;
        char *p = strtok(in, " ");
        sscanf(p, "%d:%d:%d", &nh, &nm, &ns);
        p = strtok(NULL, " ");
        dist += speed * (nh-h+(nm-m)/60.0+(ns-s)/3600.0);
        h=nh, m=nm, s=ns;
        if(p==NULL) printf("%02d:%02d:%02d %.2lf km\n", h,m,s, dist);
        else sscanf(p, "%d", &speed);

    }
    return 0;
}
