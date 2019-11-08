#include <iostream>

#include "List.hpp"

using namespace std;

int main()
{
    enum ProgramStatus
    {
        ACTIVE = 0,
        QUIT = 1,
    };
    ProgramStatus Status = ACTIVE;
    /*
        array 6 int
        [12, 43, 547, 764, 124, 324]

        list = []
        // add 13
        list = [13]
        // add 42
        list = [13, 42]
    */

    // static world
    // int list[99999999] = {};
    // int size = 0;

    // // add
    // int in;
    // cin >> in;
    // list[size] = in;
    // size++;

    // Dynamic world
    List list;
    list.print();
    cout << endl;

    // add
    for (int i = 0; Status == ACTIVE; i++)
    {
        cout << "Digit -1 to quit sequence" << endl;
        cout << "Step " << i << endl;
        int in;
        cin >> in;
        if (in == -1)
        {
            Status = QUIT;
        }
        else
        {
            list.add(in);
            list.print();
        }
    }

    cout << "END" << endl;
    list.print();
    cout << endl;

}