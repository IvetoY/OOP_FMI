#include <iostream>
#include <initializer_list>
#include <algorithm>

class Iterator{
    private:
    int* ptr;
    public:
    Iterator(int* p) : ptr(p) {}
    int& operator*() {return *ptr;}
    Iterator& operator++(){++ptr; return *this;}
    Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }
    Iterator operator--(int) { Iterator tmp = *this; --ptr; return tmp; }
    Iterator& operator--(){--ptr; return *this;}
    bool operator!=(const Iterator& other){
        return ptr!=other.ptr;
    }
};
class CustomContainer{
    private:
    int* data;
    size_t size;
    public:
    CustomContainer(std::initializer_list<int> init) : size(init.size()) {
        data = new int[size];
        std::copy(init.begin(), init.end(), data);
    }
    ~CustomContainer(){
        delete []data;
    }
    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
};

int main (){
    CustomContainer container{10, 20, 30, 40};
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout<<std::endl;
    Iterator it = container.end();
    Iterator itBegin = container.begin();
    while (it != itBegin) {
        --it;  // Първо намаляме, после достъпваме
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}