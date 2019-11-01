#include "Node.hpp"

class List
{
public:

    List() : _size(0), _first(nullptr) {}

    void add(int val)
    {
        Node* newNodePtr = new Node(val);

        if (_first == nullptr)
        {
            // list empty
            _first = newNodePtr;
        }
        else
        {
            _first->setNext(newNodePtr);
        }

        _size++;
    }

    void print()
    {
        cout << "[";
        if (_first != nullptr)
        {
            _first->print();
        }
        cout << "]" << endl;
    }

    int size() const
    {
        return _size;
    }

    int _size;
    Node* _first;

};