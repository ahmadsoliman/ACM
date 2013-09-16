#include <stdio.h>

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int compare1 (const void * a, const void * b)
{
  return ( *(int*)b - *(int*)a );
}

int main(){
    int taken[53], girl[3], boy[2], takenGirl[3], takenBoy[2], i, j, needed;
    while(scanf("%d %d %d %d %d", &girl[0], &girl[1], &girl[2], &boy[0], &boy[1])>0){
        if(girl[0]==0) return 0;
        memset(taken, 0, sizeof taken);
        memset(takenBoy, -1, sizeof takenBoy);
        memset(takenGirl, -1, sizeof takenGirl);

        qsort(girl, 3, sizeof(int), compare);
        qsort(boy, 2, sizeof(int), compare1);
        for(i=0; i<3; i++) taken[girl[i]]=1;
        for(i=0; i<2; i++) taken[boy[i]]=1;

        for(i=0; i<2; i++) {
            for(j=0; j<3; j++) {
                if(takenGirl[j]==-1 && girl[j]>boy[i]){
                    takenGirl[j]=i;
                    takenBoy[i]=j;
                    break;
                }
            }
        }
        if(takenBoy[0]!=-1 && takenBoy[1]!=-1) printf("-1\n");
        else{
            if(takenBoy[0]==-1 && takenBoy[1]==-1){
                needed=1;
            } else {
                for(i=2; i>=0; i--) if(takenGirl[i]==-1) break;
                needed=girl[i];
            }
            while(taken[needed]==1 && needed<53) needed++;
            if(needed>52) printf("-1\n");
            else printf("%d\n", needed);
        }
    }

    return 0;
}
