#include <iostream>
#include <string>

#include "Security.h"
#include "Administrator.h"
#include "User.h"

using namespace std;


/* TEST */
int main(int argc, char const *argv[])
{
	string userName;
	string password;
	Administrator admin;
	User us;

	cout <<"\nEnter a  username:" << endl;
	cin >> userName;
	cout <<"\nEnter a  password:" << endl;
	cin >> password;

	if(admin.Login(userName,password)){
		cout << "\nYeeyy! You are an Admin :)" << endl;
	}

	else if(us.Login(userName,password)){
		cout <<"\nYou are a User :)" << endl;
	}

	else{
		cout << "\nYou're nothing!!!" << endl;
	}
	
	cout << endl;

	return 0;
}