#include <iostream>
template <typename T>
T add (T a, T b){
    return a+b;
}
template <typename T>
T mult (T a, T b){
    return a*b;
}
template <typename T>
T sub (T a, T b){
    return a-b;
}
template <typename T>
T div (T a, T b){
    return a/b;
}
int main (){
    int a = 2;
    int b = 5;
    double n = 3.505;
    double m = 2.0;
    std::cout<<add(a,b)<<std::endl;
    std::cout<<mult(m,n)<<std::endl;
    
    return 0;
}

