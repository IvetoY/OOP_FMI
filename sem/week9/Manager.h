#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <vector>

class Manager : public Employee {
    double baseSalary;
    std::vector<Employee*> team;
    
public:
    Manager(std::string _n, int _id, double _s);
    
    void addToTeam(Employee* e);
    double getSalary() const override;
    void printInfo() const override;
    
    ~Manager();
};

#endif