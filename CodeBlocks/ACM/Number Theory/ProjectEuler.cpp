#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>

#define MAX (2000000)

using namespace std;

// calculates (a*b)%c taking into account that a*b might overflow
long long mulmod(long long a,long long b,long long c){
    long long x=0; y=a%c;
    while(b){
        if(b&1) x += y;
        if(x>=MOD) x-=MOD;
        y <<= 1;
        if(y>=MOD) y-=MOD;
        b >>= 1;
    }
    return x;
}

long long powmod1(int x, int pow, int m){
    if(pow==1)return x;
    long long halfpow = powmod1(x,pow/2,m);
    return (halfpow*halfpow*((pow%2)?x:1))%m;
}

long long powmod2(long long a, long long b, long long  c){
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


int prob2(){//even fib nums
    int s=0, y=2;
    double golden3=4.2360679775;
    while(y<3000000){
        s+=y;
        y=(int)roundf(y*golden3);
    }
    return s;
}

int primes[2000000];

void sieve(){
    memset(primes, 1, sizeof primes);
    int i,j, sqrtM=(int)sqrt(MAX);
    for(i=2; i<sqrtM; i++){
        if(!primes[i])continue;
        for(j=i*i; j<MAX; j+=i)primes[j]=0;
    }
}

#define MAXSIEVE 100000000
#define MAXSIEVEHALF (MAXSIEVE/2)
#define MAXSQRT 5000

char a[MAXSIEVE/16+2];
int primes2[6000000];
#define isPrime(n) (a[(n)>>4]&(1<<(((n)>>1)&7)))

void fast_sieve(){
    int i, j;
    memset(a, 255, sizeof(a));
    a[0]=0xFE;
    for(i=1;i<MAXSQRT;i++)
        if(a[i>>3]&(1<<(i&7)))
            for(j=i+i+i+1;j<MAXSIEVEHALF;j+=i+i+1)
                a[j>>3]&=~(1<<(j&7));
    primes2[0]=2;
    j=1;
    for(i=3; i<MAXSIEVE; i+=2)if(isPrime(i))primes2[j++]=i;
}

long long prob3(){//largest prime factor
    long long x = 600851475143LL, maxD, i;
    sieve();
    for(i=2ll; i<MAX; i++){
        if(primes[i]){
            while(x%i==0){
                x/=i;
                if(i>maxD)maxD=i;
            }
        }
    }
    return maxD;
}

int isPalin(int x){
    char s[6];
    sprintf(s, "%d", x);
    int n=0,i;
    while(x>0)x/=10,n++;
    for(i=0; i<n/2; i++)if(s[i]!=s[n-i-1])return 0;
    return 1;
}

void prob4(){
    int i, j, maxN=0, curN, maxI=0,maxJ=0;
    for(i=999;i>99;i--){
        for(j=999;j>99;j--){
            curN=i*j;
            if(curN>maxN && isPalin(curN)){
                maxN=curN;  maxI=i; maxJ=j;
            }
        }
    }
    printf("%d %d",maxI, maxJ);
}

int gcd(int m, int n){
    if(m==0)return n;
    return gcd(n%m, m);
}

long long gcdl(long long m, long long n){
    long long tmp;
    while(m>0){
        tmp = m;
        m = n%m;
        n = tmp;
    }
    return n;
}


int prob5(){
    int product=1, i;
    for(i=2; i<21; i++)product*=(i/gcd(product,i));
    return product;
}

int prob6(){
    int i, sum=0, sumSquares=0, res;
    for(i=1; i<101; i++)sumSquares+=i*i;
    printf("%d\n", sumSquares);
    res = 25502500-sumSquares;
    return res;
}

int prob7(){
    sieve();
    int i,countI=0;
    for(i=2; i<MAX; i++){
        if(primes[i])countI++;
        if(countI==10001)return i;
    }
    return 0;
}

int prob8(){
    string s;
    s="731671765313306249192251196744265747423553491949349698352031277450632623957831801698480186947885184385";
    s+="861560789112949495459501737958331952853208805511125406987471585238630507156932909632952274430435576689";
    s+="664895044524452316173185640309871112172238311362229893423380308135336276614282806444486645238749303589";
    s+="072962904915604407723907138105158593079608667017242712188399879790879227492190169972088809377665727333";
    s+="0010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977";
    s+="846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440";
    s+="3199890008895243450658541227588666881164271714799244429282308634656748139191231628245861786645835912456";
    s+="65294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444";
    s+="36298123098787992724428490918884580156166097919133875499200524063689912560717606058861164671094050775410";
    s+="0225698315520005593572972571636269561882670428252483600823257530420752963450";

    int i, maxP=0, curP;
    for(i=0; i<996; i++){
        curP=(s[i]-'0')*(s[i+1]-'0')*(s[i+2]-'0')*(s[i+3]-'0')*(s[i+4]-'0');
        if(curP>maxP)maxP=curP;
    }
    return maxP;
}

int prob9(){
    //a= 2mn; b= m^2 -n^2; c= m^2 + n^2;
    int i, j, c;
    for(i=1; i<1000; i++){
        for(j=1; i+j<1000; j++){
            c=1000-i-j;
            if(i*i+j*j==c*c)return i*j*c;
        }
    }
}

long long prob10(){
    int i;
    long long s=0ll;
    sieve();
    for(i=2; i<MAX; i++)if(primes[i])s+=i;
    return s;
}

long long prob12(){
    long long i,j, countD, halfI, reached=0ll, pow, reachedT;
    fast_sieve();
    for(i=1;; i++){
        reached+=i;
        countD=1;
        halfI=reached/2;
        pow=1;
        reachedT=reached;
        for(j=0; primes2[j]<=reachedT; j++,countD*=pow,pow=1)while(reachedT%primes2[j]==0&&pow++)reachedT/=primes2[j];
        //countD*=pow;
        if(countD>500)return reached;
    }
}

int prob14(){
    long long len, maxLen=0, j;
    int i,maxI;
    for(i=100000; i<1000000; i++){
        len=1;j=i;
        while(j>1){
            if(j%2>0)
                j=3*j+1;
            else
                j/=2;
            len++;
        }
        if(len>maxLen){
            maxI=i;
            maxLen=len;
        }
    }
    return maxI;
}

//prob 15, (2*(n-1)) C (n-1)
//prob 16, python: print sum(map(int, str(2**1000)))

int prob17(){
    int digits[] = {4,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,8,8};//zero --> nineteen
    int tens[] = {3,6,6,6,5,5,7,6,6};//ten --> ninety
    int hundered = 8, thousand=8;
    int countHundered=0,i,j;//1-->99
    for(i=1; i<20; i++)countHundered+=digits[i];//1-->19
    for(i=1; i<9; i++){//20-->99
        countHundered+=tens[i];
        for(j=1; j<10; j++)countHundered+=tens[i]+digits[j];
    }
    int countThousand=countHundered;
    for(i=1; i<9; i++){//100-->999
        countHundered+=(digits[i]+hundered)*100+countHundered;
    }
    return countThousand+=digits[1]+thousand;
}

//Extended Euclidean Algorithm
void eGCD(long long res[], long long m, long long n){
    if(m==0){
        res[0]=0;res[1]=1;res[2]=n;
        return ;
    }
    long long tmp[3];
    eGCD(tmp, n%m, m);
    res[0]=tmp[1]-(n/m)*tmp[0];res[1]=tmp[0];res[2]=tmp[2];
}

//Chinese Remainder Theorem , congruences[i][0] = ai & congruences[i][1] = ni
long long congruences[3][2];
long long CRT(int len){
    //check all n are co-prime

    //calculate N
    long long N=1ll;
    int i;
    for (i = 0; i < len; i++) {
        N*=congruences[i][1];
    }

    //calculate x
    long long x=0ll;
    for (i = 0; i < len; i++) {
        long long si = N/congruences[i][1];
        long long tmp[3];
        eGCD(tmp, congruences[i][1], si);
        x += tmp[1]*si*congruences[i][0];
    }
    return x;
}

//phi(n)
long long phi(long long n){
    long long phiN=1;
    int j, powJ;
    for(j=0; primes[j]<=n; j++){
        powJ = 0;
        while(n%primes[j]==0 && ++powJ)  n/=primes[j];
        if(n%primes[j]==0)  phiN*=(primes[j]-1)*((powJ>1)?pow(primes[j], powJ-1):1);
    }
    if(n>1)
        phiN*=(n-1);
    return phiN;
}
int main(){
    congruences[0][0]=0;congruences[0][1]=12;
    congruences[1][0]=0;congruences[1][1]=21;
    congruences[2][0]=0;congruences[2][1]=28;
    printf("%d", CRT(3));
    return 0;
}
