#include <iostream>
union number{
    int i;
    float f;
};
struct Price{
    number n;
    char* currency;
};
int main (){
    Price price;
    price.currency = new char [256];
    std::cin.getline(price.currency, 255);

    price.n.i = 5;
    std::cout<<"this cost "<<price.n.i<<" "<<price.currency;
    return 0;
}