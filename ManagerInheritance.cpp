/* Programming Assignment 4: Inheritance with a Manager Class
Author: Joe Regina
Date: 10-15-2023
Description: This program calculates the average pay of several 
    managers and determines which manager is the highest paid. */
#include <iostream>
#include <iomanip>
#include "Manager.cpp"

using namespace std;

int main()
{
    // Declare variables for input/totals
    int numManagers;
    string managerName;
    double hourlyWage;
    int hoursWorked;
    double bonusAmount;
    double maxPay = 0.0;
    double totalPay = 0.0;
    int highestPaidIndex;

    // Get number of managers and create managers array
    cout << "Enter number of managers: ";
    cin >> numManagers;
    Manager *theManagers[numManagers];

    // Get info for each manager
    for(int i = 0; i < numManagers; i++)
    {
        cin.ignore();
        cout << "\nEnter manager " << i << " name: ";
        getline(cin, managerName);
        cout << "Enter manager " << i << " hourly wage: ";
        cin >> hourlyWage;
        cout << "Enter manager " << i << " hours worked: ";
        cin >> hoursWorked;
        cout << "Enter manager " << i << " bonus: ";
        cin >> bonusAmount;
        theManagers[i] = new Manager(managerName, hourlyWage, hoursWorked, bonusAmount);
    }

    // Determine the index of the highest paid manager and calculate the total pay
    for(int i = 0; i < sizeof(theManagers) / sizeof(Manager*); i++)
    {
        totalPay += theManagers[i] -> calcPay();
        if(theManagers[i] -> calcPay() > maxPay)
        {
            highestPaidIndex = i;
            maxPay = theManagers[i] -> calcPay();
        }
    }

    // Output highest paid manager and average manager pay
    cout << setprecision(2) << fixed << endl; // Correct decimals for $
    cout << "Highest paid manager is " << theManagers[highestPaidIndex] -> getName() << " who is paid $" << theManagers[highestPaidIndex] -> calcPay() << endl;
    cout << "Average pay is $" << totalPay * 1.0 / numManagers << endl;

    return 0;
}
