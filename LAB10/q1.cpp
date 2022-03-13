#include <iostream>
#include <string>

using namespace std;

class Person{ // Person class
public:
	Person(); // default constructor
	Person(string owner_name); // constructor with parameter
	Person(const Person& obj); //constructor with parameter
	string getName()const; //getter for name
	Person& operator=(const Person& assign); //assignment operator overloading
	friend istream& operator>>(istream& in,	Person& obj); // >> operator overloading 
	friend ostream& operator<<(ostream& out,const Person& obj); // << operator overloading

private:
	string name;
};

class Vehicle{  //Vehicle class
public:
	Vehicle(); // default constructor
	Vehicle(const string& manufacturer, int cylinders,const Person& owner_obj);// constructor with parameter
 	Vehicle(const Vehicle& obj); // constructor with parameter
	Vehicle& operator=(const Vehicle& obj);//assignment operator overloading
	//GETTERS
	string getManufacturer()const;
	int getCylinders()const;
	Person getOwner()const;
	//SETTERS
	void setManufacturer(const string& manufacturer);
	void setCylinders(const int cylinders);
	void setOwner(const Person& owner_obj);
	
	void show_details();

private:
	string manufacturer_name;
	int number_cylinders;
	Person owner;
};


class Truck : public Vehicle{
public:
	Truck();// default constructor
	Truck(string manufacturer , int cylinders,const Person& owner_obj, double capacity_load, int capacity_towing);// constructor with parameter
	Truck(const Truck& obj); // constructor with parameter
	Truck& operator=(const Truck& obj);//assignment operator overloading
	//GETTERS
	double getCapacityLoad()const;
	int getCapacityTowing()const;
	//SETTERS
	void setCapacityLoad(const double capacity_load);
	void setCapacityTowing(const int capacity_towing);
	
	void show_details();

private:
	double capacityL; // load capacity
	int capacityT; // towing capacity
};



Person::Person(){
	name = " ";
}

Person::Person(string owner_name) : name(owner_name){
	/*Body Intentionally Empty*/
}

Person::Person(const Person& obj) : name(obj.name){
	/*Body Intentionally Empty*/	
}
	
string Person::getName()const{
	return name;
}

Person& Person::operator=(const Person& assign){
	this->name = assign.name;
	return *this;
}

istream& operator >> (istream& in, Person& obj){
	in >> obj.name;
	return in;
}

ostream& operator<<(ostream& out, const Person& obj){
	out << obj.name;
	return out;
}

Truck::Truck() : Vehicle(){
	/* Body Intentionally Empty*/
}

Truck::Truck(string manufacturer, int cylinders,const Person& owner_obj, double capacity_load, int capacity_towing):Vehicle(manufacturer, cylinders, owner_obj),
		capacityL(capacity_load),capacityT(capacity_towing)
{
	/* Body Intentionally Empty*/	
}

Truck::Truck(const Truck& obj) : Vehicle(obj),capacityL(obj.capacityL),capacityT(obj.capacityT){
	/* Body Intentionally Empty */	
}

Truck& Truck::operator =(const Truck& obj){
	Vehicle::operator =(obj);
	this->capacityL = obj.capacityL;
	this->capacityT = obj.capacityT;
	return *this;
}

double Truck::getCapacityLoad()const{
	return capacityL;
}

int Truck::getCapacityTowing()const{
	return capacityT;
}

void Truck::setCapacityLoad(const double capacity_load){
	capacityL = capacity_load;
}

void Truck::setCapacityTowing(const int capacity_towing){
	capacityT = capacity_towing;
}

void Truck::show_details(){
	Vehicle::show_details();
	cout << "Capacity of load in tons: " << capacityL << endl;
	cout << "Towing Capacity of towing in pounds: " << capacityT << endl;
}

Vehicle::Vehicle(){
	manufacturer_name = " ";
	number_cylinders = 0;
	owner = Person();
}

Vehicle::Vehicle(const string& manufacturer, int cylinders, const Person& owner_obj){
	manufacturer_name = manufacturer;
	number_cylinders = cylinders;
	owner = owner_obj;
}

Vehicle::Vehicle(const Vehicle& obj){
	manufacturer_name = obj.manufacturer_name; 
  	number_cylinders = obj.number_cylinders;
  	owner = obj.owner;
}

Vehicle& Vehicle::operator=(const Vehicle& obj){
	manufacturer_name = obj.manufacturer_name;
	number_cylinders = obj.number_cylinders;
	owner = obj.owner;
	return *this;
}

string Vehicle::getManufacturer()const{
	return manufacturer_name;
}

int Vehicle::getCylinders()const{
	return number_cylinders;
}

Person Vehicle::getOwner()const{
	return owner;
}

void Vehicle::setManufacturer(const string& manufacturer){
	manufacturer_name = manufacturer;
}

void Vehicle::setCylinders(const int cylinders){
	number_cylinders = cylinders;
}

void Vehicle::setOwner(const Person& owner_obj){
	owner = owner_obj;
}

void Vehicle::show_details(){
	cout << "Owner: " << owner << endl;
	cout << "Name of Manufacturer: " << manufacturer_name << endl;
	cout << "Cylinders' number in the engine: " << number_cylinders << endl;	
}

/* TEST */
int main()
{
	Person per("Can DUYAR");
	Truck tr1("DUYAR Logistics LLC", 6, per, 30, 6000);

	Truck tr2(tr1);

	Truck tr3 = tr2;

	cout << "TRUCK-1" << endl;
	tr1.show_details();

	cout << "\nTRUCK-2" << endl;
	tr2.show_details();

	cout << "\nTRUCK-3" << endl;
	tr3.show_details();
	
	return 0;
}

