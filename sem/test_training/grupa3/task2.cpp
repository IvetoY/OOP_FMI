#include <iostream>
#include <cstring>

class Car {
private:
    char* brand;
    char* model;
    int year;
    double price;
    int horsePower;
    int color;

    void copy(const Car& other) {
        this->year = other.year;  // Добавено
        this->color = other.color;
        this->horsePower = other.horsePower;
        this->price = other.price;
        this->model = new char[strlen(other.model)+1];  // Поправено от new char към new char[]
        strcpy(this->model, other.model);
        this->brand = new char[strlen(other.brand)+1];
        strcpy(this->brand, other.brand);
    }

public:
    Car() : brand(nullptr), model(nullptr), year(0), price(0), horsePower(0), color(0) {}  // Инициализиране на всички член-данни

    Car(const char* b, const char* m, int y, double p, int hP, int c) {
        this->brand = new char[strlen(b)+1];
        strcpy(this->brand, b);
        this->model = new char[strlen(m)+1];
        strcpy(this->model, m);
        this->year = y;
        this->price = p;
        this->horsePower = hP;
        this->color = c;
    }

    Car(const Car& other) {
        copy(other);
    }

    Car& operator=(const Car& other) {
        if(this != &other) {
            delete[] this->brand;
            delete[] this->model;
            copy(other);
        }
        return *this;
    }

    ~Car() {
        delete[] this->brand;
        delete[] this->model;
    }

    const char* getBrand() const { return this->brand; }  // Добавен const
    const char* getModel() const { return this->model; }  // Добавен const
    int getYear() const { return this->year; }            // Добавен const
    double getPrice() const { return this->price; }       // Добавен const
    int getHorsePower() const { return this->horsePower; }// Добавен const
    int getColor() const { return this->color; }          // Добавен const

    friend std::ostream& operator<<(std::ostream& out, const Car& c) {
        out << "Your car: " << std::endl;
        out << "Brand: " << c.brand << std::endl;  // Опростен изход
        out << "Model: " << c.model << std::endl;
        out << "Year: " << c.year << std::endl;
        out << "Price: " << c.price << std::endl;
        out << "Horse Power: " << c.horsePower << std::endl;
        out << "Color code: " << c.color << std::endl;
        return out;
    }
};

int main() {
    char b[256];
    char m[256];
    std::cout << "brand: ";
    std::cin.getline(b, 255);
    std::cout << "model: ";
    std::cin.getline(m, 255);

    Car c(b, m, 2002, 10.0, 160, 255);  // Поправен брой аргументи
    std::cout << c;  // Извеждане на информацията за колата
    
    return 0;
}
