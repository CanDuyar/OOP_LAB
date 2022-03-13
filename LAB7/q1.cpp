#include<iostream>
#include<string>

using namespace std;

//CAN DUYAR  - 171044075

void Inverse(string str){
	
	char *head, *tail, *cp; //cp means char pointer
	cp = new char[str.size()+1]; //dynamic memory allocation

	for(int i = 0; i < str.size(); ++i){  //to copy
		cp[i] = str[i]; 
	}

	tail = &cp[str.size() - 1]; // tail
	head = &cp[0]; // head 

	char keep; // I used it two swap to characters 
	int count = 0;
	
	do{
		keep = cp[count];
		cp[count] = *tail;
		*tail = keep;
		*tail--; // tail decreased
		*head++; // head increased
		count++; // count increased to swap all characters of the char array
	}while (head <= tail);
	
	cout << "Reversed String: "; 
	cout << cp << endl; //cp is reversed string

}

/* TEST */
int main() {

	string str;
	cout << "Enter a string: ";
	getline(cin,str);
	
	Inverse(str);
	
	return 0;
}

