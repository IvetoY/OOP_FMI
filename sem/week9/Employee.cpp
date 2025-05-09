#include "Employee.h"

Employee::Employee() : name(""), id(0) {}

Employee::Employee(std::string _name, int _id) : name(_name) , id(_id){}

int Employee::getProjects(Employee* e){return 0;}

double Employee::getSalary() const {return 0;}

void Employee::printInfo() const {
    std::cout << "name: " << this->name << std::endl;
    std::cout << "id: " << this->id << std::endl;
}