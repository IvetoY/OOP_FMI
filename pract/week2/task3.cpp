#include <iostream>
template <typename T>
T absDifference(T a,T b){
   if((a-b)<0){
    return (a-b)*(-1);
   } 
   else {
    return a-b;
   }
}
template <typename T>
T apply(T (*absDifference)(T,T), T a, T b){
    return absDifference(a,b);
}
int main(){
    double a = 10.3, b = 6.0;
    std::cout<< apply(absDifference, a, b) <<std:: endl; // -> 4.3 
    int c = 3, d = 7;
    std::cout<< apply(absDifference, c, d) << std::endl; // -> 4
    return 0;
}