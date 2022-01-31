#ifndef ITEM_H
#define ITEM_H

//Include header file
#include "menuDetail.h"
#include "menuQtty.h"

class menuItem : protected menuDetail //Declaring inheitance of class menuDetail
{
    private:
        double total;
        //Holds value of total daily sales
        double dailytotal[7];
    
        //Declaring compostion object of class menuQtty
        menuQtty Q;

    public:
        //Mutator functions
        void setName(string n)
        {
            //Using inheritance of menuDetail class
            menuDetail::setName(n);
        }

        void setPrice(double p)
        {
            //Using inheritance of menuDetail class
            menuDetail::setPrice(p);
        }

        void setQtty(int q)
        {
            Q.setQtty(q);
        }

        void setTotal()
        {
            total = Q.getQtty() * price;
        }

        void setDailyTotal(int day)
        {
            dailytotal[day] = total;
        }



        //Accessor functions
        string getName()
        {
            return name;
        }

        double getPrice()
        {
            return price;
        }

        int getQtty()
        {
            //Using compostion of menuQtty class
            Q.getQtty();
        }

        double getTotal()
        {
            return total;
        }

        double getDailyTotal(int day)
        {
            return dailytotal[day];
        }


        //Operator overloading to add total member with running total value 
        double operator+ (double totalDaily)
        {
            return total + totalDaily;
        }

        //Declaring print function as a friend function
        friend void print(menuItem, int);

        //Default constructor
        menuItem(){}

        //Deconstructor 
        ~menuItem(){}
    
};

#endif