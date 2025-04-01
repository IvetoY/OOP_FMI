#include <iostream>
#include <algorithm>
#include <fstream>

template <typename Type>
class BoundSet {
private: 
    Type* set;
    size_t size;
    size_t capacity;

public:
    BoundSet() : size(0), capacity(10), set(new Type[10]()) {}

    BoundSet(Type* s, size_t _s, size_t c) : size(_s), capacity(c), set(new Type[c]()) {
        std::copy(s, s + _s, set);
    }

    BoundSet(const BoundSet& other) : size(other.size), capacity(other.capacity), set(new Type[other.capacity]()) {
        std::copy(other.set, other.set + other.size, set);
    }

    BoundSet& operator=(const BoundSet& other) {
        if(this != &other) {
            delete[] set;
            size = other.size;
            capacity = other.capacity;
            set = new Type[capacity]();
            std::copy(other.set, other.set + size, set);
        }
        return *this;
    }

    ~BoundSet() {
        delete[] set;
    }

    BoundSet operator+(const BoundSet& other) const {
        BoundSet result;
        result.capacity = this->size + other.size + 10; // Добавяме допълнителен капацитет
        delete[] result.set; // Първо изтриваме стария масив
        result.set = new Type[result.capacity](); // След това заделяме нов
        
        // Копираме първия сет
        std::copy(this->set, this->set + this->size, result.set);
        result.size = this->size;
        
        // Добавяме елементи от втория сет
        for(size_t i = 0; i < other.size; i++) {
            result.add(other.set[i]);
        }
        return result;
    }

    BoundSet& operator+=(const BoundSet& other) {
        // Проверка дали имаме достатъчно капацитет
        if(size + other.size > capacity) {
            size_t new_capacity = size + other.size + 10;
            Type* new_set = new Type[new_capacity]();
            std::copy(set, set + size, new_set);
            delete[] set;
            set = new_set;
            capacity = new_capacity;
        }
        
        for(size_t i = 0; i < other.size; i++) {
            add(other.set[i]);
        }
        return *this;
    }

    void add(const Type t) {
        if(!member(t)) {
            if(size >= capacity) { // Ако нямаме място, увеличаваме капацитета
                capacity *= 2;
                Type* new_set = new Type[capacity]();
                std::copy(set, set + size, new_set);
                delete[] set;
                set = new_set;
            }
            set[size++] = t;
        }
    }

    void remove(const Type t) {
        size_t new_size = 0;
        for(size_t i = 0; i < size; i++) {
            if(set[i] != t) {
                set[new_size++] = set[i];
            }
        }
        size = new_size;
    }

    bool member(const Type t) const {
        for(size_t i = 0; i < size; i++) {
            if(set[i] == t) {
                return true;
            }
        }
        return false;
    }
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    friend std::ostream& operator<<(std::ostream& out, const BoundSet& b) {
        out << "Size: " << b.size << "\nNumbers: ";
        for(size_t i = 0; i < b.size; i++) {
            out << b.set[i] << " ";
        }
        return out << "\n";
    }
};

int main() {
    int a[] = {1,2,3};
    int b[] = {5,6,7,1,8,9};
    
    BoundSet<int> b1(a, 3, 20);
    BoundSet<int> b2(b, 6, 20);
    
    b1.add(55);
    b1 += b2;
    
    std::cout << "Size after union: " << b1.getSize() << "\n";
    std::cout << b1;
    std::cout << b2;

    std::ofstream file("text.txt");
    if(!file.is_open()){
        std::cout<<"error";
        return -1;

    }
    else {
        file<<b1<<std::endl;
        file<<b2<<std::endl;
    }
    file.close();
    std::ifstream file1("text.txt");
    std::cout<<std::endl;
    std::cout<<"In your file:"<<std::endl;
    if(!file1.is_open()){
        std::cout<<"error";
        return -1;

    }
    else {
        while(file1.good()){
            std::string t;
        file1>>t;
        std::cout<<t;
        }
        
        //file<<b2<<std::endl;
    }
    file.close();
    
    return 0;
}