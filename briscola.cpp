
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>

using namespace std;


struct Card {
    int numero;
    char seme;
};

enum GiocatoreType {
    PlayerOne = 1,
    PlayerTwo = 2
};

bool isContainedInto(const int randInt, const int oldRandIndexArr[], const int oldRandIndexArrSize) {
    
    for (int i = 0; i < oldRandIndexArrSize; ++i) {
        // cout << randInt << " old RandomIndex arr: " << oldRandIndexArr << endl; 
        if (randInt == oldRandIndexArr[i]) {
            return true;
        }
    }

    return false;  
}

Card pescaCarta(const Card mazzo[], const int totCards, int* indiciCartePescate, int & numCartePescate) {
    if (numCartePescate == totCards) {
        Card empty;
        empty.numero = -1;
        empty.seme = '-';
        
        return empty;
    }

    while (true) {

        int randIndex = (rand() % totCards);

        // se primo ciclo > esegui l'if
        // se randIndex non è un num random già visto in passato > esegui l'if
        if (!isContainedInto(randIndex, indiciCartePescate, numCartePescate)) {
            // salvare il numero random già usato
            indiciCartePescate[numCartePescate] = randIndex;
            numCartePescate++;

            // cout << "Pesca carta: " << mazzo[randIndex].numero << '-' << mazzo[randIndex].seme << ' ' << randIndex << endl;
            return mazzo[randIndex];
        }
    }
}

void printPlayerCards(const Card* playerDeck, const int maxDeckPlayer, const string & playerId) {
    cout << "Gioca il Giocatore " << playerId << endl;
    for (int i = 0; i < maxDeckPlayer; ++i) {
        if (playerDeck[i].numero != -1) {
            cout << "Carta: " << i  << "  " << playerDeck[i].numero << '-' << playerDeck[i].seme << endl;
        } else {
            cout << "Carta non valida: " << i << endl;
        }
    }
}

int selectPlayerCard(const Card* playerDeck, const string & playerId) {
    int cartaIndexPlayer1;
    bool validCard1 = false;
    
    while (!validCard1) {
        cout << "Seleziona la tua carta:" << endl;
        cin >> cartaIndexPlayer1;
        if (playerDeck[cartaIndexPlayer1].numero == -1) {
            cout << "WARNING Carta non Valida" << endl;
        } else {
            validCard1 = true;
        }
    }
    cout << "Giocatore " << playerId << " mette carta: " << playerDeck[cartaIndexPlayer1].numero << '-' << playerDeck[cartaIndexPlayer1].seme << endl << endl;

    return cartaIndexPlayer1; 
}

int getPointFromCard(const Card & iCard) {
    if (iCard.numero == 1) {
        return 11;
    } else if (iCard.numero == 3) {
        return 10;
    } else if (iCard.numero == 10) {
        return 4;
    } else if (iCard.numero == 9) {
        return 3;
    } else if (iCard.numero == 8) {
        return 2;
    } else {
        return 0;
    }
}

