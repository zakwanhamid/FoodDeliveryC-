#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "menuItem.h"

using namespace std;

//Function prototype declaration
void readFile(string, string*, double*, int&);
void writeFile (string, string*, double*, int);
void showMenu(string*, double*, int);
void addMenu(string*, double*, int&);

int inputVal(int ); //Input validation function 

int main()
{
    //File access variable
    string fileName = "menu.txt";
    int menuSize = 0;
    string menuName[100];
    double menuPrice[100];

    readFile(fileName, menuName, menuPrice, menuSize);

    int day = 7;


    menuItem item[100]; //Declaring object array

    string name;
    double price;
    int qtty;

    int choice;
    char inChoice = ' ';
    bool menuChoice = false;

    double dailysales[7]; //Holds daily total sales for a week
    
    double totalDaily = 0; //Holds temp value for total daily sales (Value will be assigned to array)
    double totalWeek = 0; //Holds value of total sales for the week


    //Program start
    while (menuChoice == false)
    {
      //User interface menu
      cout << endl << endl;
      cout << "Cafe ABC daily sales system" << endl;
      cout << "Welcome! " << endl;
      cout << "----------------------------" << endl;
      cout << "1. Show Menu" << endl;
      cout << "2. Add Menu" << endl;
      cout << "3. Record Daily Sales" << endl;
      cout << "----------------------------" << endl;

      //Prompt input 
      cout << "Input: ";
      cin >> choice;
      cin.ignore();

      //Input validation
      while (choice < 1 || choice > 3)
      {
        cout << "Invalid input. Please try again: ";
        cin >> choice;
        cin.ignore();
      }

        //Determine the choice 
        switch (choice)
        {
          //Show menu
          case 1:
          {
            showMenu(menuName, menuPrice, menuSize);
            break;
          }
          
          //Add menu
          case 2:
          {
            addMenu(menuName, menuPrice, menuSize);
            break;
          }

          //Daily update menu
          case 3:
          {
                cout << endl;
                for (int j = 0; j < day; j++)
                {
                    cout << "******************************" << endl;
                    //Print prompt header
                    cout << "-----------" << endl;
                    cout << "| Day #" << (j+1) << ": |" << endl;
                    cout << "-----------" << endl;


                    for (int i = 0; i < menuSize; i++)
                    {
                        //Set value to respective object member
                        item[i].setName(menuName[i]);
                        item[i].setPrice(menuPrice[i]);
                        cout << "Menu name: " << item[i].getName() << endl;
                        cout << "Menu price: " << fixed << setprecision(2) << item[i].getPrice() << endl;

                        cout << "Input quantity: ";
                        cin >> qtty;
                        qtty = inputVal(qtty);
                        item[i].setQtty(qtty);

                        item[i].setTotal();
                        item[i].setDailyTotal(j);

                        //Calculate total daily
                        totalDaily = item[i] + totalDaily;

                        cout << "-------------------------------------- " << endl;

                        print(item[i], j);

                        cout << "-------------------------------------- " << endl;
                        cout << endl;
                          
                    }

                    //Assign temporary value into array 
                    dailysales[j] = totalDaily;

                    //Reset value
                    totalDaily = 0;
                    
                    //Update running total
                    totalWeek += dailysales[j];

                }

                cout << endl << endl;

                //Print output 
                cout << "*****************" << endl;
                cout << "* Sales record: *" << endl;
                cout << "*****************" << endl;
                
                //Print total daily sales for each item
                for (int j = 0; j < day; j++)
                {
                  cout << "-----------" << endl;
                  cout << "| Day #" << (j+1) << ": |" << endl;
                  cout << "-----------" << endl;

                  cout << "Total daily sales = RM " << fixed << setprecision(2) << dailysales[j] << endl;

                  for (int i = 0; i < menuSize; i++)
                  {
                    cout << "- " << item[i].getName() << " : RM " << fixed << setprecision(2) << item[i].getDailyTotal(j) << endl;
                  }

                  cout << endl;

                }

                //Print total sales for the week
                cout << "-----------------------------------------" << endl;
                cout << "Total sales for " << day << " day: RM " << totalWeek << endl;
                cout << "-----------------------------------------" << endl;

                break;
              }

            //Default case 
            default:
            {break;}

        }

        //Validate choice input 
        cout << endl << "Do you want to continue? (Y/N): ";
        cin >> inChoice;

        while (inChoice != 'N' && inChoice != 'n' && inChoice != 'Y' && inChoice != 'y')
        {
          cout << "Choice invalid. Please try again: ";
          cin >> inChoice;
        }

        if (inChoice == 'N' || inChoice == 'n')
        {
          menuChoice = true;
        }
      
    }

      writeFile(fileName, menuName, menuPrice, menuSize);

      return 0;

}

//Print total daily sales for each item
void print(menuItem item, int day)
{
  cout <<  item.getName() << " daily sales: RM " << item.getDailyTotal(day) << endl;
}

//Validate input not to be negative number
int inputVal(int in)
{
  while (in < 0)
  {
    cout << "Input invalid! Please input again: ";
    cin >> in;
  }

return in;
} 

//Open and read file
void readFile(string n, string* name, double* price, int &size)
{
    ifstream f;
    f.open(n);
    
    while(!f.eof())
    {
      getline(f, name[size], '_');
      f >> price[size];
      f.ignore();
      ++size;} 
  
    f.close();
}

//Write and close file 
void writeFile(string n, string* name, double* price, int size)
{
    fstream f(n);

    f.clear();
    f.seekg(0);

    for (int i = 0; i < size; i++)
    {
        if (i < (size - 1))
        {
          f << name[i] << "_" <<  price[i] << endl;
        }
        else
        {
          f << name[i] << "_" <<  price[i];
        }
    }
    f.close();
}

//Show menu function
void showMenu(string* name, double* price, int size)
{
  cout << "\nMenu:----------------------------------" << endl;
  for (int i = 0; i < size; i++)
  {
    if (name[i].length() <= 12)
    {
      cout << (i + 1) << ". " << name[i] << "\t\t\t" << "RM " << fixed << setprecision(2) << price[i] << endl;
    }
    else
    {
      cout << (i + 1) << ". " << name[i] << "\t\t" << "RM " << fixed << setprecision(2) << price[i] << endl;
    }

  }
  cout << "---------------------------------------" << endl << endl;

}

//Add menu function
void addMenu(string* name, double* price, int& size)
{
  cout << "\nAdd Menu:----------------------" << endl;
  cout << "Input new menu name: ";
  getline(cin, name[size]);
  cout << "Input new menu price: ";
  cin >> price[size];
  size++;
  cout << "Done updating! Thank you." << endl;
  cout << "--------------------------------" << endl;
}