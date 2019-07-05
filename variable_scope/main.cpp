



// Variables on Stack: static allocation
// - automatic
// - static

// Variables on Heap: dynamic allocation

#include <iostream>
#include <string>

using namespace std;


class MyInt {

    public:

        // default constructor
        MyInt() {
            cout << "MyInt: default constr" << endl;
        }

        MyInt(int d) : _data(d) {
            cout << "MyInt: custom constr - " << _data << endl;
        }

        MyInt(const MyInt& val) : _data(val._data + 100) {
            cout << "MyInt: copy constr - " << _data << endl;
        }

        // default deconstructor
        ~MyInt() {
            cout << "~MyInt: default deconstr - " << _data << endl;
        }

        void increment() {
            _data++;
        }

    private:
        int _data;
};

MyInt global27 = MyInt(27);

// pass-by-value => copy
// construct: b, a, return a
// destory: return a, a, b
MyInt fun(MyInt a, MyInt b) {
    //MyInt innerVar(21);

    global27.increment();
    a.increment();
    return a;
}

void foo() {
    static MyInt inVar(1);
    inVar.increment();
}

int main() {
    cout << "# start MAIN" << endl;

    MyInt x42 = MyInt(42);
    MyInt y58 = MyInt(58);

    cout << "# start FUN" << endl;
    MyInt z243 = fun(x42, y58);
    cout << "# finish FUN" << endl;

    foo();
    foo();

    cout << "# finish MAIN" << endl;
}
// Destroy variables

/*
WHAT DOES THE PROGRAM PRINT?

MyInt: custom constr - 27
# start MAIN
MyInt: custom constr - 42
MyInt: custom constr - 58
# start FUN
MyInt: copy constr - 158
MyInt: copy constr - 142
MyInt: copy constr - 243
~MyInt: default deconstr - 143
~MyInt: default deconstr - 158
# finish FUN
MyInt: custom constr - 1
# finish MAIN
~MyInt: default deconstr - 243
~MyInt: default deconstr - 58
~MyInt: default deconstr - 42
~MyInt: default deconstr - 3
~MyInt: default deconstr - 28

*/