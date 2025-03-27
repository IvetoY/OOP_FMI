#include <iostream>
class Rectangle{
    private:
    unsigned int width;
    unsigned int height;
    public:
    Rectangle(){
        this->height = 0;
        this->width = 0;
    }
    Rectangle(int h, int w){
        this->height = h;
        this->width = w;
    }
    Rectangle (const Rectangle& other){
        this->height = other.height;
        this->width = other.width;
    }
    Rectangle& operator=(const Rectangle& other){
        if(this!=&other){
            this->height = other.height;
            this->width = other.width;
        }
        return *this;
    }
    ~Rectangle(){
        std::cout<<"Destructor!"<<std::endl;
    }
    int area(){
        unsigned int s;
        s = (this->height) * (this->width);
        return s;
    }
    int perimeter(){
        unsigned int p = 2*((this->height)+(this->width));
        return p;
    }
    void resize(double k){
        this->height = height * k;
        this->width = width * k;
        std::cout<<"h: "<<height<<std::endl;
        std::cout<<"w: "<<width<<std::endl;
    }
};
int main(){
    Rectangle c(5,6);
    std::cout<<"P= "<<c.perimeter()<<std::endl;
    std::cout<<"S= "<<c.area()<<std::endl;
    c.resize(2.00);
    
    return 0;
}

