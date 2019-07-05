
#include <stdlib.h>
#include <iostream>
#include <string>

#include "cardArray.hpp"
#include "myArray.hpp"

using std::cout;
using std::endl;

class Deck {

public:
    // Methods

    // 1 case: No constructors defined
    // C++ adds the default one Deck() {}

    // 2 case: at least one constructor defined
    // no automatic default constructor


    // constructor
    Deck(const int numeriSize, const int* numeri, const char* semi, const int totCards) : _cards(totCards), _indexesTakenCards(totCards) {
        cout << "DEBUG: Deck: constructor" << endl;

        int numIndex = 0;
        int semeIndex = 0;

        for (int i = 0; i < _cards.size(); ++i) {
            Card aCard;
            
            if (numIndex >= numeriSize) {
                numIndex = 0;
                semeIndex++;
            }

            aCard.numero = numeri[numIndex];
            numIndex++;

            aCard.seme = semi[semeIndex];
            
            _cards.add(aCard, i);
        }

        for (int i = 0; i < _indexesTakenCards.size(); ++i) {
            _indexesTakenCards.add(-1, i);
        }

        _numCartePescate = 0;

        cout << "DEBUG: Deck: finish constructor" << endl;
    }

    bool isContainedInto(const int randInt) {
    
        for (int i = 0; i < _indexesTakenCards.size(); ++i) {
            // cout << randInt << " old RandomIndex arr: " << oldRandIndexArr << endl; 
            if (randInt == _indexesTakenCards.get(i)) {
                return true;
            }
        }

        return false;  
    }

    Card drawCard() {
        // cout << "DrawCard" << endl;

        if (_numCartePescate == _indexesTakenCards.size()) {
            return Card::getEmptyCard();
        }

        while (true) {

            int randIndex = (rand() % _indexesTakenCards.size());

            // se primo ciclo > esegui l'if
            // se randIndex non è un num random già visto in passato > esegui l'if
            if (!isContainedInto(randIndex)) {
                // salvare il numero random già usato
                _indexesTakenCards.add(_numCartePescate, randIndex);
                _numCartePescate++;

                // cout << "Pesca carta: " << mazzo[randIndex].numero << '-' << mazzo[randIndex].seme << ' ' << randIndex << endl;
                return _cards.get(randIndex);
            }
        }
    }

    void printDEBUG() const {
        cout << "DEBUG numCartePescate: " << _numCartePescate << endl;
        cout << "DEBUG indiciCartePescate: ";
        for (int i = 0; i < _numCartePescate; ++i) {
            int index = _indexesTakenCards.get(i);
            cout << _cards.get(index).print() << "  ";
        }
        cout << endl;
    }

private:
    // Fields
    
    MyArray<Card> _cards;   // => type MyArray di Card

    MyArray<int> _indexesTakenCards;
    int _numCartePescate;   // TODO: to english

};