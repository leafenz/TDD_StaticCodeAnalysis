#include <iostream>
#include "fields.h"
#include <stdlib.h>
#include <time.h>
#include <welt.h>
#include <spieler.h>
#include "gegner.h"

using namespace std;

int main()
{
    srand(time(nullptr));
    welt Welt;
    spieler Spieler1;
    Welt.printfield(Spieler1);

    char eingabe;
    do
    {
        cin >> eingabe;

        int x= Spieler1.getPositionX();
        int y= Spieler1.getPositionY();
        if(eingabe=='w'|| eingabe=='W')
        {
            if(x > 0)
            {
                x--;
                Spieler1.setPositionX(x);
            }
        }
        else if(eingabe=='s'|| eingabe=='S')
        {
            if(x < 4)
            {
                x++;
                Spieler1.setPositionX(x);
            }
        }
        else if(eingabe=='d'|| eingabe=='D')
        {
            if(y < 4)
            {
                y++;
                Spieler1.setPositionY(y);
            }
        }
        else if(eingabe=='a'|| eingabe=='A')
        {
            if(y > 0)
            {
                y--;
                Spieler1.setPositionY(y);
            }
        }
        else if(eingabe=='x'|| eingabe=='X')
        {
            cout << "Programm wird beendet." << endl;
        }
        else
        {
            cout << "Unngueltige Eingabe!" << endl;
        }

        Welt.printfield(Spieler1);
        Welt.feldAuswirkungen(Spieler1);
        int lp= Spieler1.getLebenspunkte();
        if(lp==0)
        {
            eingabe='x';
        }
        if(Welt.getLevel()>1)
        {
            Welt.gegnerHinzufuegen();
            Welt.alleGegnerBewegen(Spieler1);
        }
    }
    while(eingabe!= 'x');
    return 0;
}
