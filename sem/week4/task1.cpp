#include <iostream>
#include <cstring>
class Person {
    private:
        char* name;
        unsigned int age;
    public:
        Person(const char* name, const unsigned int age){
            this->name = new char [strlen(name)+1];
            this->age = age;
        }
        Person (const Person& other){
           this->age = other.age;
           this->name = new char [strlen(other.name)+1];
           strcpy(this->name, other.name); 
        }
        Person& operator=(const Person& other){
            if(this!=&other) {
                delete [] this->name;
                this->age = other.age;
                this->name = new char [strlen(other.name)+1];
                strcpy(this->name, other.name);
            }
            return *this;
        }
        char* getName(){
            return this->name;
        }
        int getAge(){
            return this->age;
        }
        void introduce(){
            std::cout<<"hello, im "<<getName()<<" and im "<<getAge()<<" years old!"<<std::endl;
        }
};
int main (){
    Person p("Ivan", 25);
    p.introduce();
    return 0;
}