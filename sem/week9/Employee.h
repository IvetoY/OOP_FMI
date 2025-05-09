#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

class Employee {
    protected:
        std::string name;
        int id;
        
    public:
        Employee();
        Employee(std::string _name, int _id);
        
        virtual int getProjects(Employee* e);
        virtual double getSalary() const;
        virtual ~Employee() = default;
        
        virtual void printInfo() const;
    };
#endif
