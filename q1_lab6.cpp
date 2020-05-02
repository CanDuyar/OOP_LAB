#include <iostream>

using namespace std;

class Complex{ // Complex class

public:
	//CONSTRUCTORS
	Complex(); //default constructor
	Complex(double real_part); // constructor with one parameter
	Complex(double real_part,double imag_part); //constructor with two parameters
	//GETTERS
	double getReal()const { return real;}
	double getImaginary()const {return imaginary;}
	//SETTERS
	void setImaginary(const double imag){this->imaginary = imag;}
	void setReal(const double real){this->real = real;}
	//OPERATOR OVERLOADING
	bool operator==(const Complex& compare);
	Complex operator+(const Complex& num)const;
	Complex operator-(const Complex& num)const;
	Complex operator*(const Complex& num)const;
	
private:
	double real;
	double imaginary;
	friend ostream& operator << (ostream& output,const Complex &num); // << overloading
	friend istream& operator >> (istream& input,const Complex &num); // >> overloading

};


Complex::Complex(double real_part,double imag_part){
	real = real_part;
	imaginary = imag_part;
}

Complex::Complex(double real_part){
	real = real_part;
	imaginary = 0.0; 
}

Complex::Complex():real(0),imaginary(0){ //Default Constructor
	/*Body Intentionally Empty*/
}

bool Complex::operator==(const Complex& compare){
	if(real == compare.real && imaginary == compare.imaginary)
		return true;
	else
		return false;
}

Complex Complex::operator +(const Complex& num)const{
	Complex temp;
	temp.real = real + num.getReal();
	temp.imaginary = imaginary + num.getImaginary();
	return temp;
}

Complex Complex::operator -(const Complex& num)const{
	Complex temp;
	temp.real = real - num.getReal();
	temp.imaginary = imaginary - num.getImaginary();
	return temp;
}

Complex Complex::operator*(const Complex& num)const{
	const Complex i(0,1); //value of i
	Complex temp;
	temp.real = real*num.getReal() 
	+ imaginary*num.getImaginary()*i.getImaginary()*(-1); // -1 comes from i^2
	
	temp.imaginary = real*num.getImaginary()*i.getImaginary() + imaginary*num.getReal();

	 return temp;
}

ostream& operator<<(ostream& output,const Complex &num){
	char sign;
	output << num.real;
	
	if(num.imaginary >= 0){
		sign = '+';
		output << sign << num.imaginary << "i" << endl;
	}
	else
		output << num.imaginary << "i" << endl;	
	return output;
}

istream& operator>>(istream& input,Complex &num){
	double real,imaginary;
	cout << "Enter Real and Imaginary Part ";
	input >> real >> imaginary;
	num.Complex::setReal(real);
	num.Complex::setImaginary(imaginary);
	
	return input;

}

   /*   TEST    */
int main(int argc, char const *argv[])
{
	Complex c(5, 7);
	Complex com(3,2);
	Complex com2; //0+0i as default

	cout << "\nADD" << endl;
	cout << "(5+7i) + (3+2i)   =  " << c+com << endl;


	cout << "\nSUBSTRACT" << endl;
	cout << "(5+7i) - (3+2i)   =  " << c-com << endl;

	cout << "\nMULTIPLICATION" << endl;
	cout << "(5+7i) * (3+2i)   =  " << c*com << endl;
	

	cout << "\n >> OPERATOR OVERLOADING " << endl;
	cin >> com2;
	cout << "\nThe Complex number is : " << endl;
	cout << com2;

	return 0;
}