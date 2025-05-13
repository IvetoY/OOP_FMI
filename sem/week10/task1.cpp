#include <iostream>
#include <vector>
#include <memory>
#include <string>
class Animal{
    protected:
    std::string name;
    public:
    Animal(const std::string& n) : name(n) {}
    virtual void makeSound(){
        std::cout<<"sound of animal"<<std::endl;
    }
    virtual std::unique_ptr<Animal> clone() const = 0;
    virtual ~Animal() = default; 
};
class Dog: public Animal{
    public:
    Dog(const std::string& n) : Animal(n) {}
    std::unique_ptr<Animal> clone() const override {
        return std::make_unique<Dog>(*this);
    }
    void makeSound() override{
        std::cout<<"Im "<<name<<"  -dog " <<std::endl;
    }

};
class Cat: public Animal{
    public:
    Cat(const std::string& n) : Animal(n) {}
    std::unique_ptr<Animal> clone() const override{
        return std::make_unique<Cat>(*this);
    }
    void makeSound() override{
        std::cout<<"Im "<<name<<" -  cat" <<std::endl;
    }

};
class AnimalFactory{
    public:
    static std::unique_ptr<Animal> create(const std::string& type,const  std::string& name ){
        if(type=="dog"){
            return std::make_unique<Dog>(name);}
        else if(type=="cat"){return std::make_unique<Cat>(name);}
        return  nullptr;    
    }
};
int main (){
    /*std::vector<std::unique_ptr<Animal>> animals;
    

    animals.push_back(std::make_unique<Dog>());
    animals.push_back(std::make_unique<Cat>());
    animals.push_back(std::make_unique<Dog>());

    std::cout << "All animals:" << std::endl;
    for (const auto& animal : animals) {
        animal->makeSound();
    }

    while (!animals.empty()) {
        animals.pop_back();  // std::unique_ptr автоматично освобождава паметта
    }*/
    auto a = AnimalFactory::create("dog", "Rex");
    if(a){
    a->makeSound();
    }
    std::vector<std::unique_ptr<Animal>> animals;
    animals.push_back(std::make_unique<Dog>("Karla"));
    animals.push_back(std::make_unique<Cat>("Cat"));
    animals.push_back(AnimalFactory::create("cat", "oop"));
    

    for(const auto& animal: animals ){
        animal->makeSound();
    }
    /*std::unique_ptr<Animal> original = std::make_unique<Dog>("Rex");
    std::unique_ptr<Animal> copy = original->clone();
    std::cout<<"original: "<<std::endl;
    original->makeSound();
    std::cout<<"copy: "<<std::endl;
    copy->makeSound();*/
    
    return 0;
}