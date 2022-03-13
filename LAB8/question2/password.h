#ifndef PASSWORD_H
#define PASSWORD_H

#include <string>
using namespace std;
namespace Authenticate{
class Password{

public:
	bool isValid(); 
	void inputPassword();
	string getPassword();

private:
	string password;


};

}
 #endif