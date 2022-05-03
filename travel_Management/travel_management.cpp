#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void menu();       // main menu function prototype

class ManageMenu
{
protected:
    string userName; // hide admin name

public:
    // virtual void menu(){}
     
    ManageMenu()
    {
        system("color 0A"); // change terminal color
        cout << "\n\n\n\n\n\n\n\n\n\t  Enter Your Name to Continue as an Admin: ";
        cin >> userName;
        system("CLS");
        menu(); // call to main function to load after executing the constructr
    }

     ~ManageMenu() {} // destructors
};

class Customer
{
public:
    string name, gender, address;
    int age, mobileNo, menuBack;
    static int cusID;
    char all[999];

    void getDetails()
    {
        ofstream out("old-customers.txt", ios::app); // open file using append mode to write customer details
        {
            cout << "\nEnter Customer ID: ";
            cin >> cusID;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter Age: ";
            cin >> age;
            cout << "Enter Mobile Number: ";
            cin >> mobileNo;
            cout << "Address: ";
            cin >> address; 
            cout << "Gender: ";
            cin >> gender;
        }
        out << "\nCustomer ID: " << cusID << "\nName: " << name << "\nAge: " << age << "\nMobile Number: " << mobileNo << "\nAddress: " << address << "\nGender: " << gender << endl;
        out.close();
        cout << "\nSaved \nNOTE: We save your details record for future purposes.\n"
             << endl;
    }
    void showDetails() // function to show old customer records
    {
        ifstream in("old-customers.txt");
        {
            if (!in)
            {
                cout << "File Error!" << endl;
            }
            while (!(in.eof()))
            {
                in.getline(all, 999);
                cout << all << endl;
            }
            in.close();
        }
    }
};

int Customer::cusID;

class Cabs
{
public:
    int cabChoice;
    int kilometers;
    float cabCost;
    static float lastCabCost;
   
    void cabDetails()
    {
        cout << "We collaborated with fastest, safest, and smartest cab service arround the country" << endl;
        cout << "-----------ABC Cabs-----------\n"
             << endl;
        cout << "1. Rent a Standard Cab - Rs.15 for 1KM" << endl;
        cout << "2. Rent a Luxury Cab - Rs.25 per 1KM" << endl;

        cout << "\nEnter another key to back or," << endl;

        cout << "Enter which kind of cab you need: ";
        cin >> cabChoice;
        cout << "Enter Kilometers you have to travel: ";
        cin >> kilometers;
        cout << "\nTo calculate the cost for your journey.." << endl;
            
        int hireCab;

        if (cabChoice == 1)
        {
            cabCost = kilometers * 15;
            cout << "\nYour tour will cost " << cabCost << " rupees for a standard cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired standard cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                Sleep(1000);
                system("CLS");
                cabDetails();
            }
        }
        else if (cabChoice == 2)
        {
            cabCost = kilometers * 25;
            cout << "\nYour tour will cost " << cabCost << " rupees for a luxury cab" << endl;
            cout << "Press 1 to hire this cab: or ";
            cout << "Press 2 to select another cab: ";
            cin >> hireCab;
            system("CLS");
            if (hireCab == 1)
            {
                lastCabCost = cabCost;
                cout << "\nYou have successfully hired luxury cab" << endl;
                cout << "Goto Menu to take the receipt" << endl;
            }
            else if (hireCab == 2)
            {
                cabDetails();
            }
            else
            {
                cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
                 Sleep(1000);
                system("CLS");
                cabDetails();
            }
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(1000);
            system("CLS");
            menu();
        }

