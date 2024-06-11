#include "welt.h"
#include "spieler.h"
#include <iostream>
#include "gegner.h"

using namespace std;
welt::welt()
{
    anzahlRelikte=0;
    level=1;
    do{
        weltErstellen();
    }while(anzahlRelikte==0);

}

welt::~welt()
{
    //dtor
}

void welt::printfield(spieler &Spieler1)
{
    int x = Spieler1.getPositionX();
    int y = Spieler1.getPositionY();

    int newline = 1;
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            bool gegnerAnDerPosition = false;
                for (int k = 0; k < anzahlGegner; ++k) {
                    if (gegnerListe[k].getPositionX() == i && gegnerListe[k].getPositionY() == j) {
                        gegnerAnDerPosition = true;
                    }
                }
            if(x == i && y == j)
            {
                cout << "P";
            }
            else if(gegnerAnDerPosition)
            {
                cout << "E";
            }
            else{
                    cout << spielfeld[i][j];
            }
            if(newline == 5)
            {
                cout << endl;
                newline = 0;
            }
            newline++;
        }
}
}


void welt::feldAuswirkungen(spieler &Spieler1)
{
    int x= Spieler1.getPositionX();
    int y= Spieler1.getPositionY();
    if(spielfeld[x][y] == 'G')
    {
        spielfeld[x][y] = 'L';
        if (rand()%6==1)
        {
            Spieler1.setLebenspunkt('m');
            cout<< "\nEinen Lebenspunkt verloren, Aktuelle LP: ";
        }
        else
        {
            cout << "\nGlueck gehabt keine Punkte verloren";
        }
    }
    if(spielfeld[x][y] == 'B')
    {
        spielfeld[x][y] = 'L';
        Spieler1.setLebenspunkt('p');
    }
    if(spielfeld[x][y] == 'N')
    {
        spielfeld[x][y] = 'L';
    }

    if(spielfeld[x][y] == 'R')
    {
        cout<< "\nEin Relikt gefunden!"<<endl;
        anzahlRelikte--;
        spielfeld[x][y] = 'L';
        Spieler1.setReliktpunkt('p');
        neuesSpielfeld();
    }
}

void welt::neuesSpielfeld(){
    if(anzahlRelikte==0){
        cout<< "\nneue Welt weil alle Relikte gefunden wurden!" << endl;
        level++;
        weltErstellen();
    }
}

void welt::weltErstellen(){
    for(int n=0; n<5; ++n)
    {
        for(int m=0; m<5; ++m)
        {
            int randVal = rand()%10;
            if(randVal < 4)
                spielfeld[n][m] = new emptyField;
            else if(randVal < 8)
                spielfeld[n][m] = 'G';
            else if(randVal < 9)
                spielfeld[n][m] = 'L';
            else
                spielfeld[n][m] = 'R';
        }
    }
    spielfeld[0][0]= 'L';

    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (spielfeld[i][j] == 'R') {
                ++anzahlRelikte;
            }
        }
    }
}

int welt::getLevel(){
    return level;
}

void welt::alleGegnerBewegen(spieler &Spieler1) {
        for (int i = 0; i < anzahlGegner; ++i) {
            gegnerListe[i].verfolgeSpieler(Spieler1);
        }
}

void welt::gegnerHinzufuegen() {
        if (anzahlGegner < 5) {
            gegnerListe[anzahlGegner++] = gegner();
            std::cout << "Gegner hinzugefügt für Level " << level << "." << std::endl;
        }
}

