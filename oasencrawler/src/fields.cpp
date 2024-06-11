#include "fields.h"
#include <iostream>
using namespace std;

fields::fields(int x, int y)
{
    this->x= x;
    this->y= y;
    cout << "Neues feld wurde erstellt"<< endl;
}

fields::~fields()
{
    //dtor
}

void fields::printField(){
    cout << this->x << this->y << endl;
}
