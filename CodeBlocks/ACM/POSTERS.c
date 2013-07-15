#include <stdio.h>

#define START 1
#define END 2

typedef struct {
    int s, e, i;
}Post;

typedef struct {
    int type, x, i;
}Point;

int compare_posts_s(const void *v1, const void *v2)
{
    const Post *p1 = v1;
    const Post *p2 = v2;

    if(p1->s<p2->s)
        return -1;
    if(p1->s>p2->s)
        return 1;
    if(p1->i<p2->i)
        return -1;
    if(p1->i>p2->i)
        return 1;
    return 0;
}

int compare_posts_e(const void *v1, const void *v2)
{
    const Post *p1 = v1;
    const Post *p2 = v2;

    if(p1->e<p2->e)
        return -1;
    if(p1->e>p2->e)
        return 1;
    if(p1->i<p2->i)
        return -1;
    if(p1->i>p2->i)
        return 1;
    return 0;
}

int compare_points(const void *v1, const void *v2)
{
    const Point *p1 = v1;
    const Point *p2 = v2;

    if(p1->x<p2->x)
        return -1;
    if(p1->x>p2->x)
        return 1;
    if(p1->i<p2->i)
        return -1;
    if(p1->i>p2->i)
        return 1;
    return 0;
}

Post posts[40005], posts_end[40005], posts_high[40005];
Point points[80010];

int main(){
    int t, n, i, highest, c, last_removed;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i=0; i<n; i++){
            Post p;
            scanf("%d %d", &p.s ,&p.e);
            p.i = i;
            posts[i] = p;
            posts_end[i] = p;

            Point point;
            point.i = i;
            point.x = p.s;
            point.type =  START;
            points[2*i] = point;
            point.x = p.e;
            point.type =  END;
            points[2*i+1] = point;
        }
        highest = 0;

        qsort(posts, n, sizeof(Post), compare_posts_s);
        qsort(posts_end, n, sizeof(Post), compare_posts_e);

        qsort(points, 2*n, sizeof(Point), compare_points);

        c = 0;
        last_removed = 0;
        for(i=0; i<2*n; i++){

        }
        printf("%d\n", c);
    }
    return 0;
}

/*
//printf("%d: %d\n", posts[i].i, posts[i].s);
            //if(posts[i]){
             //   c++;
            //}
            if(posts[i].i>highest){
                highest = posts[i].i;
                c++;
            }
            if(posts_end[last_removed].e>=posts[i].s){
                //c--;
                if(posts_end[last_removed].i==highest){
                    //highest = highest in previous range
                }
                last_removed++;
            }
*/
