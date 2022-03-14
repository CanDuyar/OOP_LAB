#include <iostream>

using namespace std;

template <class T> //template
T absoluteValue(T t, T t2){
	if(t > t2)
		return (t-t2);
	
	else
		return(t2-t);
}


	/* TEST */
int main(int argc, char const *argv[]){

	int in1,in2;
	double do1,do2;

	in1 = 25;
	in2 = 35;
	cout << "\nInteger Test";
	cout << "\nAbsolute value of 25,35 = " << absoluteValue(in1,in2) << endl;

	do1 = 23.4;
	do2 = 7.1;
	cout << "\nDouble Test" << endl;
	cout << "Absolute value of 23.4, 7.1 = " << absoluteValue(do1,do2) << endl << endl;


	return 0;
}