/*j ID: ahmadad1
PROG: fence8
LANG: C++
*/

#include <cstdlib>
#include <fstream>
#include <algorithm>
#include <iostream>

using namespace std;

const int maxboard=50+1;
const int maxrail=1023+1;

// the arrays contains rails and boards lenght's
int rail[maxrail], board[maxboard];

// the array contains how much of the i_th board remain for cutting the rails from
int remain[maxboard];

// number of boards and rails
int nboard, nrail;

// sumlen[i] contains sum of the length of first i rails in the case
// that rails are in the sorted order

int sumlen[maxrail];

// minindex[i] contains the index of smallest board that i_th rail
// can cut from it(rails and boards are in the sorted order)
int minindex[maxrail];

//amount of board that 'can' be waste during one run of DSF
long long maywaste;

//amount of board that waste yet
int waste;

//best solution that we want to find
int best;

ifstream fin("fence8.in");
ofstream fout("fence8.out");


//r is the rail that we want cut from board index1 or index1+1 or ... or nboard-1
void DFS(int r, int index1){

   //if r is equal to 0 we must search for the last step of solution
   if (r == 0) {
       for (int i=index1; i<nboard; ++i)
           if (remain[i]>=rail[0]){

               //if we can cut best+1 rails, we print the solution
               fout << best+1 << endl;
               fout.close();
               exit(0);
           }
       return;
   }


   for (int i=index1; i<nboard; ++i)

       //for cutting r_th rail from i_th board this condition must hold
       if (remain[i]>=rail[r]) {
           int oldwaste=waste;
           remain[i]-=rail[r];

    //now we check if i_th board being useless, amount of
    // wasted board must be less than 'maywaste'
           if (remain[i]<rail[0] && waste+remain[i]>maywaste) {
               remain[i]+=rail[r];
               continue;
           }

           // if i_th board being useless we must update 'waste'
           if (remain[i]<rail[0]) waste+=remain[i];

    // now we check if two rails have equal size, then the
    // usage of board for them must be in non-decreasing order

           if (rail[r-1] == rail[r]) DFS(r-1, i);
           else DFS(r-1, minindex[r-1]);

           // at last we set the initial state again
           remain[i]+=rail[r];
           waste=oldwaste;
       }
}

int main() {

   // reading the input and compute sum of the boards length's,
   // also set the initial state of 'remain'

   fin >> nboard;
   long long sum=0;
   for (int i=0; i<nboard; ++i) {
       fin >> board[i];
       sum+=board[i];
       remain[i]=board[i];
   }
   fin >> nrail;
   for (int i=0; i<nrail; ++i)
       fin >> rail[i];
   fin.close();

   // sort the rails and boards
   sort(&board[0], &board[nboard]);
   sort(&rail[0], &rail[nrail]);

   // set maximum number of rails that we want to use, with out loss anything
   int temp=0;
   sumlen[0]=rail[0];
   for (; temp<nrail && sumlen[temp]<=sum; ++temp, sumlen[temp]=sumlen[temp-1]+rail[temp]);
   nrail=temp;

   // set minindex array
   for (int i=0, j=0; i<nrail; ++i) {
       while (j<nboard && rail[i]>board[j]) j++;
       minindex[i]=j;
       if (j == nboard) {
           nrail=i;
           break;
       }
   }

   // check out one special case
   if (nrail == 0) {
       fout << 0 << endl;
       fout.close();
       return 0;
   }

   // main part of code that use DFS+ID
   for (int i=nrail-1; i>=0; --i){
       waste=0;
       maywaste=sum-sumlen[i];
       best=i;
       DFS(i, minindex[i]);
   }
}
