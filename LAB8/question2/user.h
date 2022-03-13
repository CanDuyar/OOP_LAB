#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

namespace Authenticate{

class User{

public:
	bool isValid(); 
	void inputUserName();
	string getUserName();

private:
	string username;


};

}
 #endif