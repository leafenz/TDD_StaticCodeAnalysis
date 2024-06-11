#ifndef WELT_H
#define WELT_H
#include <spieler.h>
#include "gegner.h"


class welt
{
    public:
        welt();
        virtual ~welt();
        int dimension=5;
        char spielfeld[5][5];
        void printfield(spieler &Spieler1);
        void feldAuswirkungen(spieler &Spieler1);
        void neuesSpielfeld();
        void weltErstellen();
        int getLevel();
        void alleGegnerBewegen(spieler &Spieler1);
        void gegnerHinzufuegen();

    protected:

    private:
        int anzahlRelikte;
        int level;
        gegner gegnerListe[5]; // höchstens 5 Gegner
        int anzahlGegner;

};

#endif // WELT_H
