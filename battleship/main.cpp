
#include <iostream>
#include <string>

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

    char board[10][10] = {};

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
    //   Hitted = x
    //   unknown = ?


    char letters[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
    cout << "  ";
    for (int x = 0; x < 10; x++)
    {
        cout << " " << letters[x];
    }
    cout << endl;

    // axe Y (vertical)
    for (int r = 0; r < 10; ++r)
    {
        cout << " " << r + 1 << " ";
        // axe X (horizontal)
        for (int c = 0; c < 10; ++c)
        {
            board[r][c] = '~';
            cout << board[r][c] << " ";
        }
        cout << endl;
    }

}