
#include <iostream>

class Card;

using namespace std;

class Player {

public:

    // static: it means that the member it's shared between the instances (objects of type Player)
    static const int MAX_CARDS = 3;

    // constructor
    Player(string iId) {
        cout << "DEBUG: Player: constructor" << endl;
        _id = iId;
    }

    // Methods
    void addCard(Card card, int index) {
        _cards[index] = card;
    }

    void printPlayerCards() {
        cout << "Gioca il Giocatore " << _id << endl;
        
        for (int i = 0; i < MAX_CARDS; ++i) {
            if (_cards[i].numero != -1) {
                cout << "Carta: " << i  << "  " << _cards[i].print() << endl;
            } else {
                cout << "Carta non valida: " << i << endl;
            }
        }
    }

    Card selectCard() {
        
        // human player
        bool validCard1 = false;
    
        while (!validCard1) {
            cout << "Seleziona la tua carta:" << endl;
            cin >> _indexCardOnTable;
            if (_indexCardOnTable < 0 || _indexCardOnTable > 2 || _cards[_indexCardOnTable].numero == -1) {
                cout << "WARNING Carta non Valida" << endl;
            } else {
                validCard1 = true;
            }
        }
        cout << "Giocatore " << _id 
                << " mette carta: " << _cards[_indexCardOnTable].print()
                <<  " index = " << _indexCardOnTable
                << endl << endl;

        
        Card aReturnCard = _cards[_indexCardOnTable];
        
        Card aCard;
        aCard.numero = -1;
        aCard.seme = '-';
        _cards[_indexCardOnTable] = aCard;

        return aReturnCard; 
    }

    Card selectAutoCard(const Card & opponentCard, const char briscola) {
        // IA player
        char aBriscolaMinor = opponentCard.seme;

        // if player 1 play point IA play an highter card if possible, 
        // if not it play a briscola
        // if not it play one of the lowest point card

        if (opponentCard.seme == briscola) {

            if (opponentCard.getPoint > 0) {
                _indexCardOnTable = getHigherCard(briscola);
            }

            if (_indexCardOnTable == -1) {
                _indexCardOnTable = getLowerCard();
            }

        } else { // opponent not briscola

            _indexCardOnTable = getHigherCardWithPointOfSeed(aBriscolaMinor);

            if (_indexCardOnTable == -1) {

                if (opponentCard.getPoint() == 0) {
                    _indexCardOnTable = getLowerCard();
                }
                else if (opponentCard.getPoint() > 0) {
                    // play lower card briscola
                    _indexCardOnTable = getLowerOfSeed(briscola);

                    if (_indexCardOnTable == -1) {
                        // play lower, leave points to opponent
                        _indexCardOnTable = getLowerCard();
                    }

                    // se l'avversario butta una briscola con punti
                    // seleziono la briscola appena più alta 
                    // da quella giocata dall'avversario
                } else {
                    _indexCardOnTable = firstValidCard();
                }
            }
            
        }

        

        cout << "Giocatore " << _id 
                << " mette carta: " << _cards[_indexCardOnTable].print() 
                <<  " index = " << _indexCardOnTable
                << endl << endl;

        Card aReturnCard = _cards[_indexCardOnTable];
        
        Card aCard;
        aCard.numero = -1;
        aCard.seme = '-';
        _cards[_indexCardOnTable] = aCard;

        return aReturnCard; 
    }

    void drawNewCard(Card iCard) {
        if (_indexCardOnTable == -1)
            cout << "DEBUG error in indexCardOnTable" << endl; 

        _cards[_indexCardOnTable] = iCard;
        _indexCardOnTable = -1;
    }

    void printScore() const {
        cout << "Punteggio Giocatore "<< _id << ": " << _score << endl;
    }

    void incrementScore(int iIncrement) {
        _score += iIncrement;
    }

    int getScore() const {
        return _score;
    }

private:

    int getLowerCard() {
        
        int lowerIndex = -1;

        for (int i = 0; i < MAX_CARDS; ++i) {

            if (_cards[i].isValid()) {

                if (lowerIndex == -1) {
                    lowerIndex = i;
                } else if (_cards[lowerIndex].getPoint() > _cards[i].getPoint()) {
                    lowerIndex = i;
                }
            }
        }

        return lowerIndex;
    }

    int getLowerOfSeed(const char & seed) const {
        int lowerIndex = -1;

        for (int i = 0; i < MAX_CARDS; ++i) {

            if (_cards[i].isValid() && _cards[i].seme == seed) {

                if (lowerIndex == -1) {
                    lowerIndex = i;
                } else if (_cards[lowerIndex].getPoint() > _cards[i].getPoint()) {
                    lowerIndex = i;
                }
            }
        }

        return lowerIndex;
    }

    int getHigherCard() const {
        int higherIndex = -1;

        for (int i = 0; i < MAX_CARDS; ++i) {

            if (_cards[i].isValid()) {

                if (higherIndex == -1) {
                    higherIndex = i;
                } else if (_cards[higherIndex].getPoint() < _cards[i].getPoint()) {
                    higherIndex = i;
                }
            }
        }

        return higherIndex;
    }

    int getHigherCard(const char & briscola) const {
        int higherIndex = -1;

        for (int i = 0; i < MAX_CARDS; ++i) {

            if (_cards[i].isValid() && _cards[i].seme == briscola) {

                if (higherIndex == -1) {
                    higherIndex = i;
                } else if (_cards[higherIndex].getPoint() < _cards[i].getPoint()) {
                    higherIndex = i;
                }
            }
        }

        return higherIndex;
    }

    int getHigherCardWithPointOfSeed(const char & seed) const {
        int higherIndex = -1;

        for (int i = 0; i < MAX_CARDS; ++i) {

            if (_cards[i].isValid() && _cards[i].seme == seed && _cards[i].getPoint() > 0) {

                if (higherIndex == -1) {
                    higherIndex = i;
                } else if (_cards[higherIndex].getPoint() < _cards[i].getPoint()) {
                    higherIndex = i;
                }
            }
        }

        return higherIndex;
    }

    int firstValidCard() const {
        for (int i = 0; i < MAX_CARDS; ++i) {
            if (_cards[i].isValid()) {
                return i;
            }
        }

        cout << "ERROR no more card" << endl;
        return -1;
    }

    string _id;

    Card _cards[MAX_CARDS];

    int _score = 0;
    int _indexCardOnTable =  -1;

};