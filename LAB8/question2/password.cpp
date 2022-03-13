#include <iostream>
#include <string>
#include <cctype>
#include "password.h"

using namespace std;

namespace Authenticate{
void Password::inputPassword(){
	do{
		cout << "Enter your password (at least 8 characters " <<
		"and at least one non-letter)" << endl;
		
		cin >> password;
	}while (!isValid( ));
}
string Password::getPassword(){
	return password;
}

bool Password::isValid(){
	int count = 0;

	for(int i = 0; password[i]!='\0'; i++){
		if(isalpha(password[i]))
			count++;
	}


	if(password.length() >= 8 && password.length()-count!=0)
		return true;
	else
		return false;
}

}