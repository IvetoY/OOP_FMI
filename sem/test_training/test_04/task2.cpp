#include <iostream>
#include <climits>  // за INT_MIN
#include <cmath>
class Statistics{
    private:
    void resize() {
        int* new_arr = new int[size + 1];
        for (size_t i = 0; i < size; i++) {
            new_arr[i] = n[i];
        }
        delete[] n;
        n = new_arr;
    }
    size_t size;
    int* n;
    public:
    
    void add(int number){
        resize();
        n[size] = number;
        size++;
        
    }
    size_t num(){
        return this->size;
    }
    int sum() const{
        
        int s = 0;
        for(size_t i = 0; i < size; i++) {
            s += (n[i]);
        }
        return s;
    }
    double prod(){
        if(size==0)return 0;
        double p=1;
        for(size_t i=0;i<this->size;i++){
            p=p*n[i];
        }
        return p;
    }
    int max(){
        int max = INT_MIN;
        if(size==0) return INT_MIN;
        for(size_t i=0;i<this->size;i++){
            if(this->n[i]>max){
                max=this->n[i];
            }
        }
        return max;
    }
    double average(){
        return (double)sum()/this->size;
    }
    public:
    Statistics(){
        this->size = 0;
        this->n = nullptr;
    }
    Statistics(int* numbers, size_t size){
        this->size = size;
        this->n = new int [size];
        for(size_t i=0;i<size;i++){
            this->n[i]=numbers[i];
        }
    }
    ~Statistics(){
        delete []this->n;
    }
    Statistics (const Statistics& other){
        this->size = other.size;
        this->n = new int [other.size];
        for(size_t i=0;i<other.size;i++){
            this->n[i]=other.n[i];
        }
    }
    Statistics& operator=(const Statistics& other){
        if(this!=&other){
            delete []this->n;
            this->size = other.size;
            this->n = new int [other.size];
        for(size_t i=0;i<other.size;i++){
            this->n[i]=other.n[i];
        }
        }
        return * this;
    }
    Statistics& operator+=(const Statistics& other){
        for (std::size_t i = 0; i < other.size; ++i)
            this->add(other.n[i]);
        
        return *this;
    }
    Statistics operator+(const Statistics& other){
        Statistics result = *this;
        result+=other;
        return result;
        
    }
    
};
int main (){
    
    int a[4]{5,6,10,-5};
    
    Statistics s;
    s.add(5);
    s.add(6);
    s.add(10);
    s.add(-5);
    std::cout<<"average: "<<s.average()<<std::endl;
    std::cout<<"max: "<<s.max()<<std::endl;
    std::cout<<"size: "<<s.num()<<std::endl;
    std::cout<<"prod: "<<s.prod()<<std::endl;
    std::cout<<"sum: "<<s.sum()<<std::endl;
    return 0;
}