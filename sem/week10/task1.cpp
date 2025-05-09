#include <iostream>
class Animal{
    
    public:
    virtual void makeSound(){
        std::cout<<"sound of animal"<<std::endl;
    }
    virtual ~Animal() = default; 
};
class Dog: public Animal{
    public:
    void makeSound() override{
        std::cout<<"bau bau"<<std::endl;
    }

};
class Cat: public Animal{
    public:
    void makeSound() override{
        std::cout<<"mew mew"<<std::endl;
    }
};

int main (){
    Animal* animalPtr = new Dog();
    animalPtr->makeSound();  
    delete animalPtr;

    Animal* animalP = new Cat();
    animalPtr->makeSound();
    delete animalP;

    return 0;
}