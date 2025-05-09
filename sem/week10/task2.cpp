
#include <vector>
#include <memory>
#include <iostream>
struct Point{
    double x;
    double y;
};
class Shape{
    public:
    virtual void area() const {std::cout<<"area of shape";}
    virtual ~Shape() = default;
};
class Circle: public Shape{
    private:
    double r;
    Point center;
    public: 
    Circle (double radius, double _x, double _y){this->r = radius;this->center.x = _x; this->center.y = _y;}
    
};
class Rectangle: public Shape{
    private:
    Point a;
    Point c;
    public:
    Rectangle(double a_x,double a_y, double c_x, double c_y){
        this->a.x=a_x;
        this->a.y = a_y;
        this->c.x = c_x;
        this->c.y = c_y;
    }
    
};
class Triangle: public Shape{
    private:
    Point a;
    Point b;
    Point c;
    public:
    Triangle(double a_x,double a_y, double b_x, double b_y, double c_x, double c_y){
        this->a.x=a_x;
        this->a.y = a_y;
        this->b.x = b_x;
        this->b.y = b_y;
        this->c.x = c_x;
        this->c.y = c_y;
    }

};
int main (){
   

    return 0;
}