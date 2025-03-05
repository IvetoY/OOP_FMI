#include <iostream>
template <typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
    
}
int main (){
    int a=2;
    int b=5;
    double a1 = 5.5;
    double b1 = 6.3;
    swap(a,b);
    std::cout<<a<<" "<<b;

    swap(a1,b1);
    std::cout<<a1<<" "<<b1;
    
    return 0;
}