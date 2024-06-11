#ifndef FIELDS_H
#define FIELDS_H


class fields
{
    public:
        fields(int x, int y);
        void printField();
        virtual ~fields();


    protected:

    private:
        int x;
        int y;
};

#endif // FIELDS_H
