#include <iostream>
template <typename T>
T findMax (T arr[], size_t n){
    T max = arr[0];
    for(size_t i=1;i<n;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int main(){
    int arr1[5] = {1, 5, 3, 9, 2};
    std::cout << findMax(arr1, 5); // -> 9
    double arr2[4] = {2.5, 7.1, 3.3, 5.0};
    std::cout << findMax(arr2, 4); // -> 7.1
    return 0;
}