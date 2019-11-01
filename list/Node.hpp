
#include <iostream>

using namespace std;

class Node
{
public:

    Node(int val) : value(val), next(nullptr) {}

    void print() const {
        cout << ", " << value;
        if (next != nullptr)
        {
            next->print();
        }
    }

    void setNext(Node* n) {
        if (next == nullptr)
        {
            next = n;
        }
        else
        {
            next->setNext(n);
        }
    }

private:
    int value;
    Node* next;
};