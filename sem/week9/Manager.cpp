#include "Manager.h"
#include "Employee.h"
#include "Developer.h"

Manager::Manager(std::string _n, int _id, double _s) 
    : Employee(_n, _id), baseSalary(_s) {}

void Manager::addToTeam(Employee* e) {
    team.push_back(e);
}

double Manager::getSalary() const {
    int total = 0;
    for(Employee* emp: team) {
        total += emp->getProjects(emp);
    }
    return this->baseSalary + total * 0.1;
}

void Manager::printInfo() const {
    Employee::printInfo();
    std::cout << " salary: " << getSalary() << std::endl
              << "team size: " << team.size() << std::endl;
    std::cout << "==================" << std::endl;
    for(const Employee* emp: team) {
        emp->printInfo();
    }
}

Manager::~Manager() {
    for (Employee* emp : team) {
        delete emp;
    }
}
