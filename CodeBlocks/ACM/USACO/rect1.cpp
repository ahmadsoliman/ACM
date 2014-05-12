/*j ID: ahmadad1
PROG: rect1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <algorithm>
#include <set>
#include <math.h>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

struct rect{
    int lx, ly, ux, uy, c;
    rect(){
        lx=ly=ux=uy=c=0;
    }
    rect(int x1, int y1, int x2, int y2, int c1){
        lx=x1; ly=y1; ux=x2; uy=y2; c=c1;
    }
};

rect rects[1005];

vector<rect> check(rect back, rect front){
    vector<rect> res;

    //printf("c: %d %d %d %d %d\n", back.lx, back.ly, back.ux, back.uy, back.c);
    //printf("c: %d %d %d %d %d\n", front.lx, front.ly, front.ux, front.uy, front.c);

    // no intersection
    if(front.lx>=back.ux || front.ly>=back.uy ||
       back.lx>=front.ux || back.ly>=front.uy) {
           res.push_back(back);
           return res;
    }

    // front covers back
    if(front.lx<=back.lx && front.ly<=back.ly &&
       front.ux>=back.ux && front.uy>=back.uy) return res;

    // front inside back
    if(front.lx>=back.lx && front.ly>=back.ly &&
       front.ux<=back.ux && front.uy<=back.uy) {
        res.push_back(rect(back.lx, back.ly, front.lx, back.uy, back.c));
        res.push_back(rect(front.lx, back.ly, front.ux, front.ly, back.c));
        res.push_back(rect(front.lx, front.uy, front.ux, back.uy, back.c));
        res.push_back(rect(front.ux, back.ly, back.ux, back.uy, back.c));
        return res;
    }

    // cover corner
    if(back.ly<=front.ly && front.lx<=back.lx && back.ux<=front.ux && back.uy<=front.uy){
        res.push_back(rect(back.lx, back.ly, back.ux, front.ly, back.c));
        return res;
    }
    if(back.ly>=front.ly && front.lx<=back.lx && back.ux<=front.ux && back.uy>=front.uy){
        res.push_back(rect(back.lx, front.uy, back.ux, back.uy, back.c));
        return res;
    }
    if(back.ly>=front.ly && front.lx>=back.lx && back.ux<=front.ux && back.uy<=front.uy){
        res.push_back(rect(back.lx, back.ly, front.lx, back.uy, back.c));
        return res;
    }
    if(back.ly<=front.ly && front.lx<=back.lx && back.ux<=front.ux && back.uy<=front.uy){
        res.push_back(rect(front.ux, back.ly, back.ux, back.uy, back.c));
        return res;
    }

    // cuts to three
    if(back.lx<=front.lx && back.ux>=front.ux){
        if(back.ly<=front.ly){
            res.push_back(rect(back.lx, back.ly, front.lx, back.uy, back.c));
            res.push_back(rect(front.lx, back.ly, front.ux, front.ly, back.c));
            res.push_back(rect(front.ux, back.ly, back.ux, back.uy, back.c));
            return res;
        }else{
            res.push_back(rect(back.lx, back.ly, front.lx, back.uy, back.c));
            res.push_back(rect(front.lx, back.uy, front.ux, back.uy, back.c));
            res.push_back(rect(front.ux, back.ly, back.ux, back.uy, back.c));
            return res;
        }
    }
    if(back.ly<=front.ly && back.uy>=front.uy){
        if(back.lx<=front.lx){
            res.push_back(rect(back.lx, back.ly, front.lx, back.uy, back.c));
            res.push_back(rect(front.lx, back.ly, back.ux, front.ly, back.c));
            res.push_back(rect(front.lx, front.uy, back.ux, back.uy, back.c));
            return res;
        }else{
            res.push_back(rect(front.ux, back.ly, back.ux, back.uy, back.c));
            res.push_back(rect(back.lx, back.ly, front.ux, front.ly, back.c));
            res.push_back(rect(back.lx, front.uy, front.ux, back.uy, back.c));
            return res;
        }
    }

    // cuts to two
    if(back.lx<=front.lx){
        if(back.ly<=front.ly){
            res.push_back(rect(back.lx, back.ly, front.lx, back.uy, back.c));
            res.push_back(rect(front.lx, back.ly, back.ux, front.ly, back.c));
        }else{
            res.push_back(rect(back.lx, back.ly, front.lx, back.uy, back.c));
            res.push_back(rect(front.lx, front.uy, back.ux, back.uy, back.c));
        }
    }else{
        if(back.ly<=front.ly){
            res.push_back(rect(back.lx, back.ly, front.ux, front.ly, back.c));
            res.push_back(rect(front.ux, back.ly, back.ux, back.uy, back.c));
        }else{
            res.push_back(rect(back.lx, front.uy, front.ux, back.uy, back.c));
            res.push_back(rect(front.ux, back.ly, back.ux, back.uy, back.c));
        }
    }

    return res;
}

int col[3005];

#include <fstream>
#include <vector>



struct RECT
{
    int x[2];
    int y[2];
    int color;
};


RECT intersect (RECT a, RECT b)
{
    RECT rtrn;


    //high left, high bottom, low right, low top
    if (a.x[0] < b.x[0])
        rtrn.x[0] = b.x[0];
    else
        rtrn.x[0] = a.x[0];


    if (a.y[0] < b.y[0])
        rtrn.y[0] = b.y[0];
    else
        rtrn.y[0] = a.y[0];


    if (a.x[1] > b.x[1])
        rtrn.x[1] = b.x[1];
    else
        rtrn.x[1] = a.x[1];


    if (a.y[1] > b.y[1])
        rtrn.y[1] = b.y[1];
    else
        rtrn.y[1] = a.y[1];


    return rtrn;
}


int sub_rect (vector<RECT> *rect, RECT a, RECT b)
{
    RECT add[4];
    int m, n = 0;


    //Test for empty
    if (b.y[1] <= b.y[0] || b.x[1] <= b.x[0])
    {
        rect->push_back (a);
        return 0;
    }


    //Create rectangles
    add[0].x[0] = a.x[0];
    add[0].y[0] = b.y[1];
    add[0].x[1] = a.x[1];
    add[0].y[1] = a.y[1];

    add[1].x[0] = b.x[1];
    add[1].y[0] = b.y[0];
    add[1].x[1] = a.x[1];
    add[1].y[1] = b.y[1];

    add[2].x[0] = a.x[0];
    add[2].y[0] = a.y[0];
    add[2].x[1] = a.x[1];
    add[2].y[1] = b.y[0];

    add[3].x[0] = a.x[0];
    add[3].y[0] = b.y[0];
    add[3].x[1] = b.x[0];
    add[3].y[1] = b.y[1];


    //Test for <= 0 area, if not, then add
    for (m = 0;m < 4;m++)
    {
        if (add[m].x[1] > add[m].x[0] && add[m].y[1] > add[m].y[0])
        {
            add[m].color = a.color;
            rect->push_back (add[m]);
            n++;
        }
    }


    return n;
}


int main() {
    //freopen("rect1.in", "r", stdin);
    //freopen("rect1.out", "w", stdout);
/*
    int i,j,k,r,l, a, colcnt;
    int w,h, n;

    scanf("%d %d %d", &w, &h, &n);

    rects[0]=rect(0,0,w,h,1);

    n++;
    for(i=1; i<n; i++){
        scanf("%d %d %d %d %d", &rects[i].lx, &rects[i].ly, &rects[i].ux, &rects[i].uy, &rects[i].c);
    }

    vector<rect> cur, nxt;
    cur.push_back(rects[0]);

    for(i=1; i<n; i++){
        nxt.clear();
        for(j=0; j<cur.size(); j++){
            //printf("-- %d: %d,%d %d,%d -- %d\n", j, cur[j].lx, cur[j].ly, cur[j].ux, cur[j].uy, cur[j].c);
            vector<rect> v = check(cur[j], rects[i]);

            for(k=0; k<v.size(); k++) {
                if((v[k].ux-v[k].lx)*(v[k].uy-v[k].ly)<1) continue;
                nxt.push_back(v[k]);
            }
        }
        cur = nxt;
        cur.push_back(rects[i]);
    }

    colcnt=0;
    for(i=0; i<cur.size(); i++){
        printf("-- %d: %d,%d %d,%d -- %d\n", i, cur[i].lx, cur[i].ly, cur[i].ux, cur[i].uy, cur[i].c);

        a = (cur[i].ux-cur[i].lx)*(cur[i].uy-cur[i].ly);
        if(a>0) col[cur[i].c]+=a;
        colcnt=max(colcnt, cur[i].c);
    }

    for(i=0; i<=colcnt; i++){
        if(col[i]>0) printf("%d %d\n", i, col[i]);
    }*/
    ifstream in;
    ofstream out;
    vector<RECT> rect;
    RECT new_rect;
    int crect, area[2500];
    int a, b, c;


    for (a = 0;a < 2500;a++)
        area[a] = 0;


    in.open ("rect1.in");
    rect.push_back (new_rect);
    rect[0].x[0] = rect[0].y[0] = 0;
    rect[0].color = 1;
    in >> rect[0].x[1] >> rect[0].y[1] >> crect;


    for (a = 1;a <= crect;a++)
    {
        rect.push_back (new_rect);
        in >> rect.back ().x[0] >> rect.back ().y[0] >> rect.back ().x[1] >> rect.back ().y[1] >> rect.back ().color;


        c = rect.size ();
        for (b = 0;b < c - 1;b++)
        {
            sub_rect (&rect, rect.front (), intersect (rect.front (), rect[c - b - 1]));
            rect.erase (rect.begin ());
        }
    }


    in.close ();

    //Calculate area of each and add them
    b = rect.size ();


    for (a = 0;a < b;a++)
        area[rect[a].color - 1] += (rect[a].x[1] - rect[a].x[0]) * (rect[a].y[1] - rect[a].y[0]);


    out.open ("rect1.out");


    for (a = 0;a < 2500;a++)
    {
        if (area[a] != 0)
            out << a + 1 << " " << area[a] << "\n";
    }


    out.close ();
    return 0;
}
