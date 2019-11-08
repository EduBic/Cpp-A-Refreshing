#include "Node.hpp"

template <class T>
class List
{
public:

    List() : _size(0), _first(nullptr) {}

    void add(T value)
    {
        Node<T>* newNodePtr = new Node<T>(value);

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

    T get(const int i) const
    {
        if (_first != nullptr) 
        {
            return _first->find(i, 0); 
        }
        else
        {
            return T();
        }
    }

    // TODO: pop_front
    // [2, 4, 65] => [4, 65]

    T pop_back()
    {
        if(_first != nullptr)
        {
            Node<T>* nodeToDelete = _first->get_back();
            T valBackup = nodeToDelete.getValue();
            delete nodeToDelete;
            size--;
            return valBackup;
        }
        return T();
    }

    void printAll()
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
    Node<T>* _first;

};