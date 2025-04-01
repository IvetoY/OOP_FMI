#include <iostream>
#include <cstring>
class Car{
    private:
    char* brand;
    char* model;
     int year;
    double price;
     int horsePower;
    int color;
    void copy(const Car& other){
        this->year = other.year;
        this->color=other.color;
        this->horsePower = other.horsePower;
        this->price = other.price;
        this->model = new char (strlen(other.model)+1);
        strcpy(this->model, other.model);
        this->brand = new char (strlen(other.brand)+1);
        strcpy(this->brand, other.brand);
    }
    public:
    Car(){
        this->brand = nullptr;
        this->model = nullptr;
        this->year=0;
        this->price =0;
        this->horsePower =0;
        this->color=0;

    };
    Car(const char* b, const char* m, const int y, double p,const int hP, int c){
        this->brand = new char [strlen(b)+1];
        strcpy(this->brand, b);
        this->model = new char [strlen(m)+1];
        strcpy(this->model, m);
        this->year = y;
        this->price = p;
        this->horsePower = hP;
        this->color = c;
    }
    Car(const Car& other){
        copy(other);
    }
    Car& operator=(const Car& other){
        if(this!=&other){
            delete []this->brand;
            delete [] this->model;
            copy(other);
        }
        return *this;
    }
    ~Car(){
        delete []this->brand;
        delete [] this->model;
    }
   const char* getBrand()const{
        return this->brand;
    }
    const char* getModel()const{
        return this->model;
    }
    int getYear()const{
        return this->year;
    }
    double getPrice()const{
        return this->price;
    }
    int getHorsePower()const{
        return this->horsePower;
    }
    int getColor()const{
        return this->color;
    }
    friend std::ostream& operator<<(std::ostream& out,const Car& c){
        out<<"Your car: "<<std::endl;
        out<<"Brand: "<<std::endl;
        out << "Brand: " << c.brand << std::endl; 
        out<<"Model: "<<std::endl;
        out << "Model: " << c.model << std::endl;
        out<<"Year: "<<c.year<<std::endl;
        out<<"Price: "<<c.price<<std::endl;
        return out;
    }
};
int main (){
    char b[256];
    char m[256];
    std::cout<<"brand: "<<std::endl;
    std::cin.getline(b,255);
    std::cout<<"model: "<<std::endl;
    std::cin.getline(m,255);

    Car	 c(b, m, 2002, 10.0, 160, (char)255);
    return 0;
}