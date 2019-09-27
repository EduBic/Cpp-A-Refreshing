
#include <iostream>

#include "Board.hpp"

using namespace std;


int main() 
{
    // Ship: size
    // Player
    // Board for each player
    // primitive AI

    // Turn base

    // Board
    // cell: 
    //  - coordinate
    //  - 
    // 100 cells

    // Displacement ships

    Board boardPlayer1;
    Board boardPlayer2;
    //boardPlayer1.print();
    boardPlayer1.insertShip(0, 1, 0, 3);
    boardPlayer1.print();

    cout << endl;

    boardPlayer2.insertShip(1, 4, 5, 4);
    boardPlayer2.print();

    // 
    boardPlayer2.shoot(2, 4);
    boardPlayer2.shoot(2, 5);
    boardPlayer2.checkIfHit();

    boardPlayer2.print();

    boardPlayer2.shoot(7, 8);
    boardPlayer2.checkIfHit();
    boardPlayer2.print();

    // TODO:
    // Loop di inserimento delle navi per i due giocatori
    // for (0 5) cin int; insertShip
    // Potenziare l'espressività del print() board
    // label string argomento
    // Alternanza player per sparare

    //
}