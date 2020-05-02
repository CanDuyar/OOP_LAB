#include <iostream>
#include <cstdlib>

using namespace std;

class Rational{ // Rational class
public:
    Rational(); // default constructor
    Rational (int wholeNumber); // constructor with one parameter
    Rational (int m, int n); // constructor with two parameters
    //GETTERS
    int getNum()const{return num;}
    int getDenom()const{return denom;}
    //SETTERS
    void setNum(const int n){this->num = n;}
    void setDenom(const int den){this -> denom = den;}
    void check();
    //OPERATOR OVERLOADING
    bool operator==(const Rational& rati);
    bool operator>=(const Rational& rati);
    bool operator<=(const Rational& rati);
    bool operator>(const Rational& rati);
    bool operator<(const Rational& rati);
    Rational operator+(const Rational& rati)const;
    Rational operator-(const Rational& rati)const;
    Rational operator*(const Rational& rati)const;
    Rational operator/(const Rational& rati)const;

private:
    int num;     // numerator
    int denom;   // denominator
    friend ostream& operator <<(ostream& outs, const Rational& rati); // << operator overloading
    friend istream& operator >>(istream& ins, Rational& rati); // >> operator overloading

};

Rational::Rational() : num(0),denom(1){
    /*Body Initially Empty*/
}

Rational::Rational (int wholeNumber):denom(1){
    num = wholeNumber;
}


Rational::Rational (int n, int d)
{
	num = n;
	denom = d;
}


void Rational::check() // to check validity
{
    if (denom < 0)
    {
		denom = denom*(-1);
		num = num*(-1);

    }
    else if (denom == 0){ //UNDEFINED
        cout << "Denominator cannot be zero" << endl;
        exit(1);
    }
}

ostream& operator <<(ostream& output, const Rational& rati) {	

	if (rati.denom < 0)  
		output << (-1)*(rati.num) << "/" << (-1)*(rati.denom); 
     
    else
		output << rati.num << "/" << rati.denom;

	return output;
}

istream& operator >>(istream& input, Rational& rati) {

	char temp; 
	input >> rati.num >> temp >> rati.denom;
	rati.check();
	return input;

}


bool Rational::operator==(const Rational& rati){
    return (num == rati.num && denom == rati.denom);
}

bool Rational::operator>=(const Rational& rati){
    return (num*rati.denom >= denom*rati.num);
}


bool Rational::operator<=(const Rational& rati){
    return (num*rati.denom <= denom*rati.num);
}

bool Rational::operator>(const Rational& rati){
    return (num*rati.denom > denom*rati.num);
}

bool Rational::operator<(const Rational& rati){
    return (num*rati.denom < denom*rati.num);
}

Rational Rational::operator*(const Rational& rati)const{
    Rational r;
    r.num = num*rati.num;
    r.denom = denom*rati.denom;
    return r;
}

Rational Rational::operator/(const Rational& rati)const{
    Rational r;
    r.num = num*rati.denom;
    r.denom = denom*rati.num;
    return r;
}

Rational Rational::operator+(const Rational& rati)const{
    Rational rat;
    rat.num = num*rati.denom + rati.num*denom;
    rat.denom = denom* rati.denom;
    return rat;    
}

Rational Rational::operator-(const Rational& rati)const{
    Rational rat;
    rat.num = num*rati.denom - rati.num*denom;
    rat.denom = denom* rati.denom;
    return rat;    
}


/*  TEST  */
int main (){
    int n, d;        
    Rational rat1,rat2,rat3,rat4;

        cout << "Enter 4 rational numbers (n/d)): ";
        cin >> rat1 >> rat2 >> rat3 >> rat4;
        cout << endl;

        cout << "rational1 : " << rat1 << endl;
        cout << "rational2 : " << rat2 << endl;
        cout << "rational3 : " << rat3 << endl;
        cout << "rational4 : " << rat4 << endl;

        cout << "\nOPERATOR OVERLOADING TEST" << endl;
        cout << " " << rat1 << " + " << rat2 << " = " << (rat1 + rat2) << endl;
        cout << " " << rat3 << " - " << rat4 << " = " << (rat3 - rat4) << endl; 
        cout << " " << rat1 << " / " << rat3 << " = " << (rat1 / rat3) << endl;
        cout << " " << rat3 << " * " << rat4 << " = " << (rat3 * rat4) << endl;
        cout << endl;

        cout <<"rational1 < rational2 ?" << "---->  " << (rat1 < rat2) << endl;
        cout <<"rational2 == rational4 ?" << "---->  " << (rat2 == rat4) << endl;
        cout <<"rational4 >= rational3 ?" << "---->  " << (rat4 >= rat3) << endl;
        cout <<"rational3 > rational1 ?" << "---->  " << (rat3 > rat1) << endl;
        cout <<"rational2 <= rational4 ?" << "---->  " << (rat2 <= rat4) << endl;

    return 0; 
}
