#include <iostream>

using namespace std;


class Point{

public:
	Point();
	Point(int x,int y);
	void move(int vertical,int horizontal);
	void rotate();
	int currentCoordinate_x()const;
	int currentCoordinate_y()const;
	
private:
	int x;
	int y;	
};

Point::Point(): x(0),y(0){ // No-Parameter constructor
	/*Initially empty*/
}

Point::Point(int x,int y){ //constructor with parameters
	this->x = x;
	this->y = y;
}


void Point::move(int vertical,int horizontal){
	this->x = this->x + vertical;
	this->y = this->y + horizontal;	
}

void Point::rotate(){

	int temp;
	temp = (this->x);
	(this->x) = (this->y);
	(this->y) = temp;

	(this->y) = (this->y)*(-1);
}


int Point::currentCoordinate_x()const{
	return this->x;
}
	

int Point::currentCoordinate_y()const{
	return this->y;
}


		/* TEST */

int main(int argc, char const *argv[])
{

	Point point1(2,7),point2;  // point2 starts from origin.   

	cout << "TEST FOR POINT1(2,7)" << endl;
	cout << "Move 2 - Vertical" <<endl;
	cout << "Move 4 - Horizontal" << endl;
	point1.move(2,4);
	cout << point1.currentCoordinate_x() << " " << point1.currentCoordinate_y() << endl;
	cout << "After rotating" << endl;
	point1.rotate();
	cout << point1.currentCoordinate_x() << " " << point1.currentCoordinate_y() << endl;
	cout << endl;
	
	cout << "TEST FOR POINT2(0,0)" << endl;
	cout << "Move 7 - Vertical" <<endl;
	cout << "Move 13 - Horizontal" << endl;
	point2.move(7,13);
	cout << point2.currentCoordinate_x() << " " << point2.currentCoordinate_y() << endl;
	cout << "After rotating" << endl;
	point2.rotate();
	cout << point2.currentCoordinate_x() << " " << point2.currentCoordinate_y() << endl;
	cout << endl;


	
	return 0;
}