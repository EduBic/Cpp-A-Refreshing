
#include <stdlib.h>
#include <iostream>
#include <string>

#include "card.hpp"

using std::cout;
using std::endl;

class Deck {

public:

    // Fields

    Card _cards[40];
    int _totCards = 40;

    int _indexesTakenCards[40];
    int _numCartePescate;   // TODO: to english

    // Methods

    void initDeck(const int numeriSize, const int* numeri, const char* semi) {
        // cout << "InitDeck" << endl;

        int numIndex = 0;
        int semeIndex = 0;

        for (int i = 0; i < _totCards; ++i) {
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

        _indexesTakenCards[_totCards];
        for (int i = 0; i < _totCards; ++i) {
            _indexesTakenCards[i] = -1;
        }

        _numCartePescate = 0;
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

        if (_numCartePescate == _totCards) {
            Card empty;
            empty.numero = -1;
            empty.seme = '-';
            
            return empty;
        }

        while (true) {

            int randIndex = (rand() % _totCards);

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

};