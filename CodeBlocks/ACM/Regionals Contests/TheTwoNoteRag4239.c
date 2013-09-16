#include <stdio.h>
#include <string.h>

long long ans[21];

long long powmod(long long a, long long b, long long  c){
  long long result = 1;
  long long base = a;
  while (b){
    if (b & 1){
      result = result*base % c;
    }
    b >>= 1;
    base = base*base % c;
  }
  return result;
}

int main(){
    int t;
    long long n,r, i,j;
    scanf("%d", &t);

    ans[1]=1; ans[2]=9; ans[3]=89; ans[4]=89; ans[5]=589; ans[6]=3089; ans[7]=3089;
    for(n=8; n<21; n++){
        mh = pow(2, n/2+1);
        map<long long, long long> mymap;

        for(i=0; i<mh; i++){
            //add g^i, i to hash table
            mymap.insert(make_pair(powmod(primitiveRoot,i,n), i));
        }
        //g^-m
        rootInv = powmod(powmod(primitiveRoot, phiN-1, n), mh, n);
        //set Y = a
        Y = a;

        //step 5
        for(i=0; i<mh; i++){
            map<long long, long long>::iterator it = mymap.find(Y);
            if(it!=mymap.end()){
                h = i*mh + it->second;
                break;
            }else{
                Y = mulmod(Y, rootInv, n);
            }
        }

    }

    while(t--){
        scanf("%d", &r);
        printf("%lld\n", ans[r]);
    }
    return 0;
}
