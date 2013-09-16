#include <stdio.h>
#include <string.h>

char in[1000], a[100], b[100], ds[10], sums[100], outs[100];

int val(int num){
    switch(num){
        case 63: return 0;
        case 10: return 1;
        case 93: return 2;
        case 79: return 3;
        case 106: return 4;
        case 103: return 5;
        case 119: return 6;
        case 11: return 7;
        case 127: return 8;
        case 107: return 9;
    }
    return -1;
}

char* out(int num){
    switch(num){
        case 0: return "063";
        case 1: return "010";
        case 2: return "093";
        case 3: return "079";
        case 4: return "106";
        case 5: return "103";
        case 6: return "119";
        case 7: return "011";
        case 8: return "127";
        case 9: return "107";
    }
}

int main(){
    int i,j,k, n,m,l, d, num1, num2, sum;
    while(1){
        gets(in);
        if(strcmp(in, "BYE")==0) return 0;

        char *p = strtok(in, "+=");
        sscanf(p, "%s", a);
        p = strtok(NULL, "+=");
        sscanf(p, "%s", b);

        n=strlen(a);
        m=strlen(b);
        num1=num2=0;
        for(i=0; i<n; i+=3){
            num1*=10;
            strncpy(ds, a+i, 3);
            sscanf(ds, "%d", &d);
            num1+=val(d);
        }
        for(i=0; i<m; i+=3){
            num2*=10;
            strncpy(ds, b+i, 3);
            sscanf(ds, "%d", &d);
            num2+=val(d);
        }
        sum = num1+num2;

        sprintf(sums, "%d", sum);
        l = strlen(sums);
        outs[0]='\0';
        for(i=0; i<l; i++){
            d=sums[i]-'0';
            strcat(outs, out(d));
        }
        printf("%s+%s=%s\n", a, b, outs);
    }
    return 0;
}
