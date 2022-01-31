#ifndef DETAIL_H
#define DETAIL_H

#include <string>
using namespace std;

//Menu details class
class menuDetail
{
  
  protected:
    string name;
    double price;

  public:
    //Accessor and mutator function for name member
    void setName(string n){name = n;}
    string getName() {return name;}
  
    //Accessor and mutator function for price member
    void setPrice(double p){price = p;}
    double getPrice() {return price;}

    //Default constructor
    menuDetail(){}

   //Deconstructor 
    ~menuDetail(){}
    
};

#endif