#include <iostream>

class Visitors {
    unsigned int visitors;
    public:
    Visitors (){this->visitors = 0;}
    Visitors (int visitors){
        this->visitors = visitors;
    }
    int increaseVisitorsCount(int counter){
        visitors += counter;
        return visitors;
    }
    int decreaseVisitorsCount(int counter){
        visitors-=counter;
        return visitors;
    }
    int getVisittorsCount(){
        return visitors;
    }

};
int main (){
    int p;
    Visitors a;
    while(p!=0){
        std::cout<<"p:"<<std::endl;
        std::cin>>p;
        if(p>0){
          a.increaseVisitorsCount(p);
          std::cout<<a.getVisittorsCount()<<std::endl;
           
        }
        else {
            a.decreaseVisitorsCount(-p);
            std::cout<<a.getVisittorsCount()<<std::endl;
        }
    }
    std::cout<<a.getVisittorsCount();
    return 0;
}