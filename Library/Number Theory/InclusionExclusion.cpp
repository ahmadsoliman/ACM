

ll incexc(vector<int> v, int i, int left, int lcmt){
    if(left==0) return div(lcmt);
    if(i==v.size()) return 0;
    return (incexc(v, i+1, left, lcmt)+
           ((left>0)? incexc(v, i+1, left-1, lcm(lcmt, v[i])) :0)) % MOD;
}

int main(){
    int i, sum=0;
    for(i=1; i<=conddiv.size(); i++){
        sum=mod(sum+mod(pow(-1, i+1)*incexc(conddiv, 0, i, 1)));
        //printf("sum: %lld\n", incexc(conddiv, 0, i, 1));
    }
    for(i=1; i<=condnotdiv.size(); i++){
        sum=mod(sum-mod(pow(-1, i+1)*incexc(condnotdiv, 0, i, 1)));
    }

    return 0;
}
