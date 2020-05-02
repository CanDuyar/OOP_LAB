#include <iostream>

using namespace std;

struct Student{
	double midterm;
	double final;
	double quiz1,quiz2;	
};

void init(Student &Record){
	Record.midterm = 0;
	Record.final = 0;
	Record.quiz1 = 0;
	Record.quiz2 = 0;
}


void input(Student &Record){
	cin >> Record.quiz1 >> Record.quiz2 >> Record.midterm >> Record.final;

	if((Record.quiz1+Record.quiz2)>20 || Record.midterm >100 || Record.midterm < 0 || Record.final > 100 || Record.midterm < 0){
		cout << "Invalid input" << endl;	
		exit(1);
	}
}


void showResults(Student &Record){
	cout << Record.quiz1 << " " << Record.quiz2 << " " << Record.midterm << " " << Record.final << " ";
}


double findAverage(Student &Record){
	double average;
	average = ((Record.quiz1+Record.quiz2)/2)*(2.5) + (Record.midterm)*(0.25) + (Record.final)*(0.5);
	return average;
}

char letterGrade(double avg){
	if(avg >= 90.0 && avg <=100.0)
		return 'A';
	else if(avg >= 80.0 && avg < 90.0)
		return 'B';
	else if(avg >= 70.0 && avg < 80.0)
		return 'C';
	else if(avg >= 60.0 && avg < 70.0)
		return 'D';
	else
		return 'F'; 
}


int main(int argc, char const *argv[])
{
	Student example;
	int count = 1;
	double average;

	init(example);
	
	while(count <= 5){
		cout << count << " ";
		input(example);
		cout << count << ".student's record:" << endl;
		showResults(example);	
		average = findAverage(example);
		cout << average << " " << letterGrade(average) << endl;
		cout << endl;
		count++;
	}
	
	return 0;
}