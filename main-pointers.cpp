#include <iostream>

using namespace std;

// | 0x003 | 8 |
void fn(int nArg1) { // pass by value => copy
    cout << "fn" << endl;
    cout << &nArg1 << endl;  // 8
    nArg1 = 42;
    cout << nArg1 << endl;  // 42
    cout << "fn exit" << endl;
}

// val   | 0x000001 | 8 (int) |
// pArg1 | 0x000010 | 0x000001 (int*) |
// read - write "val"
void fnPtr(int* pArg1) {    // pass by reference => copy ram address
    cout << "fnPtr" << endl;
    
    cout << pArg1 << endl;  // | 0x000001 | => &val
    // Read
    cout << *pArg1 << endl; // 8 => val
    // Write
    *pArg1 = 36;

    cout << "fnPtr exit" << endl;
}

// val    | 0x000001 | 8 (int) |
// refArg | 0x0000FF | 0x000001 (int *) |
// read - write "val"
void fnRef(int & refArg) { // pass by reference => copy ram address
    cout << "fnRef" << endl;
    
    // Read
    cout << refArg << endl;
    
    // Write
    refArg = 48;

    cout << "fnRef exit" << endl;
}



int main() {

    cout << "Start..." << endl << endl;

    // Start with a pointer

    // char cSomeChar = 'A';
    // // | 0x001 | 'A' |

    // char* pChar = &cSomeChar;
    // // | 0x002 | 0x001 |

    // cout << cSomeChar << endl;  // 'A'
    // cout << &cSomeChar << endl; // 0x001
    // cout << pChar << endl;      // 0x001
    // cout << *pChar << endl;     // 'A'


    // Pass parameters to fn

    int val = 8;   // | 0x000001 | 8 (int) |

    // cout << val << endl;    // 8
    // fn(val); 
    // cout << val << endl;    // 8

    fnPtr(&val);
    cout << val << endl;

    fnRef(val);
    cout << val << endl;

} // dealloca val