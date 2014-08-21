#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main1(int argc, char *argv[])
{
    int t ,i,j , minJ, len;
    cin >> t;
	
    string in, minS, tempS;	
	for(i =0; i<t; i++){
          cin >> in;
          
          len = in.length();
    		minS = in;
    		minJ=0;
    		for (j = 1; j < len; j++) {
    			tempS = in.substr(j)+in.substr(0,j);
    			if(tempS.compare(minS)<0){
    				minS = tempS;
    				minJ=j;
    			}
    		}
    		cout << minJ+1;
            cout << "\n";
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
