
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>


#include "deck.hpp"
#include "player.hpp"

using namespace std;

// TODO:
// - Refactor whoWin... function

enum GiocatoreType {
    PlayerOne = 1,
    PlayerTwo = 2
};


// Function
void computeWhoWin(const char iBriscola, const char iBriscolaMinor, 
                    const Card & iCardPlayer1, const Card & iCardPlayer2,
                    GiocatoreType & oWhoWin) {

        int numCardPlayer1      = iCardPlayer1.numero;
        char seedCardPlayer1    = iCardPlayer1.seme;
        int numCardPlayer2      = iCardPlayer2.numero;
        char seedCardPlayer2    = iCardPlayer2.seme;

        // Cases briscola
        if (seedCardPlayer1 == iBriscola && seedCardPlayer2 != iBriscola) {
            oWhoWin = PlayerOne;
        }
        else if (seedCardPlayer2 == iBriscola && seedCardPlayer1 != iBriscola) {
            oWhoWin = PlayerTwo;
        }
        else if (seedCardPlayer1 == iBriscola && seedCardPlayer2 == iBriscola) {

            if (numCardPlayer1 == 1) {
                oWhoWin = PlayerOne;
            }
            else if (numCardPlayer2 == 1) {
                oWhoWin = PlayerTwo;
            }
            else if (numCardPlayer1 == 3) {
                oWhoWin = PlayerOne;
            }
            else if (numCardPlayer2 == 3) {
                oWhoWin = PlayerTwo;
            }
            else if (numCardPlayer1 > numCardPlayer2 && 
                    numCardPlayer1 != 1 && numCardPlayer1 != 3 && 
                    numCardPlayer2 != 1 && numCardPlayer2 != 3) {
                oWhoWin = PlayerOne;
            }
            else {
                oWhoWin = PlayerTwo;
            }
        } 
        else { // nessuno ha la briscola

            // Casi con la briscola minor
            if (seedCardPlayer1 == iBriscolaMinor && seedCardPlayer2 != iBriscolaMinor) {
                oWhoWin = PlayerOne;
            }
            else if (seedCardPlayer2 == iBriscolaMinor && seedCardPlayer1 != iBriscolaMinor) {
                oWhoWin = PlayerTwo;
            }
            else if (seedCardPlayer1 == iBriscolaMinor && seedCardPlayer2 == iBriscolaMinor) {

                if (numCardPlayer1 == 1) {
                    oWhoWin = PlayerOne;
                }
                else if (numCardPlayer2 == 1) {
                    oWhoWin = PlayerTwo;
                }
                else if (numCardPlayer1 == 3) {
                    oWhoWin = PlayerOne;
                }
                else if (numCardPlayer2 == 3) {
                    oWhoWin = PlayerTwo;
                }
                else if (numCardPlayer1 > numCardPlayer2 && 
                        numCardPlayer1 != 1 && numCardPlayer1 != 3 && 
                        numCardPlayer2 != 1 && numCardPlayer2 != 3) {
                    oWhoWin = PlayerOne;
                }
                else {
                    oWhoWin = PlayerTwo;
                }
            }
        }
}


