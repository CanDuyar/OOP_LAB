#include <iostream>
using namespace std;

class NegativeDeposit{ // NegativeDeposit class
 	/*Intentionally Empty*/
};

class InsufficientFunds{ //InsufficientFunds
	/*Intentionally Empty*/
};

class Account{ // Account class
	public:
		Account(){balance = 0;} // default constructor
		Account(double initialDeposit){balance = initialDeposit;} // constructor with parameter
		~Account(){/*Body Intentionally Empty*/} //destructor
		double getBalance()const{return balance;} // getter for balance
		double deposit(double amount); 
		double withdraw(double amount);

	private:
		double balance;

};


double Account::deposit(double amount){
	if (amount > 0)
		balance += amount;
	else
		throw NegativeDeposit(); // throw
	
	return balance;
}

double Account::withdraw(double amount){
	if ((amount > balance) || (amount < 0))
		throw InsufficientFunds(); // throw
	else
		balance -= amount;

	return balance;

}

	/* TEST */
int main(int argc, char const *argv[]){
		Account money(100);

		
		// TEST OF NEGATIVE DEPOSIT 
		try{
			cout << "\nTest of negative deposit" << endl;
			cout << "Depositing -85" << endl;
			cout << "New balance: " << money.deposit(-85) << endl;
			
		}

		catch (NegativeDeposit){
			cout << "You entered negative deposit amount!!!." << endl;
		}		


		//TEST OF INSUFFICIENT FUNDS
		try{
			cout <<"\n\nTest of insufficient funds" << endl;
			cout << "\nDepositing 30" << endl;
			cout << "New balance: " << money.deposit(30) << endl;
			cout << "Withdraw 75" << endl;
			cout << "New balance: " << money.withdraw(75) << endl;
			cout << "Withdraw 1000" << endl;
			cout << "New balance: " << money.withdraw(1000) << endl;
		}

		catch (InsufficientFunds){
			cout << "You don't have enough money to withdraw." << endl << endl;
		}



		return 0;
	}