void whoWinAndComputeScore(const char iBriscola, const char iBriscolaMinor, 
                    const Card & iPlayer1, const Card & iPlayer2,
                    GiocatoreType & oWhoWin, int & oScoreGiocatore1, int & oScoreGiocatore2) {

        int numCardPlayer1      = iPlayer1.numero;
        char seedCardPlayer1    = iPlayer1.seme;
        int numCardPlayer2      = iPlayer2.numero;
        char seedCardPlayer2    = iPlayer2.seme;

        // Cases briscola
        if (seedCardPlayer1 == iBriscola && seedCardPlayer2 != iBriscola) {
            oWhoWin = PlayerOne;
            oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
        }
        else if (seedCardPlayer2 == iBriscola && seedCardPlayer1 != iBriscola) {
            oWhoWin = PlayerTwo;
            oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
        }
        else if (seedCardPlayer1 == iBriscola && seedCardPlayer2 == iBriscola) {

            if (numCardPlayer1 == 1) {
                oWhoWin = PlayerOne;
                oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
            else if (numCardPlayer2 == 1) {
                oWhoWin = PlayerTwo;
                oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
            else if (numCardPlayer1 == 3) {
                oWhoWin = PlayerOne;
                oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
            else if (numCardPlayer2 == 3) {
                oWhoWin = PlayerTwo;
                oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
            else if (numCardPlayer1 > numCardPlayer2 && 
                    numCardPlayer1 != 1 && numCardPlayer1 != 3 && 
                    numCardPlayer2 != 1 && numCardPlayer2 != 3) {
                oWhoWin = PlayerOne;
                oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
            else {
                oWhoWin = PlayerTwo;
                oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
        } 
        else { // nessuno ha la briscola

            // Casi con la briscola minor
            if (seedCardPlayer1 == iBriscolaMinor && seedCardPlayer2 != iBriscolaMinor) {
                oWhoWin = PlayerOne;
                oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
            else if (seedCardPlayer2 == iBriscolaMinor && seedCardPlayer1 != iBriscolaMinor) {
                oWhoWin = PlayerTwo;
                oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
            }
            else if (seedCardPlayer1 == iBriscolaMinor && seedCardPlayer2 == iBriscolaMinor) {

                if (numCardPlayer1 == 1) {
                    oWhoWin = PlayerOne;
                    oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
                }
                else if (numCardPlayer2 == 1) {
                    oWhoWin = PlayerTwo;
                    oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
                }
                else if (numCardPlayer1 == 3) {
                    oWhoWin = PlayerOne;
                    oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
                }
                else if (numCardPlayer2 == 3) {
                    oWhoWin = PlayerTwo;
                    oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
                }
                else if (numCardPlayer1 > numCardPlayer2 && 
                        numCardPlayer1 != 1 && numCardPlayer1 != 3 && 
                        numCardPlayer2 != 1 && numCardPlayer2 != 3) {
                    oWhoWin = PlayerOne;
                    oScoreGiocatore1 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
                }
                else {
                    oWhoWin = PlayerTwo;
                    oScoreGiocatore2 += getPointFromCard(iPlayer1) + getPointFromCard(iPlayer2);
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


    const int totCards = 40;
    Card mazzo[totCards];

    const int numeriSize = 10;
    // Asso, 2, 3, 4, 5, 6, 7, fante, cavallo, re
    const int numeri[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    const int semiSize = 4;
    const char semi[] = {'D', 'C', 'B', 'S'};

    int numIndex = 0;
    int semeIndex = 0;
    for (int i = 0; i < totCards; ++i) {
        Card aCard;
        
        if (numIndex >= numeriSize) {
            numIndex = 0;
            semeIndex++;
        }
        aCard.numero = numeri[numIndex];
        numIndex++;

        // if (semeIndex >= semiSize) {
        //     semeIndex = 0;
        // }
        aCard.seme = semi[semeIndex];
        
        mazzo[i] = aCard;
    }

    // init players data
    const int maxMazzoGiocatore = 3;
    Card mazzoGiocatore1[maxMazzoGiocatore];
    int scoreGiocatore1 = 0;

    Card mazzoGiocatore2[maxMazzoGiocatore];
    int scoreGiocatore2 = 0;

    // Assegnazione delle carte ai giocatori
    
    int indiciCartePescate[totCards];
    for (int i = 0; i < totCards; ++i) {
        indiciCartePescate[i] = -1;
    }
    int numCartePescate = 0;

    Card briscola = pescaCarta(mazzo, totCards, indiciCartePescate, numCartePescate);
    cout << "DEBUG briscola: " << briscola.numero << "-" << briscola.seme << endl;
    
    for (int i = 0; i < maxMazzoGiocatore; ++i) {
        mazzoGiocatore1[i] = pescaCarta(mazzo, totCards, indiciCartePescate, numCartePescate);
        mazzoGiocatore2[i] = pescaCarta(mazzo, totCards, indiciCartePescate, numCartePescate);
    }
    cout << "DEBUG numCartePescate: " << numCartePescate << endl << endl;

     // Default player one begin
    GiocatoreType whoWin = PlayerOne;

    // inizio partita
    for (int manoNum = 0; manoNum < 20; ++manoNum) {
        cout << endl << "### Turno: " << manoNum << " ###" << endl;
        cout << "Briscola: " << briscola.numero << "-" << briscola.seme << endl;
        
        char briscolaMinor = '-';
        int cartaIndexPlayer1 = -1;
        int cartaIndexPlayer2 = -1;

        // Who start?
        if (whoWin == PlayerOne) {
            // Select card start player
            printPlayerCards(mazzoGiocatore1, maxMazzoGiocatore, "1");
            cartaIndexPlayer1 = selectPlayerCard(mazzoGiocatore1, "1");
            briscolaMinor = mazzoGiocatore1[cartaIndexPlayer1].seme;

            // Select card other player
            printPlayerCards(mazzoGiocatore2, maxMazzoGiocatore, "2");
            cartaIndexPlayer2 = selectPlayerCard(mazzoGiocatore2, "2");

        } else if (whoWin == PlayerTwo) {
            // Start Player
            printPlayerCards(mazzoGiocatore2, maxMazzoGiocatore, "2");
            cartaIndexPlayer2 = selectPlayerCard(mazzoGiocatore2, "2");
            briscolaMinor = mazzoGiocatore2[cartaIndexPlayer2].seme;

            // Second Player
            printPlayerCards(mazzoGiocatore1, maxMazzoGiocatore, "1");
            cartaIndexPlayer1 = selectPlayerCard(mazzoGiocatore1, "1");
        }

        // Assert: cartaIndexPlayer1 != -1 && cartaIndexPlayer2 != -1

        whoWinAndComputeScore(briscola.seme, briscolaMinor, 
            mazzoGiocatore1[cartaIndexPlayer1], mazzoGiocatore2[cartaIndexPlayer2], 
            whoWin, scoreGiocatore1, scoreGiocatore2);

        cout << "Vince Giocatore " << whoWin << endl;
        cout << "Punteggio Giocatore 1: " << scoreGiocatore1 << endl;
        cout << "Punteggio Giocatore 2: " << scoreGiocatore2 << endl;
        cout << endl;

        // Draw a card for both players
        if (whoWin == PlayerOne) {
            mazzoGiocatore1[cartaIndexPlayer1] = pescaCarta(mazzo, totCards, indiciCartePescate, numCartePescate);
            if (manoNum == 16) {
                mazzoGiocatore2[cartaIndexPlayer2] = briscola;
            } else {
                mazzoGiocatore2[cartaIndexPlayer2] = pescaCarta(mazzo, totCards, indiciCartePescate, numCartePescate);
            }
        } else if (whoWin == PlayerTwo) {   // whoWin != 1 && whoWin == 2
            mazzoGiocatore2[cartaIndexPlayer2] = pescaCarta(mazzo, totCards, indiciCartePescate, numCartePescate);
            if (manoNum == 16) {
                mazzoGiocatore1[cartaIndexPlayer1] = briscola;
            } else {
                mazzoGiocatore1[cartaIndexPlayer1] = pescaCarta(mazzo, totCards, indiciCartePescate, numCartePescate);
            }
        }

        cout << "DEBUG numCartePescate: " << numCartePescate << endl;
        cout << "DEBUG indiciCartePescate: ";
        for (int i = 0; i < numCartePescate; ++i) {
            int index = indiciCartePescate[i];
            cout << mazzo[index].numero << "-" << mazzo[index].seme << "  ";
        }
        cout << endl;
    }

    if (scoreGiocatore1 > scoreGiocatore2) {
        cout << endl << "Vince Giocatore 1" << endl;
    } else if (scoreGiocatore1 == scoreGiocatore2) {
        cout << endl << "Pareggio" << endl;
    } else {
        cout << endl << "Vince Giocatore 2" << endl;
    }

    // Debug
    for (int i = 0; i < totCards; ++i) {
        // cout << indiciCartePescate[i] << endl;
        // cout << mazzo[i].numero << '-' << mazzo[i].seme << endl;
    }
}