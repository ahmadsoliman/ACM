#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
        int t ;
        cin >> t;
		int m[t]; 
        int n[t];
		int higherLimit = 0;
		int max = 0;

		for (int i = 0; i < t; i++) {
            int a;
            int b;
            scanf("%d %d",&a,&b);
			m[i] = a;
			n[i] = b;
			if (n[i] > higherLimit*higherLimit)
				higherLimit = n[i];
			if (n[i] > max)
				max = n[i];
		}
		max++;
		int arr[max];
		for (int i = 0; i < max; i++) {
			arr[i] = 1;
		}
		
		arr[0] = 0;
		arr[1] = 0;
		
		for (int i = 2; i < higherLimit; i++) {
			if (arr[i]==0)
				continue;
			for (int j = 2; j * i < max; j++) {
				arr[i*j] = 0;
			}
		}

		for (int i = 0; i < t; i++) {
			for (int j = m[i]; j <= n[i]; j++) {
				if (arr[j]) {
					cout << j;
					cout << "\n";
				}
			}
            if(i!=t-1)cout << "\n";
		}
    system("PAUSE");
    return EXIT_SUCCESS;
}
