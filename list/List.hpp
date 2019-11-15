#include "Node.hpp"

template <class T>
class List
{
public:

    List() : _size(0), _first(nullptr) {}

    void push_back_rec(T value)
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

    void push_back(T value)
    {
        if (_first == nullptr)
        {
            _first = new Node<T>(value);
        }
        else 
        {
            // at least 1 element in the list
            Node<T>* cursor = _first;

            // until cursor is not the last element of the list
            while (cursor->next != nullptr)
            {
                cursor = cursor->next;
            }

            cursor->next = new Node<T>(value);
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
    // example: [2, 4, 65] => [4, 65]

    T pop_back_rec()
    {
        if (_first != nullptr)
        {
            Node<T>* nodeToDelete = _first->get_back();
            T valBackup = nodeToDelete->getValue();
            delete nodeToDelete;
            _size--;
            return valBackup;
        }
        return T();
    }

    T pop_back()
    {
        if (_first != nullptr)
        {
            // not empty list

            // Assume 1 element in the list
            Node<T>* lastNodeSaved = _first;
            Node<T>* cursor = _first;
            
            while (cursor->next != nullptr)
            {
                if (cursor->next->next == nullptr)
                {
                    // N list, I'm in the last but one
                    lastNodeSaved = cursor->next;
                    cursor->next = nullptr;
                }
                else
                {
                    // N elements in the list
                    cursor = cursor->next;
                }
            }

            if (lastNodeSaved == _first) {
                // only 1 element in the list
                _first = nullptr;
            }

            T valBackup = lastNodeSaved->getValue();
            delete lastNodeSaved;
            _size--;
            return valBackup;
        }
        // empty list
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

private:

    int _size;
    Node<T>* _first;

};