#include <stdio.h>
#include <utility>

using namespace std;

class node{
    int key, p;
    node *left, *right;

    node(int k, int prior, node *l, node *r){
        key=k;
        p=prior;
        left=l;
        right=r;
    }

};

class treap{
    node nill=(0,-1,NULL,NULL);
    node root=nill;

    node rotate_left(node root){
        node tmp = root.right;
        root.right = tmp.left;
        tmp.left=root;
        return tmp;
    }

    node rotate_right(node root){
        node tmp = root.left;
        root.left = tmp.right;
        tmp.right=root;
        return tmp;
    }

    node balance(node root){
        if(root.p < root.left.p){
            return rotate_right(root);
        }
        if(root.p < root.right.p){
            return rotate_left(root);
        }
        return root;
    }

    node insert(int k, node cur){
        if(root==nill){
            return node();
        }
        if(k<cur.key){
            root.left = insert(k, root.left);
        }else{
            root.right = insert(k, root.right);
        }
        return balance(root);
    }
};

int main(){
    int Q, t=-1, n;
    char c;
    scanf("%d" &Q);
    while(++t<Q){
        scanf("%c ", &c);
        scanf("%d", &n);
        printf("%c\n", c);
        switch(c){

        }
    }

    return 0;
}

