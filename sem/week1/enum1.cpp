#include <iostream>
enum daysOfTheWeek {Monday, Tuesday, Wednesday, Thursday,Saturday, Sunday};
void weekDays(daysOfTheWeek d){
    if(d==Saturday || d==Sunday){
        std::cout<<" its a weekend!"<<std::endl;
    }
    else {
        std::cout<<" go to work"<<std::endl;
    }
}
int main (){
    daysOfTheWeek c = Monday;
    weekDays(c);
    return 0;
}