#include <iostream>

#include "List.hpp"

using namespace std;

int main()
{

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
    for (int i = 0; i < 3; i++)
    {
        cout << "Step " << i << endl;
        int in;
        cin >> in;
        list.add(in);
        list.print();
    }

    cout << "END" << endl;
    list.print();
    cout << endl;

}