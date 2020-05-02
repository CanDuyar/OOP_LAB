#include <iostream>
#include <string>

using namespace std;

class Pizza{

public:
	Pizza();
	Pizza(string type,string size,int topping); //constructor with parameters 
	void outputDescription();
	double computePrice();
	void setType(const string&);     // SETTERS
	void setSize(const string&);
	void setNumberOfTopping(int numberOftoppings);
	const string& getType()const;   //GETTERS 
	const string& getSize()const;
	int getNumberOfTopping()const;



private:
	string type ;
	string size;
	int numberOftoppings;

};


Pizza::Pizza(){
	numberOftoppings = 0;
	size = "Small";
	type = "deep dish";
}

Pizza::Pizza(string t,string s,int topping){
	this->type = t;
	this->size = s;
	this->numberOftoppings = topping;
}


void Pizza::setType(const string &t){
	this->type = t;
}

void Pizza::setSize(const string &s){
	this->size = s;
}

void Pizza::setNumberOfTopping(int numberOftoppings){
	this->numberOftoppings = numberOftoppings;
}

const string &Pizza::getSize()const{
	return this->size;
}

const string &Pizza::getType()const{
	return this->type;
}

int Pizza::getNumberOfTopping()const{
	return this->numberOftoppings;
}



void Pizza::outputDescription(){

	int price;

	if(size == "Small")
		price = 10;
	else if(size == "Medium")
		price = 14;
	else if(size == "Large")
		price = 17;

	cout << size << " " << type << " Pizza = $" << price << "  +"  << " with "
	 << numberOftoppings << " topping(s)" << "(2$ x  " << numberOftoppings << ')' << endl;


}


double Pizza::computePrice(){
	double total_cost = 0;
	int pizza_cost;

	if(size == "Small")
		pizza_cost = 10;
	else if(size == "Medium")
		pizza_cost = 14;
	else if(size == "Large")
		pizza_cost = 17;

	total_cost = pizza_cost + (2*numberOftoppings);

	return total_cost;

}

	     /*TEST*/

int main(int argc, char const *argv[])
{

	string type_choice;
	string size_choice;
	int numb;

	const string type1 = "deep dish";
	const string type2 = "hand tossed";
	const string type3 = "pan";
	
	const string size1 = "Small";
	const string size2 = "Medium";
	const string size3 = "Large";

	
	cout << "TYPES" << endl;
	cout << "type1 -> deep dish" << endl;
	cout << "type2 -> hand tossed" << endl;
	cout << "type3 -> pan" << endl;
	cout << endl;
	cout << "SIZES" << endl;
	cout << "size1 -> Small" << endl;
	cout << "size2 -> Medium" << endl;
	cout << "size3 -> Large" << endl;

	cout << "Enter your type choice(like type1 etc.)" << endl;
	cin >> type_choice;

	if(type_choice == "type1")
		type_choice = type1;
	else if(type_choice == "type2")
		type_choice = type2;
	else if(type_choice == "type3")
		type_choice = type3;

	cout << endl;
	cout << "Enter your size choice(like size1 etc.)" << endl;
	cin >> size_choice;
	if(size_choice == "size1")
		size_choice = size1;
	else if(size_choice == "size2")
		size_choice = size2;
	else if(size_choice == "size3")
		size_choice = size3;

	cout << "Enter number of your toppics" << endl;
	cin >> numb;
				

	Pizza dominos(type_choice,size_choice,numb);

	dominos.outputDescription();
	cout << " Your total cost is " << dominos.computePrice() << endl;
	
	return 0;
}