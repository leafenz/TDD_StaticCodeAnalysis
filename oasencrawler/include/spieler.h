#ifndef SPIELER_H
#define SPIELER_H


class spieler
{
    public:
        spieler();
        virtual ~spieler();
        void bewegung(char richtung);
        int getPositionX();
        int getPositionY();
        int getLebenspunkte();
        void setPositionX(int x);
        void setPositionY(int y);
        void setLebenspunkt(char option);
        void setReliktpunkt(char option);

    protected:

    private:
        int LP=5;
        int RP=0;
        int positionx=0;
        int positiony=0;
};

#endif // SPIELER_H
