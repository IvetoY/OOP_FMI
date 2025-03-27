#include <iostream>
class Vector{
    private:
    int* data;
    size_t size;
    size_t capacity;
    public:
    Vector(){
        this->size = 16;
        this->data = new int[16]{};

    }
    Vector(size_t size){
        this-> size = size;
        this-> data = new int [size]{};
    }
    Vector(size_t size, int val){
        this->size = size;
        this->data = new int[16];
        for(size_t i=0;i<size;++i){
            this->data[i] = val;
        }
    }
     Vector(const Vector& other) {
        this->size = other.size;
        this->data = new int[other.size];
        for (size_t i = 0; i < this->size; ++i) {
            this->data[i] = other.data[i];
        }
    }
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] this->data;
            this->size = other.size;
            this->data = new int[other.size];
            for (size_t i = 0; i < this->size; ++i) {
                this->data[i] = other.data[i];
            }
        }
        return *this;
    }
    ~Vector(){
        delete [] this->data;
    }
    void clear(){
        delete [] this->data;
        this->data = nullptr;
        this->size=0;
    }
    int& аt(size_t x){
        if(x>=0 && x<=this->size){
            return this->data[x];
        }
    }
    bool empty(){
        return this->size==0;
    }
    size_t size() const{
        return this->size;
    }
    void pushBack(int x){
        resize(1);
    }
    void resize(size_t N){
        if(empty()){
            if(N>0){
                capacity += N;
            }
        }
    }
    
};
int main (){
    return 0;
}