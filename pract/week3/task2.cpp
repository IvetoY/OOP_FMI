#include <iostream>
class Rational {
    int a;
    unsigned int b;
     int gcd(int x, int y) const {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
    void reduce() {
        int commonDivisor = gcd(abs(a), b);
        a /= commonDivisor;
        b /= commonDivisor;
    }
    public:
    Rational(){
        this->a=0;
        this->b=1;
    }
    Rational(int a, unsigned int b){
        this->a=a;
        this->b=b;
    }
    bool isZero() const { 
        return a==0;
    }
    Rational negate() const{
        return Rational(-a,b);
    }
    void add(Rational& other) {
        a = a * other.b + other.a * b;
        b = b * other.b;
        //reduce();

    }
    Rational sum (Rational& other ) const {
        Rational result(a * other.b + other.a * b, b * other.b);
        result.reduce();
        return result;
    }
    void sub(Rational& other) {
        Rational x;
        x.negate();
        x.sum(other);
    }
    
    void mult(const Rational& other) {
        a = a * other.a;
        b = b * other.b;
        reduce();
    }
    void div(const Rational &other)
    {
        if (!other.a == 0)
        {
            a = a * other.b;
            b = b * other.a;
            reduce();
        }
    }
    void print() const {
        std::cout << a << "/" << b << std::endl;
    }
};
int main (){
    Rational r1(1,2);
    Rational r2(3,4);
    std::cout << "r1: ";
    r1.print();

    std::cout << "r1 is zero: " << (r1.isZero() ? "Yes" : "No") << std::endl;
    Rational r3 = r1.negate();
    std::cout << "-r1: ";
    r3.print();
    Rational r4 = r1.sum(r2);
    std::cout << "Sum of r1 and r2: ";
    r4.print();
    r1.sub(r2);
    std::cout << "r1 - r2: ";
    r1.print();

    r1.mult(r2);
    std::cout << "r1 * r2: ";
    r1.print();

    r1.div(r2);
    std::cout << "r1 / r2: ";
    r1.print();
    return 0;
}