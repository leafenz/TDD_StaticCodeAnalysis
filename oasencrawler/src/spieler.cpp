#include "spieler.h"

spieler::spieler()
{
    //ctor
}

spieler::~spieler()
{
    //dtor
}

void spieler::bewegung(char richtung)
{
    if(richtung=='s'){
        positiony--;
    }
}

int spieler::getPositionX(){
    int x;
    x= this->positionx;
        return x;
}

int spieler::getPositionY(){
    int y=this->positiony;
        return y;
}

void spieler::setPositionX(int x){
    this->positionx= x;
}

void spieler::setPositionY(int y){
    this->positiony= y;
}

void spieler::setLebenspunkt(char option){
    if(LP>0){
        if(option=='m')
            (this->LP)--;
        if(option=='p')
            (this->LP)--;
    }
}

int spieler::getLebenspunkte(){
    return LP;
}

void spieler::setReliktpunkt(char option){
    if(RP>0){
        if(option=='m')
            (this->RP)--;
        if(option=='p')
            (this->RP)--;
    }
}
