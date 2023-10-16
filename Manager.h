// Manager Class Header
#ifndef MANAGER_H
#define MANAGER_H
#include "Employee.h"
#include "Employee.cpp"
using namespace std;

class Manager : public Employee
{
    private:
        double bonus;

    public:
        // Constructor
        Manager(string theName, double theWage, double theHours, double theBonus);
        double calcPay() const; // Calculates sum of employee pay + manager bonus
};
#endif // MANAGER_H
