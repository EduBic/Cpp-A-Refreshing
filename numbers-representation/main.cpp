#include <string>
#include <iostream>
//#include <bitset>
#include "Fraction.hpp"
#include <fstream>

using namespace std;

void testInt() {
    // const int cpuBits = 42;
    //bitset<8> aBitSet(-2);
    //bitset<8> aNegBitSet("11111111");

    // Naturali: 0 1 2 3 4 5 ... (interi positivi)

    // 2 bits => max int repr in my PC? 
    //           2*2 = 4 => - 1 = 3
    // 3 bits => max int?
    //           2*2*2 = 8 
    // 4 bits => max int representable in my PC?
    //           2*2*2*2 = 16 => - 1 = 15
    // 8 bits => max int?
    //           256 - 1 = 255
    // 16 bits => max int?
    //           2^16 - 1 = 65.535
    // 32 bits => max int?
    //           2^32 - 1 = 4.294.967.296
    // 64 bits => max int?
    //           2^64 - 1 = 18.446.744.073.709.551.616‬

    
    // Base decimale 10 numeri 
    // Base binaria: 2 numeri
    // Binary  | Decimale
    // 0        == 0
    // 1        == 1
    // 10       == 2
    // 11       == 3
    // 100      == 4
    // 101      == 5
    // 110      == 6
    // 111      == 7
    // 1000     == 8
    // 1001     == 9
    // 1010     == 10
    // ...
    // ???      == 255
    //

    // Numeri Interi?

    // bit di segno
    // 10000000        MIN_INT
    // ...
    // 11111110        -2
    // 11111111        -1
    // 00000000        0
    // 00000001        1
    // 00000010        2
    // ...
    // 01111111        MAX_INT

    // 8 bits => max pos int
    //           2^(8-1) - 1 = 127
    //        => min neg int
    //           256 - 127 - 1 = 128

    // cout << aBitSet.to_string() << endl;
    // cout << aBitSet.to_ullong() << endl;
    // cout << aNegBitSet.to_ullong() << endl;
}

Fraction sumFraction(Fraction value1, Fraction value2)
{
    return Fraction(value1.numerator + value2.numerator, value1.denominator);
}

int main () {

    fstream myStream;
    myStream.open("data.txt", ios::in);

    // TODO 0: how to understand if end of a file is reached
    while (!myStream.end) {

        // TODO 1: read a Fraction from a file
        // decide a formatting in the txt for a fraction
        int num;
        myStream >> num;
        int den;
        myStream >> den;
        Fraction aFirstFraction(num, den);

        int num;
        myStream >> num;
        int den;
        myStream >> den;
        Fraction aSecondFraction(num, den);

        // TODO 2: read which operation from a file
        string operation;
        myStream >> operation;

        if (operation == "multiply") {
            // Fraction testRes = frac.multiply(otherFrac);
        }
        else {

        }

        int num;
        myStream >> num;
        int den;
        myStream >> den;
        Fraction expectedResult(num, den);

        // TODO 3 Compare
        // testRes.compare(expectedResult); <= return bool
    
        // TODO 4: cout test fail or is all ok

    } 
    
    //cout << "Numerator " << res.numerator << endl;
    //cout << "Denominator " << res.denominator << endl; 
}
// -2147483648
// 2147483647