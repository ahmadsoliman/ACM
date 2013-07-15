#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define START 1
#define END 2


typedef struct
{
    int type, x, i;
} Point;

int compare_points(const void *v1, const void *v2)
{
    const Point *p1 = v1;
    const Point *p2 = v2;

    if(p1->x<p2->x)
        return -1;
    if(p1->x>p2->x)
        return 1;
    if(p1->i<p2->i)
        return 1;
    if(p1->i>p2->i)
        return -1;
    return 0;
}

Point points[80010], origPoints[80010];
int visible[40005], activeSet[40005];

int main()
{
    int t, n, i, highest, c, s, e;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(i=0; i<n; i++) {
            scanf("%d %d", &s ,&e);

            Point point;
            point.i = i;
            point.x = s;
            point.type =  START;
            points[2*i] = point;
            origPoints[2*i] = point;
            point.type =  END;
            point.x = e;
            points[2*i+1] = point;
            origPoints[2*i+1] = point;
        }

        qsort(points, 2*n, sizeof(Point), compare_points);

        memset(visible, 0, sizeof visible);
        memset(activeSet, 0, sizeof activeSet);

        highest = -1;
        c = 0;

        for(i=0; i<2*n; i++){
            //printf("P: %d %d\n", points[i].i, points[i].x);
            if(points[i].type==START){
                activeSet[points[i].i] = 1;
                if(points[i].i>highest){
                    highest = points[i].i;
                    if(points[i+1].type==END || points[i].x!=points[i+1].x){
                        visible[highest] = 1;
                    }
                }
            }else{
                activeSet[points[i].i] = 0;
                if(points[i].i==highest){
                    if(points[i+1].type == END || (points[i].x!=points[i+1].x && points[i].x+1!=points[i+1].x)){
                        while(highest>-1 && activeSet[highest]==0) highest--;
                        if(highest>-1) visible[highest] = 1;
                    }else{
                        highest = -1;
                    }
                }
            }
        }
        for(i=0; i<n; i++){
            c += visible[i];
        }

        printf("%d\n", c);
    }
    return 0;
}
