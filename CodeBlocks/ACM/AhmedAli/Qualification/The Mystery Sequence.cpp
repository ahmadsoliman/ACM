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

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ii, ii> iiii;
typedef pair<double, int> di;
typedef vector<int> vi;
typedef vector<di> vdi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

char in[1000];
vector<int> nums;

int main(){
    int t,n,k, sum;

    nums.push_back(2);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(17);
    nums.push_back(18);
    nums.push_back(21);
    nums.push_back(28);
    nums.push_back(37);
    nums.push_back(43);
    nums.push_back(61);

    for(int i=0; i<nums.size(); i++) printf("%2d ", nums[i]);
    printf("\n");
    int fib1=0, fib2=1;
    for(int i=0; i<nums.size(); i++) printf("%2d ", abs(nums[i]-fib2), fib2), swap(fib1, fib2), fib2+=fib1;



    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);

    }

    return 0;
}





