#include <iostream>
#include <string>

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
    List<string> list;
    list.printAll();
    cout << endl;

    // add
    for (int i = 0; Status == ACTIVE; i++)
    {
        cout << "Digit :q to quit sequence" << endl;
        cout << "Step " << i << endl;
        string in;
        cin >> in;
        if (in == ":q")
        {
            Status = QUIT;
        }
        else if (in == ":get")
        {
            int intIn;
            cin >> intIn;
            string res = list.get_rec(intIn);
            cout << "Value in " << intIn << " = " << res << endl;
        }
        else if (in == ":del")
        {
            string resDeleted = list.pop_back();
            cout << "Deleted value = " << resDeleted << endl;
            list.printAll();
        }
        else
        {
            list.push_back(in);
            list.printAll();
        }
    }

    cout << "END" << endl;
    list.printAll();
    cout << endl;

}