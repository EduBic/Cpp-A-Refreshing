
#include <iostream>

#include "Board.hpp"
#include "GameState.hpp"
#include "Coordinate.hpp"

using namespace std;

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

Coordinate playerTurn(GameState& gameStatus)
{                   
    string userInput;
    
    cin >> userInput;
    if (userInput == ":m")
    {
        gameStatus = MENU;
    }
    else if (userInput.size() > 0 && userInput[0] == ':') 
    {
        cout << "HELP: Press ':m' for return to menu" << endl;
    }
    else
    {
        const string LETTERS_IN[10] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};
        const string NUMBERS_IN[10] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10"};

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
            return Coordinate(x, y);
        }
        else
        {
            cout << "Input wrong!" << endl;
        }
    }

    return Coordinate(-1, -1);
}


void initBoardsWithShips(GameState& gameStatus, Board& boardPlayer1, Board& boardPlayer2)
{
    const int shipNumber = 5;
    const string shipName[shipNumber] = {"Carrier", "Battleship", "Cruiser", "Submarine", "Destroyer"};
    const int shipSize[shipNumber] = {5, 4, 3, 3, 2};

    for (int t = 1; t <= 2 && gameStatus == STARTUP; t++)
    {
        if (t == 1)
            boardPlayer1.print();
        else 
            boardPlayer2.print();

        for (int p = 0; p < shipNumber && gameStatus == STARTUP;)
        {
            cout << "Player " << t << " ";
            
            // cout migliorabile
            cout << "enter coordinate for " 
                 << shipName[p] << " (size " << shipSize[p] << ") "
                 << "placement" << endl;
            
            cout << "Enter begin coordinate: ";
            Coordinate begin = playerTurn(gameStatus);
            // optimize: exit if gamestatus changes
            if (gameStatus != STARTUP) return;
            
            cout << "Enter end coordinate: ";
            Coordinate end = playerTurn(gameStatus);
            // optimize: exit if gamestatus changes
            if (gameStatus != STARTUP) return;
            
            if (t == 1)
            {
                if (boardPlayer1.insertShip(begin, end, shipSize[p]))
                {
                    p++;
                }
                boardPlayer1.print();
            }
            else
            {
                if (boardPlayer2.insertShip(begin, end, shipSize[p])) 
                {
                    p++;
                }
                boardPlayer2.print();
            }
            cout << endl;
        }
    }
}


void shootingPhase(GameState& gameStatus, Board& boardEnemy, const Board& boardPlayer, int& player)
{
    Coordinate coord = playerTurn(gameStatus);
    boardPlayer.print();

    bool hit = boardEnemy.shoot(coord.x, coord.y);
    if (player == 1 && !hit) 
    {
        player++;
    } 
    else if (player == 2 && !hit)
    {
        player--;
    }
    
    boardEnemy.checkIfHit();
}


void test_initBoardWithShips(Board& ioBoard)
{
    ioBoard.insertShip(Coordinate(2, 2), Coordinate(5, 2), 3);
    //ioBoard.insertShip(9, 8, 9, 5);
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



    GameState gameStatus = MENU;
    string userInput;

    // Game loop
    while (gameStatus != EXIT)
    {
        // menu flow
        cout << "______       _   _   _           _     _       " << endl <<      
                "| ___ \\     | | | | | |         | |   (_)      " << endl <<
                "| |_/ / __ _| |_| |_| | ___  ___| |__  _ _ __  " << endl <<
                "| ___ \\/ _` | __| __| |/ _ \\/ __| '_ \\| | '_ \\ " << endl <<
                "| |_/ / (_| | |_| |_| |  __/\\__ \\ | | | | |_) |" << endl <<
                "\\____/ \\__,_|\\__|\\__|_|\\___||___/_| |_|_| .__/ " << endl <<
                "                                        | |    " << endl <<
                "                                        |_|    " << endl;

        cout << "\t" << "Insert :s for start..."   << endl 
             << "\t" << "or :x for exit the game." << endl;
        cin >> userInput;
        if (userInput == ":s")
        {
            // startup flow
            gameStatus = STARTUP;
            Board boardPlayer1;
            Board boardPlayer2;
            
            initBoardsWithShips(gameStatus, boardPlayer1, boardPlayer2);
            
            // game flow
            if (gameStatus == STARTUP)
            {
                gameStatus = GAME;
            }
            int player = 1;

            while (gameStatus == GAME)
            {
                if (player == 1)
                {
                    cout << "Player1, enter shoot coordinate: ";
                    shootingPhase(gameStatus, boardPlayer2, boardPlayer1, player);
                    if(boardPlayer2.checkIfWin())
                    {
                        cout << "\tPlayer1 WINS" << endl;
                        gameStatus = MENU;
                    }
                }
                else
                {
                    cout << "Player2, enter shoot coordinate: ";
                    shootingPhase(gameStatus, boardPlayer1, boardPlayer2, player);
                    if(boardPlayer1.checkIfWin())
                    {
                        cout << "\tPlayer2 WINS" << endl;
                        gameStatus = MENU;
                    }
                }
            }
        }
        else if (userInput == ":x")
        {
            gameStatus = EXIT;
        }
    }
    // TODO:
    // label string argomento
    // Save match, restart etc.
    // support pause state
}