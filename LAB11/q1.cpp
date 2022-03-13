#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*CAN DUYAR -171044075*/

const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int UP = 4;

class Organism;
class Doodlebug;
class Ant;


class Game { //Game Class

public:
  Game(){ // default constructor
	  srand(time(NULL));
	  step_count = 0;
	  for (int x = 0; x < 20; x++)
	    for (int y = 0; y < 20; y++)
	      array[x][y] = nullptr;
  } 
  void start();
  void timeStep();
  void print()const;
  int random(int start, int end){return rand() % (end - start + 1) + start;}

private:
  Organism* array[20][20];
  int step_count;

  friend class Organism;
  friend class Ant;
  friend class Doodlebug;
  
};

class Organism { //Organism Class

public:
  Organism(): current(nullptr), x(0), y(0), breed_time(0), step_count(0){/*Body Intentionally Empty*/} //default constructor
  Organism(Game* current, int x, int y){ //constructor with parameter
	  this->current = current;
	  this->x = x;
	  this->y = y;
	  breed_time = 0;
	  step_count = current->step_count;
  }
  vector<int> validMoves(int x, int y); //returns valid moves for adjacent empty cells
  bool isValid(int x, int y)const; //if coordinates are valid then returns true otherwise returns false 
  void getCoordinate(int& x, int& y, int move)const; //x and y change depends on move which is given as parameter
  virtual void breed() = 0; //pure virtual
  virtual void move();
  virtual int getType() = 0; //pure virtual
  virtual bool starve() { return false; }

protected:
  Game* current;
  int x;
  int y;
  int breed_time;
  int step_count;
  
};

class Doodlebug: public Organism { //Doodlebug class which is derivated from Organism class

public:
  Doodlebug(): Organism(), starve_time(0){/*Body Intentionally Empty*/} //default constructor
  Doodlebug(Game* current, int x, int y): Organism(current, x, y){ //constructor with parameter
  	starve_time = 3;
  	breed_time = 8;
  }	
  vector<int> validMoves(int x, int y);//returns valid moves for adjacent empty cells
  void breed();
  void move();
  int getType(){ return 1; } //1 means type of doodlebug
  bool starve(){ return starve_time == 0;}

private:
  int starve_time;

};

class Ant: public Organism { //Ant class which is derivated from Organism class

public:
  Ant(): Organism(){/*Body Intentionally Empty*/} //default constructor
  Ant(Game* current, int x, int y);  //constructor with parameter
  void breed();
  int getType(){ return 2;} //2 means type of doodlebug 

};


void Game::start(){
  int x,y;
  int counter_db = 0; //it means counter_doodlebug
  int counter_ant = 0;

  while (counter_db < 5){ // generate 5 doodlebugs
    x = random(0,19);
    y = random(0,19);
    if (array[x][y] != nullptr)
    	continue;
    array[x][y] = new Doodlebug(this, x, y);
    counter_db++;
  }

  while (counter_ant < 100){ // generate 100 ants
    x = random(0,19); //it generates random x
    y = random(0,19); //it generates random y
    if (array[x][y] != nullptr)
    	continue;
    array[x][y] = new Ant(this, x, y);
    counter_ant++;
  }
}

void Game::timeStep(){
  step_count++;

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (array[x][y] == nullptr)
      	continue;
      if (array[x][y]->getType() == 1)
        array[x][y]->move();
    }
  }

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (array[x][y] == nullptr)
      	continue;
      if (array[x][y]->getType() == 2)
        array[x][y]->move();
    }
  }

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (array[x][y] == nullptr)
      	continue;
      array[x][y]->breed();
    }
  }

  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (array[x][y] == nullptr)
      	continue;
      if (array[x][y]->starve()){
        delete array[x][y];
        array[x][y] = nullptr;
      }
    }
  }
}

void Game::print()const {
  for (int x = 0; x < 20; x++){
    for (int y = 0; y < 20; y++){
      if (array[x][y] == nullptr)
        cout << " - ";
      else if (array[x][y]->getType() == 2) //condition for ants
        cout << " O ";
      else  //condition for doodlebugs
        cout << " X ";
    }
    cout << endl;
  }
}

