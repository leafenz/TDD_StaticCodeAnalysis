#include "gegner.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <math.h>

using namespace std;

gegner::gegner()
{
    //ctor
}

gegner::~gegner()
{
    //dtor
}

void gegner::verfolgeSpieler(spieler &Spieler1) {

        int deltaX = Spieler1.getPositionX() - positionx;
        int deltaY = Spieler1.getPositionY() - positiony;

        int length = sqrt(deltaX * deltaX + deltaY * deltaY);
        int dirX = deltaX / length;
        int dirY = deltaY / length;

        positionx += dirX;
        positiony += dirY;
}

void gegner::gegnerHinzufugen(int level) {
    if (level > 1) {
    for(int i=0; i<level; i++){
        int x = rand() % 5;
        int y = rand() % 5;

        cout << "Ein Gegner wurde auf dem Feld (" << x << ", " << y << ") hinzugefügt." << endl;
    }
    }
}

int gegner::getPositionX(){
    return positionx;
}

int gegner::getPositionY(){
    return positiony;
}
