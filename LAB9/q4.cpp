#include <iostream>
using namespace std;


void move(int count,int n1,int n3,int n2){
	if(count > 0){
		move(count-1,n1,n2,n3);
		cout << "Disk-" << count << ":  " << n1 << "---->" << n3 << endl;
		move(count-1,n2,n3,n1);
	}
}


int main(int argc, char const *argv[])
{
	int num;
	cout << "enter the number of disks: ";
	cin >> num;
	cout << endl;
	move(num,1,2,3);
	return 0;
}