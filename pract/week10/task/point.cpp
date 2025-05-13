#include <iostream>
#include <math.h>
class Point {
    protected:
    double x;
    double y;
    public:
    double getX(){return this->x;}
    double getY(){return this->y;}

    void setX(double _x){this->x = _x;}
    void setY(double _y){this->y = _y;}

    void Print(std::ostream& os) const{
        os<<"("<<this->x<<","<<this->y<<")"<<std::endl;
    }
    friend std::ostream& operator<< (std::ostream& os, Point& p) {
        os<<"("<<p.x<<","<<p.y<<")";
        return os;
    }
    double DistanceTo(const Point& other) const{
        double y1 =(this->y - other.y)*(this->y - other.y);
        double x1 = (this->x - other.x)*(this->x - other.x);
        return sqrt(x1 + y1);
    }
    Point(){}
    Point (double _x, double _y){
        this->x = _x;
        this->y = _y;
    }
};
class Figure{
    public:
virtual void print(){std::cout<<"base class"<<std::endl;};
virtual double getPerimeter(){return 0.0;}
virtual double getArea(){return 0.0;}
virtual ~Figure() {}
};

class Triangle: public Figure{
    Point a;
    Point b;
    Point c;
    public:
    Triangle(){}
    Triangle(Point _a, Point _b, Point _c) : a(_a), b(_b), c(_c){}
    double getArea() override{
        double p=(this->getPerimeter())/2;
        double ab = a.DistanceTo(b);
        double bc = b.DistanceTo(c);
        double ca = c.DistanceTo(a);
        return sqrt(p*(p-ab)*(p-bc)*(p-ca));
    }
    double getPerimeter() override{
        return a.DistanceTo(b) + b.DistanceTo(c) + c.DistanceTo(a);
    }
    void print() override {
        std::cout<<"Your triangle:"<<std::endl<<
        "Points: "<<this->a<<" "<<this->b<<" "<<this->c<<std::endl
        <<"Perimeter: "<<this->getPerimeter()<<std::endl
        <<"AreA:"<<this->getArea()<<std::endl;
    }
};
class Quadrilateral:public Figure{
    Point a;
    Point b;
    Point c;
    Point d;
    public:
    Quadrilateral(){}
    Quadrilateral(Point _a, Point _b, Point _c, Point _d) : a(_a), b(_b), c(_c), d(_d) {}
    double getPerimeter() override{
        return a.DistanceTo(b) + b.DistanceTo(c) + c.DistanceTo(d) + a.DistanceTo(d);
    }
    double getArea() override {
        
            // Опитваме се да разделим по диагонала a-c
            Triangle t1(a, b, c);
            Triangle t2(a, c, d);
            double area1 = t1.getArea() + t2.getArea();
        
            // Опитваме се да разделим по диагонала b-d
            Triangle t3(a, b, d);
            Triangle t4(b, c, d);
            double area2 = t3.getArea() + t4.getArea();
        
            // Връщаме по-голямото лице (ако едно от тях е NaN, избираме другото)
            return (area1 > area2) ? area1 : area2;
        }
    
    void print() override{
        std::cout<<"Your Quadrilateral:"<<std::endl<<
        "Points: "<<this->a<<" "<<this->b<<" "<<this->c<<" "<<this->d<<std::endl
        <<"Perimeter: "<<this->getPerimeter()<<std::endl
        <<"Area:"<<this->getArea()<<std::endl;
    }
};
int main (){
    Point p1(2,1);
    Point p2(3,1);
    Point p3(5,4);
    Point p4(10,15);
    std::cout<<"Distance from ";
    std::cout<<p1<<" to "<<p2<< ": "<<p1.DistanceTo(p2)<<std::endl;
    Figure* t = new Triangle(p1, p2, p3); 
    std::cout<<t->getArea()<<" "<<t->getPerimeter()<<std::endl;
    delete t;
    Figure* q = new Quadrilateral(p1, p2, p3, p4);
    q->print();
    delete q;

    return 0;
}