#include <iostream>
enum type {SEDAN, SUV, TRUCK};
struct Car{
    char* brand;
    int year;
    type t;
};
int main (){
    Car c;
    std::cin.getline(c.brand,255);
    c.year = 2005;
    c.t = TRUCK;
    std::cout<<"brand: "<<c.brand<<std::endl;
    std::cout<<"year: "<<c.year<<std::endl;
    std::cout<<"type: "<<c.t<<std::endl;
    return 0;
}