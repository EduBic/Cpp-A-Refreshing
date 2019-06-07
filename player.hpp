
#include <iostream>

class Card;

class Player {

public:
    std::string _id;

    Card _cards[3];
    const int _maxCards = 3;

    int _score = 0;
    int _indexCardOnTable = -1;

    // Methods

    void addCard(Card card, int index) {
        _cards[index] = card;
    }

    void printPlayerCards() {
        std::cout << "Gioca il Giocatore " << _id << std::endl;
        
        for (int i = 0; i < _maxCards; ++i) {
            if (_cards[i].numero != -1) {
                std::cout << "Carta: " << i  << "  " << _cards[i].print() << std::endl;
            } else {
                std::cout << "Carta non valida: " << i << std::endl;
            }
        }
    }

    Card selectCard() {
        bool validCard1 = false;
        
        while (!validCard1) {
            std::cout << "Seleziona la tua carta:" << std::endl;
            std::cin >> _indexCardOnTable;
            if (_cards[_indexCardOnTable].numero == -1) {
                std::cout << "WARNING Carta non Valida" << std::endl;
            } else {
                validCard1 = true;
            }
        }
        std::cout << "Giocatore " << _id 
                  << " mette carta: " << _cards[_indexCardOnTable].print() 
                  << std::endl << std::endl;

        Card aCard;
        aCard.numero = -1;
        aCard.seme = '-';
        _cards[_indexCardOnTable] = aCard;

        return _cards[_indexCardOnTable]; 
    }

    void drawNewCard(Card iCard) {
        if (_indexCardOnTable == -1)
            std::cout << "DEBUG error in indexCardOnTable" << std::endl; 

        _cards[_indexCardOnTable] = iCard;
        _indexCardOnTable = -1;
    }

};