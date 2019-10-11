
#include <iostream>

#include "Board.hpp"
#include "GameState.hpp"

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


// Return index of the input in the possibleInputs array 
int convertInput(const string& input, const string (&possibleInputs)[10])
{   
    cout << "DEBUG: input = " << input << endl;

    for (int i = 0; i < 10; ++i)
    {
        if (input == possibleInputs[i])
        {
            return i;
        }
    }

    return -1;
}



void playerTurn(string userInput, GameState& gameStatus, Board& boardEnemy, const Board& boardPlayer)
{
    const string LETTERS_IN[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
    const string NUMBERS_IN[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};
                    
    cin >> userInput;
    if (userInput == ":m")
    {
        gameStatus = MENU;
    }
    else
    {
        string charX = string(1, userInput[0]);  // letter
        string charY = string(1, userInput[1]);  // number

        if (userInput.size() == 3)
        {
            charY.append(1, userInput[2]);
        }

        int x = convertInput(charX, LETTERS_IN);
        int y = convertInput(charY, NUMBERS_IN);

        if (x != -1 && y != -1)
        {
            boardPlayer.print();

            boardEnemy.shoot(x, y);
            boardEnemy.checkIfHit();
        }
        else
        {
            cout << "Input wrong!" << endl;
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

    GameState gameStatus = MENU;
    string userInput;

    // Game loop
    while (gameStatus != EXIT)
    {
        // menu flow
        cout << "Insert :s for start..." << endl
             << "or :x for exit the game." << endl;
        cin >> userInput;
        if (userInput == ":s")
        {
            gameStatus = GAME;
            // game flow

            // boardPlayer1.print();
            // // initBoardsWithShips(boardPlayer1, boardPlayer2);
            test_initBoardWithShips(boardPlayer1);
            // boardPlayer1.print();
            test_initBoardWithShips(boardPlayer2);
            // boardPlayer2.print();

            // 
            int player = 1;

            while (gameStatus == GAME)
            {
                if(player == 1)
                {
                    cout << "Player1 enter shoot coordinate: ";
                    playerTurn(userInput, gameStatus, boardPlayer2, boardPlayer1);
                    player++;
                }
                else
                {
                    cout << "Player2 enter shoot coordinate: ";
                    playerTurn(userInput,gameStatus, boardPlayer1, boardPlayer2);
                    player--;
                }
            }
        }
        else if (userInput == ":x")
        {
            gameStatus = EXIT;
        }
    }
    // TODO:
    // Potenziare l'espressività del print() board (fixare il 10)
    // label string argomento
    // If shoot is an hit, the player plays the next turn 
    // Print BATTLESHIP in ascii art in MENU flow (might be cool)

    // BUG: overlap of ship in the insertion
    // BUG: go to menu don't refresh players board
}