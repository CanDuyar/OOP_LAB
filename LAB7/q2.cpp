#include <iostream>
#include <string>

using namespace std;

// CAN DUYAR 171044075

class Student{ //Student class
public:
	Student(); //constructor
	~Student(); // destructor - It releases all memory that has been allocated.
	void resetStudent();
	void studentInput();
	void output();
	string getName()const;
	int getnumClasses()const;
	string* getClassList()const;
	void setName(const string nameSet);
	void setnumClasses(const int classNum);
	void setClassList(string* cl); // cl means class list
	Student& operator=(const Student& param);

private:
	string name; // A string that stores the name of the student
	int numClasses; //An integer that tracks how many courses the student is currently enrolled in
	string *classList; //A dynamic array of strings used to store the names of the classes that the student is enrolled in
};

Student::Student(){
	studentInput();
}

void Student::resetStudent(){
	numClasses = 0; 
	delete[] classList;
    classList = NULL;
}

Student::~Student() {
	resetStudent(); 
}

string Student::getName()const{
	return name;
}

int Student::getnumClasses()const{
	return numClasses;
}

string* Student::getClassList()const{
	return classList;
}

void Student::setName(const string nameSet){
	name = nameSet;
}

void Student::setnumClasses(const int classNum){
	numClasses = classNum;
}
void Student::setClassList(string* cl){
	classList = cl;
}


void Student::output(){
	cout <<"\nName: " << getName() << endl;
	cout <<"\nList of all courses:" << endl;
	
	for(int u = 0; u < getnumClasses(); u++)
		cout << classList[u] << endl;

}

Student& Student::operator =(const Student& param) // Assignment operator overloading
{ 
    resetStudent(); 
    numClasses = param.numClasses; 
    if (numClasses > 0) { 
        classList = new string[numClasses+1]; 
        for (int t = 0; t < numClasses;++t) { 
            classList[t] = param.classList[t]; 
        } 
    } 

    return *this; 
} 

void Student::studentInput(){
	cout << "\nEnter student's name" << endl;
	cin >> name;
	cout << "Enter the number of classes" << endl;
	cin >> numClasses;
	classList = new string[numClasses+1];

	cout << "\nEnter the class list" << endl;

	for(int t = 0; t < numClasses;++t)
		cin >> classList[t];
}


int main(int argc, char const *argv[])
{
	Student student1,student2;
	cout << endl;
    cout << "Output of student1:\t";
    student1.output();
    
    student2 = student1;

    cout << endl;

    cout << "Output of student2 after assignment operator(student2 = student1):\t";
    student2.output();
    cout << endl;
	
	return 0;
}