#include <iostream>
class DynamicArray{
    private:
    int size;
    int* data;
    public:
    DynamicArray(){
        this->size = 0;
        this->data  = nullptr;
        std::cout<<"default constructor"<<std::endl;
    };
    DynamicArray(int size){
        this->size = size;
        this->data  = new int [this->size];
        for(int i=0;i<this->size;i++){
            data[i]=i+1;
        }
        std::cout<<" constructor"<<std::endl;
    };

    DynamicArray(const DynamicArray& other){
        this->size = other.size;
        this->data = new int [this->size];
        for(int i=0;i<this->size;i++){
            this->data[i] = other.data[i];
        }
        std::cout<<"copy constructor"<<std::endl;
    };
    DynamicArray& operator=(const DynamicArray& other){
        if(this==&other) return *this;

        delete [] this->data;
        this->size = other.size;
        this->data = new int [this->size];
        for(int i=0;i<this->size;i++){
            this->data[i] = other.data[i];
        }
        std::cout<<"operator="<<std::endl;
        return * this;


    }
    ~DynamicArray(){
        delete []this->data;
        std::cout<<"delete"<<std::endl;
    };
    void resize(int newSize){
        int* newData = new int[newSize];
        for(int i=0;i<this->size;i++){
            newData[i]=this->data[i];
        }
        delete [] this->data;
        this->data = newData;
        this->size = newSize;
    }
    void push(int value){
        resize(this->size + 1);
        this->data[this->size - 1] = value;
    }
    void print(){
        for(int i=0;i<this->size;i++){
            std::cout<<this->data[i]<<" ";
        }
        std::cout<<std::endl;
    }
};
int main (){
    DynamicArray arr(0);
arr.push(1);
arr.push(2);
arr.push(3);
arr.print(); 
    return 0;
}