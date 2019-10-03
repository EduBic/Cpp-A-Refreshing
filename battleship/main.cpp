
#include <iostream>

#include "Board.hpp"

using namespace std;


void initBoardsWithShips(Board& boardPlayer1, Board& boardPlayer2)
{
    for(int t = 1; t <= 2; t++)
    {
        for(int p = 0; p < 5; p++)
        {
            if(t == 1)
            {
                cout << "Player 1 ";
            }
            else
            {
                cout << "Player 2 ";
            }
            // cout migliorabile
            cout << "enter coordinate for ship placement" << endl;
            cout << "Enter first x coordinate: ";
            int x = 0;
            // cin >> x;
            cout << "Enter first y coordinate: ";
            int y = 0;
            // cin >> y;
            cout << "Enter second x coordinate: ";
            int x2 = 0;
            // cin >> x2;
            cout << "Enter second y coordinate: ";
            int y2 = 0;
            // cin >> y2;
            
            if (t == 1)
            {
                boardPlayer1.insertShip(x, y, x2, y2);
                boardPlayer1.print();
                cout << endl;
            }
            else
            {
                boardPlayer2.insertShip(x, y, x2, y2);
                boardPlayer2.print();
                cout << endl;
            }
        }
    }
}

void test_initBoardWithShips(Board& ioBoard)
{
    ioBoard.insertShip(2, 2, 5, 2);
    ioBoard.insertShip(9, 8, 9, 5);
}

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
    //  0 = menu
    //  1 = game
    int gameStatus = 0;
    char userInput;
    while(true)
    {
        // menu flow
        cout << "Press s for start..." << endl;
        cin >> userInput;
        if(userInput == 's')
        {
            gameStatus++;
        }

        // game flow
        while(gameStatus == 1)
        {
            // boardPlayer1.print();
            // // initBoardsWithShips(boardPlayer1, boardPlayer2);
            // test_initBoardWithShips(boardPlayer1);
            // boardPlayer1.print();
            // test_initBoardWithShips(boardPlayer2);
            // boardPlayer2.print();

            // 
            while(gameStatus == 1)
            {
                cout << "Player1 enter shoot coordinate: ";
                // modify to take imput coordinate for shoot
                char x, y;
                cin >> x;
                cin >> y;
                // loop caused by int variable confronted with char need a fix
                if(x == 'h'|| y == 'h')
                {
                    gameStatus--;
                }
                
                // boardPlayer1.shoot(x, y);
                // boardPlayer1.checkIfHit();
                // boardPlayer1.print();

                // boardPlayer2.shoot(2, 4);
                // boardPlayer2.checkIfHit();

                // boardPlayer2.print();

                // boardPlayer2.shoot(7, 8);
                // boardPlayer2.checkIfHit();
                // boardPlayer2.print();
            }
        }
    }
    // TODO:
    // (done) Loop di inserimento delle navi per i due giocatori (riga 29)
    // (done) for (0 5) cin int; insertShip (riga 31)(fix need for ship over another ship placement)
    // Potenziare l'espressività del print() board
    // label string argomento
    // (done) Alternanza player per sparare (riga 72)

    // BUG: overlap of ship in the insertion
}