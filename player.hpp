
#include <iostream>

class Card;

using namespace std;

class Player {

public:

    // constructor
    Player(string iId) {
        _id = iId;
    }

    // Methods
    void addCard(Card card, int index) {
        _cards[index] = card;
    }

    void printPlayerCards() {
        cout << "Gioca il Giocatore " << _id << endl;
        
        for (int i = 0; i < _maxCards; ++i) {
            if (_cards[i].numero != -1) {
                cout << "Carta: " << i  << "  " << _cards[i].print() << endl;
            } else {
                cout << "Carta non valida: " << i << endl;
            }
        }
    }

    Card selectCard() {
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

    const int _maxCards = 3;


private:
    string _id;

    Card _cards[3];

    int _score = 0;
    int _indexCardOnTable = -1;

};