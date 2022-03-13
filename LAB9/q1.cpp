#include <iostream>
using namespace std;

int fibo(int n) { // function to find n.th fibonacci number
   if((n==1)||(n==0))
      return 1;
   
   return(fibo(n-1)+fibo(n-2));
   
}

/* TEST */
int main() {
   int t,i=0;
   while(i < 5){ // try with 5 numbers...   
   cout << "\nEnter the N value for fibonacci series to find the Nth term:" << endl;
   cin >> t;
   
      cout << "F" << t << " = " << fibo(t) << endl;
      i++;
   }
   return 0;
}