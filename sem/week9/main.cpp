#include "Employee.h"
#include "Developer.h"
#include "Manager.h"
#include <iostream>

int main() {
    Employee e("Yana", 690);
    Employee d("Albena", 620);
    e.printInfo();
    d.printInfo();

    Employee *ptr = new Developer("Ivelina", 615, 2000, 100);
    ptr->printInfo();
    delete ptr;

    Manager manager("John Manager", 1, 3000);
    
    manager.addToTeam(new Developer("Alice", 101, 2000, 5));
    manager.addToTeam(new Developer("Bob", 102, 2200, 8));
    manager.addToTeam(new Employee("Charlie", 103));
  
    manager.printInfo();
    return 0;
}