#include <iostream>
template <typename T> 
T findMin (T arr[], size_t size){
    T min = arr[0];
    for(size_t i=1;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    return min;
}
int main (){
    int numbers[] = {5, 3, 8, 1, 7};
std::cout << findMin(numbers, 5) << std::endl; // Извежда: 1

double values[] = {3.14, 2.71, 1.41, 1.73};
std::cout << findMin(values, 4) << std::endl; // Извежда: 1.41
    return 0;
}