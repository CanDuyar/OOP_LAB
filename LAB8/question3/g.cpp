#include <iostream>

#include "g.h"

using namespace std;

//definition of g() in Namespace A

namespace A{
	void g(){ //sum of squares
		int num1,num2,sum;
		cout << "\nSum of Squares in g()" << endl;
		cout << "\nEnter the value of number1:" << endl;
		cin >> num1;
		cout << "\nEnter the value of number2:" << endl;
		cin >> num2;

		sum = num1*num1 + num2*num2;
		cout << "g() of namespace A is called" << endl;
		cout << "\nSum of Squares:  " << sum << endl;

	} //end of the function 

} // end of the namespace