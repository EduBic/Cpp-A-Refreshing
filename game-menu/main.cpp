
#include <iostream>
#include <string>

using namespace std;


void retarded(int iPlay) {
    cout << "Press 0 to return to main menu when you are bored enough" << endl;
            
    cin >> iPlay;
    while (iPlay != 0) {
        cout << "I said Press 0 RETARDED little boy" << endl;
        cin >> iPlay;
    }
}


int main() {

    // Spec:
    // Menu of program:
    // - Play
    // - Options
    // - Exit

    int iPlay = 0;
    bool running = true;
    
    while (running) {
        cout << endl;
        cout << "1 - Play" << endl;
        cout << "2 - Options" << endl;
        cout << "3 - Exit" << endl;
        cout << endl;
        
        cin >> iPlay;
        if (iPlay == 1) {
            cout << "Playing... (This game is so sad)" << endl;
            retarded(iPlay);
        }
        else if (iPlay == 2) {
            cout << "Select your volume and graphics setting in your immagination..."
                << "(Brilliant settings)" << endl;
            retarded(iPlay);
        }
        else if (iPlay == 3) {
            cout << "I see you understand this game, you won" << endl;
            running = false;
        }
    }
    

}