#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>

using namespace std;

pair<int, int> nums[10010];
int arr[10010], arrindex[10010];

int popFirstElement(multiset<int> &S) {
    int result = *(S.begin());
    S.erase( S.begin() );
    return result;
}

int popLastElement(multiset<int> &S) {
    multiset<int>::iterator it = S.end();
    it--;
    int result = *it;
    S.erase( it );
    return result;
}

int getLastElement(multiset<int> &S) {
    multiset<int>::iterator it = S.end();
    it--;
    return *it;
}

int main(){
    int t, i,j, n, num, kase=1;
    multiset<int> lowerHalf, upperHalf;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &i, &n);
        lowerHalf.clear();
        upperHalf.clear();
        printf("%d %d\n", kase++, n/2+1);

        for(i=0, j=0; i<n; i++) {
            scanf("%d", &arr[i]);
            if (lowerHalf.size()==(n+1)/2 && getLastElement(lowerHalf) <= arr[i])
                upperHalf.insert(arr[i]);
            else
                lowerHalf.insert(arr[i]);

            while (lowerHalf.size() > (i+1)/2)
                upperHalf.insert( popLastElement( lowerHalf ));
            while (upperHalf.size() > i/2)
                lowerHalf.insert( popFirstElement( upperHalf ));

            if(i%2==0){
                printf("%d", getLastElement(lowerHalf));
                j++;
                if(j%10==0) printf("\n");
                else if(i<n-2) printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
