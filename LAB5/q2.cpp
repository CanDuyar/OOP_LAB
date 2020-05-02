#include <iostream>

using namespace std;

class MyInteger{ //MyInteger class
public:	
	MyInteger(){setInteger(0);} // no-parameter constructor
	MyInteger(int number){setInteger(number);} // constructor ->I used setter in these constructors.
	void setInteger(const int val){this->value = val;} //SETTER
	int getInt()const{return this->value;}  //GETTER
	int digitNumber(int numb); //to find number of digits
	int operator[](int i); // [] operator overloading

private:
	int value;
};

int MyInteger::digitNumber(int numb){
	int digit_num = 0;
	while(numb > 0){
		numb/=10;
		digit_num++;
	}
	return digit_num;
}

int MyInteger::operator[](int digit){
	int temp = value;
	int result=digitNumber(value)-digit; 
	while(digitNumber(value)>result){
		temp /=10;                  
		result++;
	}
		temp%=10;
		if(digitNumber(value)>digit) // if total digit number > parameter then returns temp.
			return temp;
		else  //if total digit number <= parameter then returns -1
			return -1;
}
              /*   TEST  */
int main(int argc, char const *argv[])
{
	MyInteger exp1(458),exp2(171044);

	cout << "TEST - 458" << endl;
	cout << "0 ---> " << exp1[0] << endl;
	cout << "1 ---> " << exp1[1] << endl;
	cout << "2 ---> " << exp1[2] << endl;
	cout << "3 ---> " << exp1[3] << endl;
	cout << endl;

	cout << "TEST - 171044" << endl;
	cout << "0 ---> " << exp2[0] << endl;
	cout << "1 ---> " << exp2[1] << endl;
	cout << "2 ---> " << exp2[2] << endl;
	cout << "3 ---> " << exp2[3] << endl;
	cout << "4 ---> " << exp2[4] << endl;
	cout << "5 ---> " << exp2[5] << endl;
	cout << "6 ---> " << exp2[6] << endl;
	cout << endl;
	

	return 0;
}