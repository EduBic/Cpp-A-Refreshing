#include <iostream>
#include <string>

using namespace std;

int main() {
  // To Do:
  // -Create 2 player
  // -Create 2 symbol(emblem) (x and o)
  // -Assign to player a symbol
  // -Create "Board"
  // -Determinate who start (default player 1 for easy win programming XD) and turns
  // - Set "how to play"
  // -Tell "who win"

char cPlayer1 = 'x';
char cPlayer2 = 'o';
// Print board
//  1 | 2 | 3 
// -----------
//  4 | 5 | 6 
// -----------
//  7 | 8 | 9
cout << "   |   |   " << endl;
cout << "   |   |   " << endl;
cout << "   |   |   " << endl;

// function for print board with numbers
// Aggiungere array per board, e modo per escludere le caselle occuppate nelle succ
// giocate, e modo per far visualizzare simbolo del giocatore in caselle occupate.
for (int turn = 0; turn < 9; ++turn) {

    int selection;
    cin >> selection;

    // TODO: cout board with cell "selection" cover with an X and O alternate
    // Example: cin >> 5
    // Board update (turn == 0):
    //   |   |   
    //   | x |   
    //   |   |   
    // Next: cin >> 9
    // Board update (turn == 1):
    //   |   |   
    //   | x |   
    //   |   | o

}


}