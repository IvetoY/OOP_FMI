#ifndef DEVELOPER_H
#define DEVELOPER_H

#include "Employee.h"

class Developer : public Employee {
    double baseSalary;
    int projects;
    
public:
    Developer(std::string _n, int _id, double _s, int _p);
    
    double getSalary() const override;
    void printInfo() const override;
    int getProjects(Employee* e) override;
    
    ~Developer() = default;
};

#endif