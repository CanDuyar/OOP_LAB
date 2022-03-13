#include <iostream>
#include <cstdlib>
#include <ctime>

/*CAN DUYAR - 171044075*/

using namespace std;

class Player { //Player class
   public:
      virtual int getGuess() = 0; //pure virtual
      int guess; 
};

class ComputerPlayer : public Player { //ComputerPlayer class which is derived from Player class
   public:
      ComputerPlayer() : Player(){ /*Body Intentionally empty*/ }
      int getGuess() {
         return rand() % 100 + 1; 
      }
};

class HumanPlayer : public Player { //HumanPlayer class which is derived from Player class
   public:
      HumanPlayer() : Player() {/*Body Intentionally empty*/}
      int getGuess() {
         cout << "Enter your guess: ";
         cin >> guess;
         return guess;
      }
};


bool checkForWin(int guess, int answer){ //If player guesses the number as true then i returns true otherwise returns false
  if (answer == guess){
     cout << "Congratulations! You win!" << endl;
     return true;
  }
  else if (answer < guess)
     cout << "Your guess is too high." << endl;
  else
     cout << "Your guess is too low." << endl;
  return false;
}

void play(Player &player1, Player &player2){
  int answer = 0, guess = 0;
  answer = rand() % 100;
  bool win = false;

  while (!win)
  {
   cout << "Player 1's turn to guess." << endl;
   guess = player1.getGuess();
   win = checkForWin(guess, answer);
   if (win)
    break;

   cout << "Player 2's turn to guess." << endl;
   guess = player2.getGuess();
   win = checkForWin(guess, answer);
  }
}


/* TEST */
int main()
{
    char input;
    int option;
    int loop_control = 1;

    srand(time(NULL));
    HumanPlayer humanPlayer1, humanPlayer2;
    ComputerPlayer computerPlayer1, computerPlayer2;

    while(loop_control) {
    
      cout << "******GUESSING-GAME MENU*******" << endl; //GAME MENU
      cout << "\n1-Human vs. Human" << endl;
      cout << "2-Human vs. Computer" << endl;
      cout << "3-Computer vs. Computer" << endl;
      cout << "4-EXIT" << endl;
      cout <<"\n\nEnter your game-mod:" << endl;
      cin >> option;
        switch(option){
          case 1:
            cout << endl;
            cout << "\nHuman vs. Human Mod" << endl;
            play(humanPlayer1, humanPlayer2);
          break; 
       
          case 2:
            cout << endl;
            cout << "\nHuman vs. Computer Mod" << endl;
            play(humanPlayer1, computerPlayer1);
          break;

          case 3:
            cout << endl;
            cout << "\nComputer vs. Computer Mod" << endl;
            play(computerPlayer1, computerPlayer2);
          break;

          case 4:
            loop_control = 0;
            cout << endl;
            cout << "\nYou exit from the game!!!" << endl;
          break;

          default:
            cout << "\nYou entered an invalid operation,please try again!!!" << endl;
          break;
        }   
  }
        
    return 0;
}