#include <iostream>
class Time{
    private:
        unsigned int hours;
        unsigned int minutes;
    public:
    Time(){
        this->hours = 0;
        this->minutes = 0;
    }
    Time(unsigned int h, unsigned int m){
        this->hours = h;
        this->minutes = m;
    }
    Time (const Time& other){
        this->hours = other.hours;
        this->minutes = other.minutes;
    }
    Time& operator=(const Time& other){
        if(this!=&other){
            this->hours = other.hours;
            this->minutes = other.minutes;
        }
        return *this;
    }
    ~Time(){
        std::cout<<"Destructor!";
    }
    Time& operator+(const Time& other){
        this->hours = this->hours + other.hours;
        this->minutes = this->minutes + other.minutes;
        return *this;
    }
    bool operator==(const Time& other) const {
        return (this->hours == other.hours) && (this->minutes == other.minutes);
    }
    bool operator<(const Time& other) const {
        std::cout<<"opartor <"<<std::endl;
        if (this->hours < other.hours) return true;
        if (this->hours == other.hours && this->minutes < other.minutes) return true;
        return false;
    }
    public:
    void normalize() {
        hours += minutes / 60;
        minutes %= 60;
        hours %= 24;
    }
    void print(){
        std::cout<<"hours: "<<this->hours<<std::endl;
        std::cout<<"Minutes: "<<this->minutes<<std::endl;
    }

};
int main (){
        Time t(10, 15);
    Time t1(10, 13);
    
    if(t < t1) {
        std::cout << "t is earlier than t1" << std::endl;
    } else {
        std::cout << "t is not earlier than t1" << std::endl;
    }
    
    Time sum = t + t1;
    sum.print();
    return 0;
}