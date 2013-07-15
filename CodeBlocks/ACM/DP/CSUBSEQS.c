#include <string.h>
#include <stdio.h>

char a[51], b[51], c[51], d[51];
int n1,n2,n3,n4, o1[26][50],o2[26][50],o3[26][50],o4[26][50], l1[26],l2[26],l3[26],l4[26], dp[51][51][51][51];

int recur(int i, int j, int k, int l){
    if(i==n1||j==n2||k==n3||l==n4)
        return 0;
    if(dp[i][j][k][l]!=-1)
        return dp[i][j][k][l];

    int sum = 0;
    if(a[i]==b[j]&&a[i]==c[k]&&a[i]==d[l]){
        int e1,e2,e3,e4, index=a[i]-'a';
        for(e1=0; e1<l1[index] && i!=o1[index][e1]; e1++);
        for(e2=0; e2<l2[index] && j!=o2[index][e2]; e2++);
        for(e3=0; e3<l3[index] && k!=o3[index][e3]; e3++);
        for(e4=0; e4<l4[index] && l!=o4[index][e4]; e4++);

        if(e1<=e2&&e2<=e3&&e3<=e4)
            sum += 1 + 2*recur(i+1,j+1,k+1,l+1);
        else
            sum += recur(i+1,j+1,k+1,l+1);
        return dp[i][j][k][l] = sum;
    }
    if(i<n1)
        sum += recur(i+1, j, k, l);
    if(j<n2)
        sum += recur(i, j+1, k, l);
    if(k<n3)
        sum += recur(i, j, k+1, l);
    if(l<n4)
        sum += recur(i, j, k, l+1);
    return dp[i][j][k][l] = sum;
}

int main(){
    int i;
    scanf("%s", a);
    scanf("%s", b);
    scanf("%s", c);
    scanf("%s", d);
    n1 = strlen(a);
    n2 = strlen(b);
    n3 = strlen(c);
    n4 = strlen(d);
    for(i=0; i<n1; i++) o1[a[i]-'a'][l1[a[i]-'a']++] = i;
    for(i=0; i<n2; i++) o2[b[i]-'a'][l2[b[i]-'a']++] = i;
    for(i=0; i<n3; i++) o3[c[i]-'a'][l3[c[i]-'a']++] = i;
    for(i=0; i<n4; i++) o4[d[i]-'a'][l4[d[i]-'a']++] = i;
    memset(dp, -1, sizeof dp);
    printf("%d\n", recur(0,0,0,0));
    return 0;
}
