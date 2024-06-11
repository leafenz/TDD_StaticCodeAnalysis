#ifndef GEGNER_H
#define GEGNER_H
#include "spieler.h"



class gegner
{
    public:
        gegner();
        virtual ~gegner();
        void gegnerHinzufugen(int level);
        void verfolgeSpieler(spieler &Spieler1);
        int getPositionX();
        int getPositionY();

    protected:

    private:
        int positionx=0;
        int positiony=0;
};

#endif // GEGNER_H
