#include <iostream>
using namespace std;

class PrimeNumber{
public:
    PrimeNumber(); //No-parameter constructor 
    PrimeNumber(int numberValue); //Constructor
    int getNumber()const;  //getter
    PrimeNumber operator ++(int); //post increment operator overloading
    PrimeNumber operator --(int); //post decrement operator overloading
private:
    int data;
    bool checkPrime(int is_prime); //if a number which is given as parameter is prime number then returns true. otherwise returns false.
    int nextPrimeNumber(int numb); // to find next prime number
    int previousPrimeNumber(int numb); // to find previous prime number
};

PrimeNumber::PrimeNumber() : data(1){
    /*Intentionally empty*/
}

PrimeNumber::PrimeNumber(int n) : data(n){
    /*Intentionally empty*/   
}

int PrimeNumber::getNumber() const{ // getter
     return data;
}
    
bool PrimeNumber::checkPrime(int is_prime){ 
    bool value = true; 
    for(int t = is_prime/2; t>1; t--){
        if(is_prime % t == 0){
            value = false; //it means nonprime number.
            break;
        }
    }
    return value; 
}
int PrimeNumber::nextPrimeNumber(int numb){
    int next = 0;
    while(true){
        numb++; //go to next number
        if(checkPrime(numb)){
            next = numb;
            break;
        }
    }
    return next;
}

int PrimeNumber::previousPrimeNumber(int numb){
    int previous = 0;
    while(true){
        numb--; // go to previous number
        if(checkPrime(numb)){
            previous = numb;
            break;
        }
    }
    return previous;
}


PrimeNumber PrimeNumber::operator ++(int){
    PrimeNumber inc;
    inc.data = nextPrimeNumber(data);
    return inc;
}

PrimeNumber PrimeNumber::operator --(int){
    PrimeNumber dec;
    dec.data = previousPrimeNumber(data);
    return dec;
}
               /* TEST */
int main(){
    PrimeNumber p1(13),p2(59), previous,next;
    next = p1++;
    previous = p1--;
    cout <<"PRIME NUMBER = 13" << endl;
    cout << "Next ---> " << next.getNumber() << endl;
    cout << "Previous-----> " << previous.getNumber()<< endl;
    cout << endl;
    next = p2++;
    previous= p2--;
    cout <<"PRIME NUMBER = 59" << endl;
    cout << "Next ---> " << next.getNumber() << endl;
    cout << "Previous-----> " << previous.getNumber()<< endl;
    return 0;
}