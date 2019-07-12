#include <iostream>

#include <string>

using namespace std;

void seeBoard(int aFunction[]) {
  for (int increm = 0; increm < 9; increm++) {
    char cPlayer1 = 'x';
    char cPlayer2 = 'o';
    cout << " ";
    // doppie funzioni come concatenare per semplificare la lettura?(probabile poca voglia di farlo al momento causa l'errore mentale)
    if (aFunction[increm] == -1) {
      cout << cPlayer1;
    } else if (aFunction[increm] == -2) {
      cout << cPlayer2;
    } else {
      cout << aFunction[increm];
    }
    cout << " |";
    increm++;
    cout << " ";
    if (aFunction[increm] == -1) {
      cout << cPlayer1;
    } else if (aFunction[increm] == -2) {
      cout << cPlayer2;
    } else {
      cout << aFunction[increm];
    }
    cout << " |";
    increm++;
    cout << " ";
    if (aFunction[increm] == -1) {
      cout << cPlayer1;
    } else if (aFunction[increm] == -2) {
      cout << cPlayer2;
    } else {
      cout << aFunction[increm];
    }
    cout << " " << endl;
  }
}


int main() {
  // To do:
  // - Determinate who start (default player 1 for easy win programming XD) and turns
  // - Set "how to play"
  // - Tell "who win"

  int iPlayer1 = -1;
  int iPlayer2 = -2;


  // Preparing Array for Empty Board
  int aBoard[9];
  // Debug
  // acBoard = ' '; per inizializzare tutto l'array a quel carattere?
  for (int iArray = 0; iArray < 9; iArray++) {
    aBoard[iArray] = iArray;
  }

  // Print board
  //  1 | 2 | 3
  // -----------
  //  4 | 5 | 6
  // -----------
  //  7 | 8 | 9
  seeBoard(aBoard);


  // Aggiungere array per board, e modo per escludere le caselle occuppate nelle succ
  // giocate, e modo per far visualizzare simbolo del giocatore in caselle occupate.
  for (int turn = 0; turn < 9; ++turn) {

    // Player 1
    cout << "Player 1 turn" << endl;
    int selection;
    cin >> selection;
    while (aBoard[selection] == iPlayer1 || aBoard[selection] == iPlayer2 || selection >= 9 || selection < 0) {
      cout << "Occupied select another" << endl;
      cin >> selection;
    }

    aBoard[selection] = iPlayer1;

    seeBoard(aBoard);

    // Player 2
    cout << "Player 2 turn" << endl;
    cin >> selection;
    while (aBoard[selection] == iPlayer1 || aBoard[selection] == iPlayer2 || selection >= 9 || selection < 0) {
      cout << "Occupied select another" << endl;
      cin >> selection;
    }

    aBoard[selection] = iPlayer2;

    // Print board
    seeBoard(aBoard);

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
// da fare stasera:
// -aggiungere variabile fissa (penso sia static ma non sono sicuro) per i player in modo da avere il simbolo associato in ogni parte del programma
// -semplificare alcune parti uguali funzioni ecc
// -implementare eventuale player vs cpu (magari come modalità aggiuntiva)
// -fix bug of board with hight number