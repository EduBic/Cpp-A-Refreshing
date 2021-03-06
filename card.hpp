
#include <iostream>
#include <string>

using namespace std;

/*
Equivalent to:

struct Card {
    int numero;
    char seme;

    int fun() {

    }
}
*/

class Card {

// Const Instruction
// Variable:
// x: | 0x01 | 10 (const)|
// const int x = 10;  Eq to: int const x = 10;

// px: | 0x02 | 0x01 |
// const int* px = &x;  <- the pointer object cannot change
// Eq to: int const * px = &x;
// *px = 42 <- ILLIGAL: ERROR COMPILE
// px = &y

// y = 20;
// int* const py = &y;  <- the pointer cannot change
// *py = 42
// py = &z <- ERROR

public:

    static Card getEmptyCard() {
        Card empty;
        empty.numero = -1;
        empty.seme = '-';
        
        return empty;
    }

    // implicitly implemented C++ if you want
    Card() {
        // cout << "DEBUG: Card: constructor" << endl;
    }                // default constructor
    
    Card(int number, char seed) {
        numero = number;
        seme = seed;
    }

    Card(const Card & val) {
        // cout << "DEBUG: Card: copy constructor" << endl;
        
        numero = val.numero;
        seme = val.seme;
    }     // copy constructor

    // Methods
    int getPoint() const {
        if (numero == 1) {
            return 11;
        } else if (numero == 3) {
            return 10;
        } else if (numero == 10) {
            return 4;
        } else if (numero == 9) {
            return 3;
        } else if (numero == 8) {
            return 2;
        } else {
            return 0;
        }
    }

    std::string print() const {
        return std::to_string(numero) + '-' + seme;
    }

    bool isValid() const {
        return numero != -1 || seme != '-';
    }

public:
    // Fields
    int numero;
    char seme;

};