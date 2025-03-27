#include <iostream>
union Data{
    char* array;
    int number;
};
int main() {
    Data c;
    c.array = new char[256];  // Allocate memory
    //c.number = 5;
    std::cout << "Enter a string: ";
    std::cin.getline(c.array, 255);

    std::cout << "String: " << c.array << std::endl;
    //std::cout<<"Number: "<<c.number<<std::endl;

    delete[] c.array;  // Don't forget to free memory
    return 0;
}