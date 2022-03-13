#include "Administrator.h"
#include "Security.h"

#include <string>
using namespace std;

bool Administrator::Login(string username, string password){
	if(Security::validate(username,password) == 2)
		return true;
	else
		return false;
}
