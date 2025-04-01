#include <iostream>
template <typename Type>
class BoundSet{
    private: 
    Type* set;
    size_t size;
    size_t capacity;
    public:
    void copy(const BoundSet& other){
        delete []this->set;
        this->size = other.size;
        this->capacity = other.capacity;
        this->set = new Type[this->capacity];
        for(size_t i=0;i<other.size;i++){
            this->set[i] = other.set[i];
        }
        
    }
    BoundSet(){
        this->size = 0;
        this->capacity = 10;
        this->set = new Type [this->capacity];
    }
    BoundSet(Type* s,size_t _s, size_t c){
        this->size = _s;
        this->capacity = c;
        this->set = new Type[this->capacity];
        for(size_t i=0;i<_s;i++){
            this->set[i] = s[i];
        }
        
    }
    BoundSet(const BoundSet& other){
        this->set = nullptr;
        copy(other);
    }
    BoundSet& operator=(const BoundSet& other){
        if(this!=&other){
            copy(other);
        }
        return * this;
    }
    ~BoundSet(){
        delete []this->set;
    }
    BoundSet operator+(const BoundSet& other) const {
        BoundSet result;
        result.capacity = this->capacity + other.capacity;
        delete []result.set;
            result.set = new Type[result.capacity];
        for(size_t i = 0; i < this->size; i++) {
            result.set[i] = this->set[i];
        }
        for(size_t i = 0; i < other.size; i++) {
            if(!result.member(other.set[i])) {
                if(result.size < result.capacity) {
                    result.set[result.size++] = other.set[i];
                }
            }
        }
        return result;
        }
        
    
    BoundSet& operator+=(const BoundSet& other){
        this->size =this->size + other.size;
        for(size_t i=0;i<other.size;i++){
            this->add(other.set[i]);
        }
        return *this;
    }
    void add(const Type t){
        if(!this->member(t) && this->size < this->capacity) {   
            this->set[this->size++] = t;
        }
    }
    void remove(const Type t){
        int br=0;
        for(size_t i=0;i<this->size;i++){
            if(this->set[i]!=t){
                this->set[br]=this->set[i];
                br++;
            }
        }
            
            this->size=br;
    }
    bool member(const Type t){
        for(size_t i=0;i<this->size;i++){
            if(this->set[i]==t){
                return true;
            }
        }
        return false;
    }
    size_t getSize() const { return size; }
    size_t getCapacity() const { return capacity; }
    Type* getSet() const {return this->set;}
    
    friend std::ostream& operator<<(std::ostream& out, const BoundSet& b){
        out << "Size: "<<b.getSize()<<std::endl;
        out << "Numbers: "<<std::endl;
        for(size_t i=0;i<b.size;i++){
            out<<b.set[i]<<" ";
        }
        
        return out;
    }
};

int main (){
    int a[] = {1,2,3};
    int b[] = {5,6,7,1,8,9};
    BoundSet<int> b1(a,3,20);
    BoundSet<int> b2(b,6,20);
    b1.add(55);
    b1+=b2;
    std::cout << "Size after union: " << b1.getSize() << std::endl;
    std::cout<<b1<<std::endl;
    std::cout<<b2<<std::endl;

    return 0;
}