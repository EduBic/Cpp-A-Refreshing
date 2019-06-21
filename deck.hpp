
#include <stdlib.h>
#include <iostream>
#include <string>

#include "card.hpp"

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
    Deck(const int numeriSize, const int* numeri, const char* semi) {
        cout << "DEBUG: Deck: constructor" << endl;

        int numIndex = 0;
        int semeIndex = 0;

        for (int i = 0; i < TOT_CARDS; ++i) {
            Card aCard;
            
            if (numIndex >= numeriSize) {
                numIndex = 0;
                semeIndex++;
            }

            aCard.numero = numeri[numIndex];
            numIndex++;

            aCard.seme = semi[semeIndex];
            
            _cards[i] = aCard;
        }

        _indexesTakenCards[TOT_CARDS];
        for (int i = 0; i < TOT_CARDS; ++i) {
            _indexesTakenCards[i] = -1;
        }

        _numCartePescate = 0;

        cout << "DEBUG: Deck: finish constructor" << endl;
    }

    bool isContainedInto(const int randInt, const int oldRandIndexArr[], 
                        const int oldRandIndexArrSize) {
    
        for (int i = 0; i < oldRandIndexArrSize; ++i) {
            // cout << randInt << " old RandomIndex arr: " << oldRandIndexArr << endl; 
            if (randInt == oldRandIndexArr[i]) {
                return true;
            }
        }

        return false;  
    }

    Card drawCard() {
        // cout << "DrawCard" << endl;

        if (_numCartePescate == TOT_CARDS) {
            Card empty;
            empty.numero = -1;
            empty.seme = '-';
            
            return empty;
        }

        while (true) {

            int randIndex = (rand() % TOT_CARDS);

            // se primo ciclo > esegui l'if
            // se randIndex non è un num random già visto in passato > esegui l'if
            if (!isContainedInto(randIndex, _indexesTakenCards, _numCartePescate)) {
                // salvare il numero random già usato
                _indexesTakenCards[_numCartePescate] = randIndex;
                _numCartePescate++;

                // cout << "Pesca carta: " << mazzo[randIndex].numero << '-' << mazzo[randIndex].seme << ' ' << randIndex << endl;
                return _cards[randIndex];
            }
        }
    }

    void printDEBUG() const {
        cout << "DEBUG numCartePescate: " << _numCartePescate << endl;
        cout << "DEBUG indiciCartePescate: ";
        for (int i = 0; i < _numCartePescate; ++i) {
            int index = _indexesTakenCards[i];
            cout << _cards[index].print() << "  ";
        }
        cout << endl;
    }

private:
    // Fields

    static const int TOT_CARDS = 40;
    
    Card _cards[TOT_CARDS];

    int _indexesTakenCards[TOT_CARDS];
    int _numCartePescate;   // TODO: to english

};