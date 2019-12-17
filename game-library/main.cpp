
/*
Funzione :
- dichiarazione: tipoRitorno nomeFunzione(tipoInput varInput)
- implementazione: { ...code here... }
- chiamata: nomeFunzione(varInput);
*/
#include <iostream>
#include <string>
#include "Account.hpp"

using namespace std;

/**
 * - Your game library
 *      - Inner Group
 * - Game pages
 * - Friends
 * - Shop
 * - Account
 */
int main()
{
    // TODO
    // create account
    // game library

    // TODO: print title
    cout << "Create your account, insert your nickname: " << endl;

    string newAccountNick;
    cin >> newAccountNick;

    Account currUser(newAccountNick);

    cout << "Welcome " << currUser.getNickName() << endl;

    // Main Loop
    for (string in = "i"; in != "q";)
    {
        cout << "Enter q to quit" << endl;
        cin >> in;
        
        if (in == "q")
        {
            cout << "See ya" << endl;
        }
        else if (in == "a")
        {
            cout << "Insert the game name to add into your library: " << endl;
            cin >> in;
            currUser.addGame(in);
            in = "i";
        }
    }
}