        cout << "\nPress 1 to Redirect Main Menu: ";
        cin >> hireCab;
        system("CLS");
        if (hireCab == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
};

float Cabs::lastCabCost;

class Chargers : public Cabs, Customer // Multiple Inheritance of some other classes to Chargers
{

public:
    void printBill()
    {
        ofstream outf("receipt.txt"); // receipt for bought items
        {
            outf << "--------ABC Travel Agency--------" << endl;
            outf << "-------------Receipt-------------" << endl;
            outf << "_________________________________" << endl;

            outf << "Customer ID: " << Customer::cusID << endl
                 << endl;
            outf << "User Name:" << Customer::name << endl
                 << endl;
            outf << "Description\t\t Total" << endl;
            outf << "Travel (cab) cost:\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;

            outf << "_________________________________" << endl;
            outf << "Total Charge:\t\t " << fixed << setprecision(2) << Cabs::lastCabCost << endl;
            outf << "_________________________________" << endl;
            outf << "------------THANK YOU------------" << endl;
        }
        outf.close();
        // cout << "Your receipt printed, please get it from the file saved path:D" << endl;
    }
    void showBill()
    {
        ifstream inf("receipt.txt");
        {
            if (!inf)
            {
                cout << "File Error!" << endl;
            }
            while (!(inf.eof()))
            {
                inf.getline(all, 999);
                cout << all << endl;
            }
        }
        inf.close();
    }
};

void menu() // menu function contain main menu
{

    int mainChoice;
    int inChoice;
    int gotoMenu;
    cout << "\t\t      * ABC Travels *\n"
         << endl;
    cout << "-------------------------Main Menu--------------------------" << endl;
    cout << "\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ " << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    //  cout << "\t|\tAgency System Management -> 0" << endl;
    cout << "\t|\tCustomer Management -> 1\t|" << endl;
    cout << "\t|\tCabs Management     -> 2\t|" << endl;
    cout << "\t|\tCharges & Bill      -> 3\t|" << endl;
    cout << "\t|\tExit                -> 4\t|" << endl;
    cout << "\t|\t\t\t\t\t|" << endl;
    cout << "\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|" << endl;

    cout << "\nEnter Choice: ";
    cin >> mainChoice;

    system("CLS");

    Customer a2; // creating objects
    Cabs a3;
    Chargers a4;

    if (mainChoice == 1)
    {
        cout << "------Customers------\n"
             << endl;
        cout << "1. Enter New Customer" << endl;
        cout << "2. See Old Customers" << endl;

        cout << "\nEnter choice: ";
        cin >> inChoice;

        system("CLS");
        if (inChoice == 1)
        {
            a2.getDetails();
        }
        else if (inChoice == 2)
        {
            a2.showDetails();
        }
        else
        {
            cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
            Sleep(100);
            system("CLS");
            menu();
        }
        cout << "Press 1 to Redirect Main Menu: ";
        cin >> gotoMenu;
        system("CLS");
        if (gotoMenu == 1)
        {
            menu();
        }
        else
        {
            menu();
        }
    }
    else if (mainChoice == 2)
    {
        a3.cabDetails();
    }
    else if (mainChoice == 3)
    {
        cout << "-->Get your receipt<--\n"
             << endl;
        a4.printBill();
        cout << "Your receipt is already printed you can get it from file path\n"
             << endl;
        cout << "to display the your receipt in the screen, Enter 1: or Enter another key to back main menu: ";
        cin >> gotoMenu;
        if (gotoMenu == 1)
        {
            system("CLS");
            a4.showBill();
            cout << "Press 1 to Redirect Main Menu: ";
            cin >> gotoMenu;
            system("CLS");
            if (gotoMenu == 1)
            {
                menu();
            }
            else
            {
                menu();
            }
        }
        else
        {
            system("CLS");
            menu();
        }
    }
    else if (mainChoice == 4)
    {
        cout << "\n\n\t--GOOD-BYE!--" << endl;
        Sleep(1000);
        system("CLS");
        ManageMenu();
    }
    else
    {
        cout << "Invalid Input! Redirecting to Previous Menu \nPlease Wait!" << endl;
        Sleep(1000);
        system("CLS");
        menu();
    }
}

int main()
{
    ManageMenu startObj;
    return 0;
}