vector<int> Organism::validMoves(int x, int y){
  vector<int> movesToEmptyCells;
  int x_temp, y_temp;
  for (int move = LEFT; move <= UP; move++){
    x_temp = x;
    y_temp = y;
    getCoordinate(x_temp, y_temp, move);
    if (!isValid(x_temp, y_temp))
    	continue;
    if (current->array[x_temp][y_temp] == nullptr) 
      movesToEmptyCells.push_back(move);
  }
  return movesToEmptyCells;
}

bool Organism::isValid(int x, int y) const {
  if (x < 0 || x >= 20 || y < 0 || y >= 20)
    return false;
  else
  	return true;
}

void Organism::getCoordinate(int& x, int& y, int move) const {
  if (move == LEFT) x--;
  if (move == RIGHT) x++;
  if (move == DOWN) y--;
  if (move == UP) y++;
}

void Organism::move(){
  if (step_count == current->step_count) return;
  step_count++;
  breed_time--;
  int randomMove = current->random(LEFT, UP);
  int x_new = x;
  int y_new = y;
  getCoordinate(x_new, y_new, randomMove);
  if (isValid(x_new, y_new)){
    if (current->array[x_new][y_new] != nullptr) return;
    current->array[x][y] = nullptr;
    current->array[x_new][y_new] = this;
    x = x_new;
    y = y_new;
  }
}

vector<int> Doodlebug::validMoves(int x, int y){
  vector<int> movesforAnts;
  int x_temp, y_temp;
  for (int move = LEFT; move <= UP; move++){
    x_temp = x;
    y_temp = y;
    getCoordinate(x_temp, y_temp, move);
    if (!isValid(x_temp, y_temp))
    	continue;
    if (current->array[x_temp][y_temp] == nullptr)
    	continue;
    if (current->array[x_temp][y_temp]->getType() == 2) 
      movesforAnts.push_back(move);
  }
  return movesforAnts;
}



void Doodlebug::breed(){
  if (breed_time > 0) return;
  vector<int> moves = validMoves(x, y);
  if (moves.size() == 0) return;
  int randomMove = moves[current->random(0, moves.size() - 1)];
  int x_new = x;
  int y_new = y;
  getCoordinate(x_new, y_new, randomMove);
  current->array[x_new][y_new] = new Doodlebug(current, x_new, y_new);
  breed_time = 8;
}

void Doodlebug::move(){
  if (step_count == current->step_count) return;
  vector<int> movesforAnts = validMoves(x, y);
  if (movesforAnts.size() == 0){
    Organism::move();
    starve_time--;
    return;
  }
  step_count++;
  starve_time = 3;
  int randomMove = movesforAnts[current->random(0, movesforAnts.size() - 1)];
  int antX = x;
  int antY = y;
  getCoordinate(antX, antY, randomMove);
  delete current->array[antX][antY];
  current->array[antX][antY] = this;
  current->array[x][y] = nullptr;
  x = antX;
  y = antY;
}

Ant::Ant(Game* current, int x, int y): Organism(current, x, y){
  breed_time = 3;
}

void Ant::breed(){
  if (breed_time > 0) return;
  vector<int> moves = validMoves(x, y);
  if (moves.size() == 0) return;
  int randomMove = moves[current->random(0, moves.size() - 1)];
  int x_new = x;
  int y_new = y;
  getCoordinate(x_new, y_new, randomMove);
  current->array[x_new][y_new] = new Ant(current, x_new, y_new);
  breed_time = 3;
}


/*TEST*/
int main(){

  char input;
  Game simulation; //Game object

  cout << "\n\033[7mDOODLEBUG VS. ANTS GAME\033[0m" << endl; //code for reverse video colour mode
  simulation.start();
  cout << "\nRANDOM 20x20 AREA" << endl << endl;
  simulation.print();
  cout << endl;

  cout << "Please enter for a timestep(press anything else to exit from the simulation): " << endl;
  cin.get(input);

  while(input == '\n'){
    simulation.timeStep();
    simulation.print();
    cout << endl;
    cout << "Please enter for a timestep(press anything else to exit from the simulation): " << endl;
    cin.get(input);
 	system("clear"); // to clear the console screen...
  }

  cout << "You exit from the simulation!!!" << endl;
    
  return 0;
}