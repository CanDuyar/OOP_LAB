#include <iostream>
#include <vector> // to use vector
using namespace std;

class Vector2D{ //Vector2D class
public:
	Vector2D();  //no parameter constructor
	Vector2D(int newx, int newy); //constructor
	void setX(const int newx); //
	void setY(const int newy); // SETTERS
	void vectorSet();          //
	int getX()const;  // GETTERS
	int getY()const;  //
	Vector2D operator *(const Vector2D &vec)const; // * overloading
private:
	int x,y;
	vector<vector<int>> v; //2D Vector
};

Vector2D::Vector2D():x(0),y(0){
	v.resize(2,vector<int>(2)); 
	vectorSet(); 
}

Vector2D::Vector2D(int newx, int newy){
	x=newx;
	y=newy;
	v.resize(2,vector<int>(2));
	vectorSet();
}

void Vector2D::setX(const int newx){ //Setter of x
	this->x = newx;
}

void Vector2D::setY(const int newy){ //Setter of y
	this->y = newy;
}
void Vector2D::vectorSet(){ //Setter of my vector
	v[0][0] = x;
	v[1][0] = y;
}

int Vector2D::getX()const{ //getter of x
	return x;
}
int Vector2D::getY()const{ // getter of y
	return y;
}

Vector2D Vector2D::operator *(const Vector2D &vec)const{
	Vector2D v;
	v.setX(getX() * vec.getX());
	v.setY(getY() * vec.getY());
	v.vectorSet();
	return v;
}
           /* TEST  */
int main(int argc, char const *argv[])
{
	Vector2D exp1(13,10),exp2(20,12);

	cout <<'(' << exp1.getX() <<',' << exp1.getY() << ") * " 
	<< '(' << exp2.getX() <<',' << exp2.getY() << ") = " << (exp1*exp2).getX() + (exp1*exp2).getY() << endl;
	return 0;
}