int main() {
    srand(time(0));

    // *** Specifiche ***
    // Carte totali: 40 >> 10 + 10 + 10 + 10
    
    // Carta
    //  Numero:
    //  Seme:

    // Mazzo : Card[]
    //  Numero 1 -> 10 dove 1 = Asso, 8 = fante, 9 = cavallo, 10 = re
    //  Seme 'D' 'C' 'B' 'S'

    // Giocatore
    //  Dati:
    //      MazzoGiocatore : Card[] 
    //          mazzo con MAX 3 card
    //      Punteggio : int
    //  Azioni
    //      Inizializza il mazzo
    //      Pesca una carta
    // 

    // Tavolo/Partita
    //  Dati:  
    //      indiciCartePescate : Card[]
    //      turnoPartenzaMano (inizio random, poi del vincitore mano precedente)
    //      Mano
    //          turno di quale giocatore
    //          2 carte messe dai giocatori    
    //          chi vince
    //  Condizione di vittoria partita

    // Briscola:
    //  - Carta pescata dal mazzo
    //  - Seme governa la partita
    //  - L'ultima carta pescata


    // const int totCards = 40;
    // Card mazzo[totCards];

    const int numeriSize = 10;
    // Asso, 2, 3, 4, 5, 6, 7, fante, cavallo, re
    const int numeri[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const int semiSize = 4;
    const char semi[] = {'D', 'C', 'B', 'S'};

    // RAM              Bytes
    // | Card[40]   | => (1 + 8) * 40 = 360
    // | int        | => 8
    // | int[40]    | => 320
    // | int        | => 8
    Deck theDeck(numeriSize, numeri, semi);


    Player player1("1");
    Player player2("2");

    // Assegnazione delle carte ai giocatori

    Card briscola(theDeck.drawCard());
    cout << "DEBUG briscola: " << briscola.print() << endl;

    for (int i = 0; i < Player::MAX_CARDS; ++i) {
        player1.addCard(theDeck.drawCard(), i);
        player2.addCard(theDeck.drawCard(), i);
    }
    // cout << "DEBUG numCartePescate: " << theDeck._numCartePescate << endl << endl;

    // Default player one begin
    GiocatoreType whoWin = PlayerOne;

    // inizio partita
    for (int manoNum = 0; manoNum < 20; ++manoNum) {
        cout << endl << "### Turno: " << manoNum << " ###" << endl;
        cout << "Briscola: " << briscola.print() << endl;
        
        char briscolaMinor = '-';
        Card cartaIndexPlayer1;
        Card cartaIndexPlayer2;

        // Who start?
        if (whoWin == PlayerOne) {
            // Select card start player
            player1.printPlayerCards();
            cartaIndexPlayer1 = player1.selectCard();
            briscolaMinor = cartaIndexPlayer1.seme;

            // Select card other player
            player2.printPlayerCards();
            // IA play a card
            cartaIndexPlayer2 = player2.selectAutoCard(cartaIndexPlayer1, briscola.seme);

        } else if (whoWin == PlayerTwo) {
            // Start Player
            player2.printPlayerCards();
            // IA gioca una carta
            cartaIndexPlayer2 = player2.selectAutoCard(Card(-1, '-'), briscola.seme);
            briscolaMinor = cartaIndexPlayer2.seme;

            // Second Player
            player1.printPlayerCards();
            cartaIndexPlayer1 = player1.selectCard();
        }

        // Assert: cartaIndexPlayer1 != -1 && cartaIndexPlayer2 != -1

        computeWhoWin(briscola.seme, briscolaMinor, 
            cartaIndexPlayer1, cartaIndexPlayer2, whoWin);

        // Compute score turn and
        int scoreTurn = cartaIndexPlayer1.getPoint() + cartaIndexPlayer2.getPoint();

        // Draw new card for both players and assign score turn
        if (whoWin == PlayerOne) {
            player1.incrementScore(scoreTurn);
            player1.drawNewCard(theDeck.drawCard());
            if (manoNum == 16) {
                player2.drawNewCard(briscola);
            } else {
                player2.drawNewCard(theDeck.drawCard());
            }
        } else if (whoWin == PlayerTwo) {   // whoWin != 1 && whoWin == 2
            player2.incrementScore(scoreTurn);
            player2.drawNewCard(theDeck.drawCard());
            if (manoNum == 16) {
                player1.drawNewCard(briscola);
            } else {
                player1.drawNewCard(theDeck.drawCard());
            }
        }

        cout << "Vince Giocatore " << whoWin << endl;
        player1.printScore();
        player2.printScore();
        cout << endl;

        theDeck.printDEBUG();
    }

    if (player1.getScore() > player2.getScore()) {
        cout << endl << "Vince Giocatore 1" << endl;
    } else if (player1.getScore() == player2.getScore()) {
        cout << endl << "Pareggio" << endl;
    } else {
        cout << endl << "Vince Giocatore 2" << endl;
    }
}