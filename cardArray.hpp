
#include "card.hpp"

class CardArray {

public:

    // CardArray() {}

    CardArray(int length) {
        _length = length;

        _array = new Card[length];
    }

    bool add(Card elem, int index) {
        if (index > _length - 1) {
            return false;
        }

        _array[index] = elem;

        return true;
    }

    Card get(int index) const {
        if (index > _length -1) {
            return Card::getEmptyCard();
        }

        return _array[index];
    }

private:

    int _length;
    Card* _array;

};