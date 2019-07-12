#include <iostream>

using namespace std;

void init() {
    int* valInit = new int();
}

int main() {

    cout << "Start..." << endl << endl;

    int valStack = 42;          // Stack | 0x0001 | 42 |

    int* valHeap = new int();   
    *valHeap = 42;
    // Heap  | 0xH001 | 42 (int) |
    // Stack | 0x0002 | 0xH001 (int *) |



    const int sizeArray = 4;
    char* pArray = new char[sizeArray];

    // cout << "Start pointer array: " << static_cast<void*>(pArray) << endl;

    pArray[0] = 'A';    // char -> byte size? 
    pArray[1] = 'B';
    pArray[2] = 'C';
    pArray[3] = 'D';

    for (int i = 0; i < sizeArray; ++i) {
        // cout << pArray[i] << endl;
        //cout << pArray + i << endl; // pArray | 0x000FF | 0x00011 (char*) |
        // cout << *(pArray + i) << endl;
        // *pArray -> A         | 0x00011
        // *(pArray + 1) -> B   | 0x00011 + 1
        // *(pArray + 2) -> C   | 0x00011 + 2
    }

    delete[] pArray;
    // pArray | 0x00044 | NULL |
    pArray = nullptr;




    /*
        char = 1 byte
        int = 4 byte => 4 * 8 = 32 bit
        long int = 8 byte
        short int = 2 byte
    */

    const int sizeIntArr = 5;
    int intArr[sizeIntArr];

    intArr[0] = 10;
    intArr[1] = 11;
    intArr[2] = 12;
    intArr[3] = 13;
    intArr[4] = 14;

    /* Remeber: 1 byte == 8 bit => 1 bit 0/1
        | ADDRESS  |  VALUE
        | 0x61fe10 | 00000000 > start 10
        | 0x61fe11 | 00000000
        | 0x61fe12 | 00000000
        | 0x61fe13 | 00001010 > finish 10
        | 0x61fe14 | 00000000 > start 11
        ...
        | 0x61fe17 | 00001011 > finish 11
        | 0x61fe18 | 00000000 > start 12
        ...
        | 0x61fe1b | 00001100 > finish 12
        | 0x61fe1c | 00000000 > start 13
        ...
        | 0x61fe20 | 00001101 > finish 13
        | 0x61fe21 | ... > start 4
        | ...
        | 0x61fe24 | ... 
    */

    // intArr == &intArr[0]
    // intArr[0] 
    cout << intArr << endl;
    cout << *(intArr + 4) << endl;
    cout << intArr[4] << endl;

    for (int i = 0; i < sizeIntArr; ++i) {
        cout << static_cast<void*>(&intArr[i]) << endl;
        cout << intArr[i] << endl;
    }


}