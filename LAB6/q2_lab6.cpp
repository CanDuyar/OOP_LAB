#include <iostream>
#include <cstdlib>

using namespace std;

class CharPair{
	public:
		CharPair(); // default constructor
		CharPair(int sz); // constructor with 1 parameter
		CharPair(int sz, char arr[]); //constructor with 2 parameter
		int getSize()const{return size;} //accessor function
		void setSize(const int szee){this->size = szee;} // setter
		char& operator[](int index);

	private:
		int size;
		char array[100];	 
};

int main(int argc, char const *argv[])
{

	cout <<"\nTEST - A" << endl;
	CharPair b;
	cout << "initial size value which is returned by accessor function = " << b.getSize() << endl;
	cout << "First 10 char:" << endl;
	for(int t = 0; t < 10; t++)
		cout << b[t] << " ";
	cout << endl;
 
	cout << "\nTEST - B (b[1] = 'A' and b[2] = 'B')" << endl;
	b[1] = 'A';
	b[2] = 'B';
	cout << "b[1] =  "<< b[1] << endl;
	cout << "b[2] =  "<< b[2] << endl;

	cout << "\nTEST - C" << endl;
	cout << "\nAfter CharPair c(2) )" << endl;
	CharPair c(2);
	cout << "c[0] =  "<< c[0] << endl;
	cout << "c[1] =  "<< c[1] << endl;

	cout << "\nTEST - D  (CharPair d(2,arr))" << endl;
	int sz = 2;
	char arr[2] = {'g','t'};
	CharPair d(sz,arr);
	
	cout << "d[0] =  " << d[0] << endl;
	cout << "d[1] =  " << d[1] << endl;	

	

	return 0;
}


char& CharPair::operator[](int index){
	return array[index];
	
}

CharPair::CharPair():size(10) {
	for(int i = 0; i < size; i++)
		array[i] = '#';
}


CharPair::CharPair(int sz){
	for(int t = 0; t < sz; t++)
		array[t] = '#';
	size = sz;
}

CharPair::CharPair(int sz, char *arr){
	//error check
	if(sz > 100){
		cout << "ERROR: Size cannot be greater than size of array!!!" << endl;
		exit(1);
	}
	//error check
	else if(sz <= 0){
		cout << "ERROR: size of array must be greater than 0!!!" << endl;
		exit(1);
	}


	for(int g = 0; g < sz; g++)
		array[g] = arr[g];
	size = sz;
}

