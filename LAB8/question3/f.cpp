#include <iostream>

#include "f.h"

using namespace std;

//definition of f() in Namespace A

namespace A{
	void f(){ //swap
		int num1,num2,temp;
		cout << "Swapping of numbers in f()" << endl;
		cout << "\nEnter the value of number1:" << endl;
		cin >> num1;
		cout << "\nEnter the value of number2:" << endl;
		cin >> num2;

		temp = num1;
		num1 = num2;
		num2 = temp;

		cout << "f() of namespace A is called" << endl;
		cout << "\nNumber1:  " << num1 << endl;
		cout << "\nNumber2:  " << num2 << endl;

	} //end of the function 

} // end of the namespace