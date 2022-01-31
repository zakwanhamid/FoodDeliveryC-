#ifndef QUANTITY_H
#define QUANTITY_H

//Menu quantity class
class menuQtty
{
    private:
        //Quantity
        int qtty;

    public:
        //Accessor and mutator function for qtty member
        void setQtty(int q) {qtty = q;}
        int getQtty() {return qtty;}

        //Default constructor
        menuQtty(){}

        //Deconstructor 
        ~menuQtty(){}

};

#endif