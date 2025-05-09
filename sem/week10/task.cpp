#include <iostream>
 #include<vector>
 
class Employee{
    protected:
    std::string name;
    int id;
    public:
    Employee(){};
    Employee(std::string _name, int _id){
        this->name = _name;
        this->id = _id;
    }
    virtual int getProjects(Employee* e){
        return 0;
    }
    virtual double getSalary()const {return 0;}
    virtual ~Employee() = default;
    virtual void printInfo() const{
        std::cout<<"name: " <<this->name<<std::endl;
        std::cout<<"id: "<<this->id<<std::endl;
    }
};
class Developer: public Employee{
 
    double baseSalary;
    int projects;
    public:
    Developer(std::string _n, int _id, double _s, int _p) 
    : Employee(_n, _id), baseSalary(_s), projects(_p) {}
    double getSalary() const override {
        return this->baseSalary + this->projects * 0.1;
    }
    void printInfo() const override {
        Employee::printInfo();
        std::cout<<" base salary: "<<this->baseSalary<<std::endl;
        std::cout<<" projects: "<<this->projects<<std::endl;
        std::cout<<" total salary: "<<this->getSalary()<<std::endl;
    }
    int getProjects (Employee* e) override{
        return this->projects;
    }
    ~Developer() = default;
};
class Manager: public Employee{
    double baseSalary;
    std::vector<Employee*> team;
    public:
    Manager(std::string _n, int _id, double _s): Employee(_n, _id), baseSalary(_s) {}
    void addToTeam(Employee* e){
        team.push_back(e);
    }
    double getSalary() const override{
        int total = 0;
        for(Employee* emp: team){
            total+=emp->getProjects(emp);
        }
        return this->baseSalary + total*0.1;
    }
    void printInfo()const override {
        Employee::printInfo();
        std::cout<<" salary: "<<getSalary()<<std::endl
        <<"team size: "<<team.size()<<std::endl;
        std::cout << "==================" << std::endl;
        for(const Employee* emp: team){
            emp->printInfo();
        }
    }
    ~Manager() {
        for (Employee* emp : team) {
            delete emp;  
        }
    }
};
int main (){
    Employee e("Yana",690);
    Employee d("Albena",620);
    e.printInfo();
    d.printInfo();
 
    Employee *ptr = new Developer ("Ivelina",615,2000,100);
    ptr->printInfo();
    delete ptr;


    Manager manager("John Manager", 1, 3000);
    
    
    manager.addToTeam(new Developer("Alice", 101, 2000, 5));
    manager.addToTeam(new Developer("Bob", 102, 2200, 8));
    manager.addToTeam(new Employee("Charlie", 103));
  
    manager.printInfo();
    return 0;
}
