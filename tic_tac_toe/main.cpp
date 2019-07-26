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

void getInputAi(int* ioBoard, const int iPlayer) {
  cout << "CPU " << -iPlayer << " turn" << endl;

  int selection;

  // init selection to some number
  
  ioBoard[selection] = iPlayer;
}


// Layer 0 : 1 states --
// Layer 1 : 4 states
// Layer 2 : 3 => 4 * 3 = 12 states
// Layer 3 : 2 => 12 * 2 = 24 states
// Layer 4 : 1 => 24 * 1 = 24 states
// 4 + 12 + 24 + 24 = 64 + 1 (layer 0)

// 1 * 4 = 4
// 4 * 3 = 12
// 12 * 2 = 24
// 24 * 1 = 24


// f(x) = x * f(x - 1) + 1
// f(0) = 1


// 1 * 9 = 9
// 9 * 8 = 72
// 72 * 7 = 504
// 504 * 6 = 3024
// 3024 * 5 = 15.120
// 15.120 * 4 = 60.480
// 60.480 * 3 = 181.440
// 180.440 * 2 = 362.880
// 362.880 * 1 = 362.880
// 362.880 + 362.880 + 181.440 + 60.440 + 15.120 + 3024 + 504 + 72 + 9 = 986409 + 1


struct Board { 
  char arr[9]; 
  int size = 9;
};

void printBis(const Board& iBoard, const int layer, const int i) {
    cout << endl << "Layer: " << layer << ", i: " << i << endl;
    cout << iBoard.arr[0] << "|" << iBoard.arr[1] << endl;
    cout << iBoard.arr[2] << "|" << iBoard.arr[3] << endl;
}

// Recursive solution
long int countingStatesRec(long int iNumStates) {
  if (iNumStates == 0) {
    // cout << "Res step: " << iNumStates << " equal: " << 1 << endl;
    return 1;
  }

  // cout << "Res step: " << iNumStates << endl;

  long int x = iNumStates - 1;
  int nextRes = countingStatesRec(x);  // <== 
  // Reprise from recursion
  int res = iNumStates * nextRes + 1;

  // cout << "Res step: " << iNumStates << " equal: " << res << endl;

  return res;

  // return x * countingStatesRec(x - 1) + 1; 
}

// Iterative solution
// f(0) = 1
// f(x) = x * f(x - 1) + 1
long int countingStates(long int iNumStates) {

  long int res = 1;

  for (long int x = 1; x <= iNumStates; x++)
  {
    res = x * res + 1;

    // cout << "Res step: " << iNumStates << " equal: " << res << endl;
  }

  return res;
}


// Without recursion
// Deep First in the tree
// - Take the first move from position i where i is empty position
// - Copy the board
void testingTreeRec(char iPlayer, Board ioBoard, int layer, long int& counter) {

  // if (layer > 4) {
  //   return;
  // }

  // cout << endl << "Layer: " << layer << endl;
  // printBis(ioBoard.arr);

  // for each place free in the ioBoard
  for (int i = 0; i < ioBoard.size; ++i) {
    if (ioBoard.arr[i] != 'o' && ioBoard.arr[i] != 'x') {
    
      ioBoard.arr[i] = iPlayer;         // <==
      printBis(ioBoard, layer, i);  
      counter++;

      // ====>
      testingTreeRec(iPlayer == 'x' ? 'o' : 'x', ioBoard, layer + 1, counter);
      // <====
      ioBoard.arr[i] = '-';
    }
  }
}


// iNumStates = 4
// ? | ?
// ? | ?
void testingTree(char iPlayer, Board ioBoard, const int iNumStates) {

  Board stack[9] = {};
  int top = -1;

  // init push
  top++;
  stack[top] = ioBoard;

  while (top != -1) { // while stack not empty

    Board innerBoard = stack[top];
    top--;

    for (int x = 0; x < iNumStates; ++x) {  // choice at layer == x
      if (innerBoard.arr[x] != 'o' && innerBoard.arr[x] != 'x') { // true if state is ?
        // change states
        innerBoard.arr[x] = iPlayer;
        
        printBis(innerBoard, -1, x);    // main operation

        // push
        top++;
        stack[top] = innerBoard;

        innerBoard.arr[x] = '-'; 
      }
    }
    
    iPlayer = iPlayer == 'x' ? 'o' : 'x';
  }
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
  // seeBoard(aBoard);
  
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
  // MAIN LOOP
  // for (int turn = 0; turn < 9; ++turn) {

  //   // 42 mod(2) = 0 => 42 / 2  get rest of division

  //   int thePlayer = turn % 2 == 0 ? iPlayer1 : iPlayer2;

  //   getInputPlayer(aBoard, thePlayer);

  //   seeBoard(aBoard);

  //   if (checkIfPlayerWin(aBoard, thePlayer) < 0) {
  //     cout << "Player " << -thePlayer << " WIN"<< endl;
  //     break;
  //   }
  // }

  // Board theBoard({'-', '-', '-', '-', '-', '-', '-', '-', '-',});
  Board theBoard({'-', '-', '-', '-'});
  testingTree('x', theBoard, 4);

  // int aNumStates = 4;

  // long int counterRec = countingStatesRec(aNumStates);
  // cout << endl;
  // long int counterIter = countingStates(aNumStates);

  // cout << endl << "Recursive res: " << counterRec << endl;
  // cout << endl << "Iterative res: " << counterIter << endl;

  cout << endl << "Finish" << endl;
}
// TODO:
// -implementare eventuale player vs cpu (magari come modalità aggiuntiva)