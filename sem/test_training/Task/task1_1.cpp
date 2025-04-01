#include <iostream>
#include <cstring>
class Employee{
    private:
    char* name;
    char* position;
    unsigned int salary;
    int ID[10];
    void copy(const Employee& other){
        this->name = new char[strlen(other.name)+1];
        strcpy(this->name, other.name);
        this->position = new char [strlen(other.position)+1];
        strcpy(this->position, other.position);
        for(size_t i=0;i<10;i++){
            this->ID[i]=other.ID[i];
        }
        this->salary = other.salary;

    }
    char* getName(){
        return this->name;
    }
    char* getPosition(){
        return this->position;
    }
    unsigned getSalary(){
        return this->salary;
    }
    
    
    public:
    friend std::ostream& operator<<(std::ostream& out, const Employee& e){
        out << "Employee's information: "<< std::endl;
        out << "Name: "<<e.name<<std::endl;
        out << "Position: "<<e.position<<std::endl;
        out << "Salary: "<<e.salary<<std::endl;
        out << "ID: ";
        for(size_t i=0;i<10;i++){
            out<<e.ID[i];
        }
        out<<std::endl;
        return out;

    }
    Employee(){
        this->name = new char[1];
        this->name[0]='\0';
        this->position = new char[1];
        this->position[0]='\0';
        for(size_t i=0;i<10;i++){
            ID[i]=0;
        }
        this->salary = 0;
    }
    Employee(const char* n, const char* p, unsigned int s, int _ID[]){
        this->name = new char[strlen(n)+1];
        strcpy(this->name, n);
        this->position = new char[strlen(p)+1];
        strcpy(this->position, p);
        for(size_t i=0;i<10;i++){
            this->ID[i]=_ID[i];
        }
        this->salary = s;
        
    }
    Employee(const Employee& other){
        copy(other);
    }
    Employee& operator=(const Employee& other){
        if(this!=&other){
            delete [] this->name;
            delete [] this->position;
            copy(other);
        }
        return *this;
    }
    ~Employee(){
        delete []this->name;
        delete []this->position;
    }
    bool operator==(const Employee& other){
        return strcmp(this->position, other.position) == 0;
    }
    
};
class Company{
    private:
    size_t size;
    Employee* employees;
    void copy(const Employee& other){
        this->employees = new Employee [this->size];
    }
    public:
    Company(Employee* e, size_t s){
        this->size = s;
        this->employees = new Employee [this->size];
    }
    Company(const Employee& other){
        copy(other);
    }
};
int main(){
    char name1[256];
    char position1[256];
    std::cout<<"Name:"<<std::endl;
    std::cin.getline(name1,255);
    std::cout<<"Position:"<<std::endl;
    std::cin.getline(position1,255);
    int ID[10]={1,2,3,4,5,6,7,8,9,0};
    Employee e1 (name1, position1, 2000, ID);
    Employee e2 (name1, position1, 3000, ID);
    if(e1==e2){
        std::cout<<"the same position"<<std::endl;
    }
    else {
        std::cout<<"different positions"<<std::endl;

    }
    std::cout<<e1<<std::endl;
    int n;
    std::cin>>n;
    
    return 0;
}