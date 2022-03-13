#include <iostream>
#include <string>

using namespace std;

class Payment{ // Payment class

public:
	Payment():amount_payment(0){ /* Body Intentionally Empty */ } // default constructor
	Payment(float amount):amount_payment(amount){/* Body Intentionally Empty */} //constructor with parameter
	float getAmount()const{return this->amount_payment;} //getter for amount of payment
	void setAmount(const float amount){this->amount_payment = amount;} // setter for amount of payment
	void paymentDetails(); // to show payment details

private:
	float amount_payment;

};


class CashPayment : public Payment{ // CashPayment class which is derived from Payment
public:
	CashPayment(); //default constructor
	CashPayment(float cashAmount); // constructor with parameter
	void paymentDetails(); // to show payment details
};

class CreditCardPayment : public Payment{ // CreditCardPayment class which is derived from Payment
public:
	CreditCardPayment(); // default constructor
	CreditCardPayment(float creditAmount, string ccpNameOnCard,string ccpExpirationDate, string ccpCardNumber); //constructor with paramater
	void paymentDetails(); //to show payment details

private: 
	string nameOnCard;
	string expirationDate;
	string cardNumber;

};


void Payment::paymentDetails(){
	cout << "Amount of payment: $" << amount_payment << endl;
}

CashPayment::CashPayment() : Payment(){
	/* Body Intentionally Empty */
}

CashPayment::CashPayment(float cashAmount) : Payment(cashAmount){
	/* Body Intentionally Empty */
}

void CashPayment::paymentDetails(){
	cout << "Amount of cash payment: $" << getAmount() << endl;
}

CreditCardPayment::CreditCardPayment(): Payment(), nameOnCard(""), expirationDate(""), cardNumber(""){
	/* Body Intentionally Empty */
}

CreditCardPayment::CreditCardPayment(float amount,string ccpNameOnCard, string ccpExpirationDate, string ccpCardNumber)
  :Payment(amount), nameOnCard(ccpNameOnCard),expirationDate(ccpExpirationDate), cardNumber(ccpCardNumber)
{
	/* Body Intentionally Empty */
}

void CreditCardPayment::paymentDetails(){
	cout << "Credit card payment's Amount: $" << getAmount() << endl;
	cout << "Name on the credit card: " << nameOnCard << endl;
	cout << "Expiration date: " << expirationDate << endl;
	cout << "Credit card number: " << cardNumber << endl;	
}

/* TEST */
int main()
{
	CashPayment cash(250.75);
	CashPayment cash2(113.50);
	CreditCardPayment credit(100.50, "CAN", "12/12/2022","101011010");
	CreditCardPayment credit2(99.9, "IPEK", "08/11/2024" ,"001010101");

	cout << "CASH PAYMENT - 1" << endl;
	cash.paymentDetails();
	
	cout << "\nCASH PAYMENT - 2" << endl;
	cash2.paymentDetails();
	
	cout << "\nCREDITCARD PAYMENT - 1" << endl;
	credit.paymentDetails();
	
	cout << "\nCREDITCARD PAYMENT - 2" << endl;
	credit2.paymentDetails();
		
	return 0;
}