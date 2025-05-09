#include "Developer.h"
#include "Employee.h"

Developer::Developer(std::string _n, int _id, double _s, int _p) 
    : Employee(_n, _id), baseSalary(_s), projects(_p) {}

double Developer::getSalary() const {
    return this->baseSalary + this->projects * 0.1;
}

void Developer::printInfo() const {
    Employee::printInfo();
    std::cout << " base salary: " << this->baseSalary << std::endl;
    std::cout << " projects: " << this->projects << std::endl;
    std::cout << " total salary: " << this->getSalary() << std::endl;
}

int Developer::getProjects(Employee* e) {
    return this->projects;
}