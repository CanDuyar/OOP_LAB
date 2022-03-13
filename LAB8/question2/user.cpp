#include <iostream>
#include <string>
#include <cctype>
#include "user.h"

using namespace std;

namespace Authenticate{

void User::inputUserName( ){
	do{
		cout << "Enter your username (8 letters only)" << endl;
		cin >> username;
	}while (!isValid());
}

string User::getUserName( ){
	return username;
}

bool User::isValid(){
	int count = 0;

	for(int i = 0; username[i]!='\0'; i++){
		if(isalpha(username[i]))
			count++;
	}


	if(username.length() == 8 && count == 8)
		return true;
	else
		return false;
}
	

}