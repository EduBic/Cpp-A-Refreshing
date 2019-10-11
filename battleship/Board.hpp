#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
        0  1  2  3  4  5  6  7  8  9
    0   A0 B0 C0 D0 E0 F0 G0 H0 I0 J0
    1   A1 B1 C1 D1 E1 F1 G6 H1 I1 J1
    2   A2 B2 C2 D2 E2 F2 G6 H2 I2 J2
    3   A3 B3 C3 D3 E3 F3 G6 H3 I3 J3
    4   A4 B4 C4 D4 E4 F4 G6 H4 I4 J4
    5   A5 B5 C5 D5 E5 F5 G6 H5 I5 J5
    6   A6 B6 C6 D6 E6 F6 G6 H6 I6 J6
    7   A7 B7 C7 D7 E7 A7 G6 H7 I7 J7
    8   A8 B8 C8 D8 E8 F8 G8 H8 I8 J8
    9   A9 B9 C9 D9 E9 F9 G9 H9 I9 J9
*/

//   ON BOARD INDEX
//   ship = s
//   water = ~

//   hitted water = o
//   ship hitted = x
//   unknown = ?
class Board
{
public:
    Board()
    {
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; ++y)
            {
                board[x][y] = '~';
            }
        }
    }

    void print() const
    {
        cout << "  ";
        for (int x = 0; x < 10; x++)
        {
            cout << " " << letters[x];
        }
        cout << endl;

        
        for (int y = 0; y < 10; y++)
        {
            cout << " " << numbers[y] << " ";
            for (int x = 0; x < 10; ++x)
            {
                cout << board[y][x] << " ";
            }
            cout << endl;
        }
    }
    
    // coordinates included
    bool insertShip(int x1, int y1, int x2, int y2)
    {
        if (y1 == y2) {
            int xMax = max(x1, x2);
            int xMin = min(x1, x2);

            if (isShipSizeAccepted(xMax, xMin))
            {
                for (int x = xMin; x <= xMax; x++)
                {
                    board[y1][x] = 'o';
                }
                return true;
            }
        }
        else if (x1 == x2) 
        {
            int yMax = max(y1, y2);
            int yMin = min(y1, y2);
            // check per controllare se la nave è piazzabile o meno
            if (isShipSizeAccepted(yMax, yMin))
            {
                for (int y = yMin; y <= yMax; y++)
                {
                    board[y][x1] = 'o';
                }
                return true;
            }    
        }

        cout << "DEBUG: Ship Not Valid, select other coordinate for ship placement" 
            << endl; 

        return false;
    }

    //  imput compresi perchè stiamo ragionando a celle
    bool isShipSizeAccepted(int max, int min)
    {
        return max - min > 0 && max - min < 5;
    }
    //  submarine = 3
    //  incrociatore = 3
    //  cacciatorpediniere = 2
    //  corazzate = 4
    //  portaerei = 5
    
    //  implementare eventuale piazzamento a scelta per tipo di nave

    void shoot(int x, int y)
    {
        if (board[y][x] == '~')
        {
            board[y][x] = 'w';
        }
        else if (board[y][x] == 'o')
        {
            board[y][x] = 'x';
        }
        else 
        {
            cout << "DEBUG: Already hitted coordinates" << endl;
        }
    }

    void checkIfHit()
    {
        Board boardTest(*this);
        // hideWaterAndShips
        for (int x = 0; x < 10; x++)
        {
            for (int y = 0; y < 10; ++y)
            {
                if (boardTest.board[x][y] == '~' || boardTest.board[x][y] == 'o')
                    boardTest.board[x][y] = '?';
            }
        }

        boardTest.print();
    }

private:

    const char letters[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    const int numbers[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    char board[10][10];
};