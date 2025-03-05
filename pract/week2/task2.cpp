#include <iostream>
template <typename T> 
void sort (T arr[], size_t n){
    for(size_t i=0;i<n;i++){
        for(size_t j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                T temp = arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
}
template <typename T>
void print (T arr[],size_t n){
    for(size_t i=0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
}
int main(){
    int arr1[5] = {1, 5, 3, 9, 2};
    sort(arr1, 5);
    print(arr1,5);  // -> 1 2 3 5 9
    double arr2[4] = {2.5, 7.1, 3.3, 5.0};
    sort(arr2, 4);
    print(arr2,4);  // -> 2.5 3.3 5.0 7.1
    return 0;
}