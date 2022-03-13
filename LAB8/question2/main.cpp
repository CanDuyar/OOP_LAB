#include <iostream>
#include "password.h"
#include "user.h"

using namespace Authenticate;
using namespace std;

int main(int argc, char const *argv[])
{
	Password pas;
	User us;

	cout << endl;
	us.inputUserName( );
	cout << endl;
	pas.inputPassword( );
	cout << endl;
	cout << "Your username is " << us.getUserName( ) <<
	" and your password is: " << pas.getPassword( ) << endl;

	return 0;
}