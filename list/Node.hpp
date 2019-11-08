
#include <iostream>

using namespace std;

template <class T>
class Node
{
public:

    Node(T val) : value(val), next(nullptr) {}

    void print() const
    {
        cout << value;
        if (next != nullptr)
        {
            cout << ", ";
            next->print();
        }
    }

    T find(int i, int n) const
    {
        if (next != nullptr)
        {
            if (n != i)
            {
                return next->find(i, ++n);
            }
            else
            {
                return value;
            }
        }
        return value;
    }

    Node<T>* get_back()
    {
        if (next != nullptr)
        {
            // TODO: if last but one
            // if (next->next == nullptr)
            // clean next of this node
            // nextSaved = next;
            // next = nullptr
            // return nextSaved->pop_back()
            return next->pop_back();
        }
        return this;
    }

    void setNext(Node* n)
    {
        if (next == nullptr)
        {
            next = n;
        }
        else
        {
            next->setNext(n);
        }
    }

    T getValue() const 
    {
        return value;
    }

private:
    T value;
    Node<T>* next;
};