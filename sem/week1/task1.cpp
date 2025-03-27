#include <iostream>
#include <string>  // For std::string
#include <limits>  // For std::numeric_limits
struct Engine{
    int horsePower;
    char fuelType[2];
};
struct Car {
    std::string brand;  // Using std::string instead of char*
    int year;
    double price;
    Engine engine;
};
void print(Car car){
    std::cout<<car.brand<<" is the best car"<<std::endl;
}
void printAllInfo(Car car){
    std::cout<<car.brand<<" is the best car "<<std::endl;
    std::cout<<"only : "<<car.engine.horsePower<<" hp"<<std::endl;
}
int main() {
    Car cars[5];
    
    // Input loop
    /*for(size_t i = 0; i < 5; i++) {
        std::cout << "Enter car #" << i+1 << " details:" << std::endl;
        
        std::cout << "brand: ";
        std::cin >> cars[i].brand;
        
        std::cout << "year: ";
        while(!(std::cin >> cars[i].year)) {  // Input validation for year
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid year: ";
        }
        
        std::cout << "price: ";
        while(!(std::cin >> cars[i].price)) {  // Input validation for price
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a valid price: ";
        }
        
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Clear the input buffer
    }
    
    // Output loop
    std::cout << "\nYour cars:\n";
    for(size_t i = 0; i < 5; i++) {
        std::cout << "Car #" << i+1 << ":" << std::endl;
        std::cout << "brand: " << cars[i].brand << std::endl;
        std::cout << "year: " << cars[i].year << std::endl;
        std::cout << "price: " << cars[i].price << std::endl;
        std::cout << std::endl;
    }*/
    Car c;
    c.brand= "Mercedes";
    c.price = 1000.00;
    c.year = 2023;
    print(c);
    c.engine.horsePower = 450;
    printAllInfo(c);

    return 0;
}