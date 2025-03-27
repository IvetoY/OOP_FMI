#include<iostream>
#include <cstring>
class Car{
    private:
    char* brand;
    unsigned int year;
    public:
    Car(){
        brand = new char[1];
        brand[0] = '\0'; 
        
        this->year = 0;
    }
    Car(char* b, unsigned int y){
        if (b == nullptr) {
            brand = new char[1];
            brand[0] = '\0';
        } else {
            brand = new char[strlen(b) + 1];
            strcpy(brand, b);
        }
        this->year = y;
    }
    Car(const Car& other){
        this->brand = new char[strlen(other.brand)+1];
        strcpy(this->brand, other.brand);
        this->year = other.year;
    }
    Car& operator=(const Car& other){
        if(this!=&other){
            delete []this->brand;
            this->brand = new char[strlen(other.brand)+1];
            strcpy(this->brand, other.brand);
            this->year = other.year;
        }
        return *this;
    }
    ~Car(){
        delete []this->brand;
    }
    const char* getBrand(){
        return this->brand;
    }
    void print(){
        std::cout<<"Your car:"<<std::endl;
        std::cout<<"Brand: "<<this->brand<<std::endl;
        std::cout<<"Year: "<<this->year<<std::endl;
    }
    unsigned int getYear(){
        return this->year;
    }
};
int main() {
    char brand[256];
    std::cout << "Enter car brand: ";
    std::cin.getline(brand, 255);
    
    Car car1(brand, 2020);

    car1.print();
    return 0;
}