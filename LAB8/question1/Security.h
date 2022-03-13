#ifndef SECURITY_H
#define SECURITY_H

#include <string>
using namespace std;

class Security{

public:
static int validate(string username, string password);
// This subroutine hard-codes valid users and is not
// considered a secure practice.
// It returns 0 if the credentials are invalid,
// 1 if valid user, and
// 2 if valid administrator

};

#endif
