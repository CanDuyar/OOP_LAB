#include "User.h"
#include "Security.h"

#include <string>
using namespace std;

bool User::Login(string username, string password){
	if(Security::validate(username,password) != 0)
		return true;
	else
		return false;
}
