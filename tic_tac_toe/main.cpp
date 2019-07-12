#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

void printBoardCell(const int * iBoard, const int increm, const char * iLastChars) {
  char cPlayer1 = 'x';
  char cPlayer2 = 'o';

  cout << " ";
  if (iBoard[increm] == -1) {
    cout << cPlayer1;
  } else if (iBoard[increm] == -2) {
    cout << cPlayer2;
  } else {
    cout << iBoard[increm];
  }
  cout << iLastChars;
}

void seeBoard(const int iBoard[]) {
  for (int increm = 0; increm < 9; increm++) {
    
    printBoardCell(iBoard, increm, " |");
    increm++;
    printBoardCell(iBoard, increm, " |");
    increm++;
    printBoardCell(iBoard, increm, " \n");
  }
}

  
int checkIfPlayerWin(const int iBoard[], const int iPlayer) {
  if (iBoard[0] == iPlayer && iBoard[1] == iPlayer && iBoard[2] == iPlayer)
  {
    return iPlayer;
  }
  else if (iBoard[0] == iPlayer && iBoard[4] == iPlayer && iBoard[8] == iPlayer)
  {
    return iPlayer;
  }
  else if (iBoard[0] == iPlayer && iBoard[3] == iPlayer && iBoard[6] == iPlayer)
  {
    return iPlayer;
  }
  else if (iBoard[1] == iPlayer && iBoard[4] == iPlayer && iBoard[7] == iPlayer)
  {
    return iPlayer;
  }
  else if (iBoard[3] == iPlayer && iBoard[4] == iPlayer && iBoard[5] == iPlayer)
  {
    return iPlayer;
  }
  else if (iBoard[2] == iPlayer && iBoard[4] == iPlayer && iBoard[6] == iPlayer)
  {
    return iPlayer;
  }
  else if (iBoard[6] == iPlayer && iBoard[7] == iPlayer && iBoard[8] == iPlayer)
  {
    return iPlayer;
  } 
  else if (iBoard[2] == iPlayer && iBoard[5] == iPlayer && iBoard[8] == iPlayer)
  {
    return iPlayer;
  }
  else {
    return 0;
  }
}

void getInputPlayer(int * ioBoard, const int iPlayer) {
  cout << "Player " << -iPlayer << " turn" << endl;

  int selection;
  cin >> selection;
  while (ioBoard[selection] == iPlayer || ioBoard[selection] == iPlayer 
        || selection >= 9 || selection < 0) 
  {
    cout << "Occupied select another" << endl;
    cin >> selection;
  }
  
  ioBoard[selection] = iPlayer;
}



int main() {

  int iPlayer1 = -1;
  int iPlayer2 = -2;


  // Preparing Array for Empty Board
  int aBoard[9];
  for (int iArray = 0; iArray < 9; iArray++) {
    aBoard[iArray] = iArray;
  }

  // Print board
  //  0 | 1 | 2
  // -----------
  //  3 | 4 | 5
  // -----------
  //  6 | 7 | 8
  seeBoard(aBoard);
  
  // Cout board with cell "selection" cover with an X and O alternate
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
  for (int turn = 0; turn < 9; ++turn) {

    int thePlayer = turn % 2 == 0 ? iPlayer1 : iPlayer2;

    getInputPlayer(aBoard, thePlayer);

    seeBoard(aBoard);

    if (checkIfPlayerWin(aBoard, thePlayer) < 0) {
      cout << "Player " << -thePlayer << " WIN"<< endl;
      break;
    }

  }

  cout << endl << "Finish" << endl;
}
// TODO:
// -implementare eventuale player vs cpu (magari come modalità aggiuntiva)