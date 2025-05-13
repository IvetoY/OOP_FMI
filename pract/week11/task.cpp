#include <iostream>
#include <vector>
template <typename T>
class Filter{
    virtual ~Filter() = default;
    virtual bool matches(const T& item) const;
    virtual std::string getFilterName() const;
    virtual std::string getFilterType() const;
    virtual void printDescription() const;
};
template <typename T>
class NumericFilter: public Filter<T>{
    public:
    std::string getFilterType() const override{
        return "Numeric";
    }

};
template <typename T>
class DivisibilityFilter: public NumericFilter<T>{
    T d;
    public:
    DivisibilityFilter(T _d) : d(_d) {}
    std::string getFilterName() const override{
        return "Divisibility Filter";
    }
    /*std::string getFilterType() const override{
        return "Numeric Filter";
    }*/
    bool matches(const T& item) const override{
        if(item%d==0){return true;}
        else {return false;}
    }
    void printDescription() const override{
        std::cout<<"Diviseble by "<<d<<std::endl;
    }
};
template <typename T>
class EvenFilter : public NumericFilter<T> {
public:
    bool matches(const T& item) const override { return item % 2 == 0; }
    std::string getFilterName() const override { return "Even numbers"; }
};
template <typename T>
class RangeFilter: public NumericFilter<T>{
    private:
    T left;
    T right;
    public:
    RangeFilter(int _l, int _r) : left(_l), right(_r) {}
    std::string getFilterName() const override {return "Range Filter";}
    bool matches(const T& item) const override{
        if(item<left && item>right){return false;}
        else {return true;}
    }
    void printDescription() const override{
        std::cout<<"this filter is a range filter: "<<left<<" ,"<<right<<std::endl; 
    }
};
template <typename T>
class StringFilter: public Filter<std::string>{
    bool matches(const T& item)const override{
        if((item>='a' && item<='z')||(item>='A' && item<='Z')){
            return true;
        }
        else {
            return false;
        }
    }
    std::string getFilterType() const override{
        return "String filter";
    }

};
template <typename T>
class UpperFilter: public StringFilter<T>{
    std::string getFilterName() const override{
        return "Upper Filter";
    }
    bool matches(const std::string& item) const override {
        for (char c : item) {
            if (c<='A' || c>='Z') return false;
        }
        return !item.empty();
    }
    void prinDescription() const override{
        std::cout<<"this is a string with upper case only"<<std::endl;
    }
};
template <typename T>
class LowerFilter: public StringFilter<T>{
    std::string getFilterName() const override{
        return "Lower Filter";
    }
    bool matches(const std::string& item) const override {
        for (char c : item) {
            if (c<='a' || c>='z') return false;
        }
        return !item.empty();
    }
    void prinDescription() const override{
        std::cout<<"this is a string with lower case only"<<std::endl;
    }
};
template <typename T>
class LettersFilter: public StringFilter<T>{
    std::string allowed;
    public:
    LettersFilter(std::string a) : allowed(a) {}
    std::string getFilterName() const override {
        return "Letters filter";
    }
   
        bool matches(const std::string& item) const override {
            for(char c: item){
                bool found = false;
                for(char a: allowed){
                    if(c==a){found = true; break;}
                }
                if(!found){return false;}
            }
            
            return true;
        }

};
template<typename T>
class LogicalFilters: public Filter<T>{
    protected:
    std::vector<Filter<T>*> filters;
    public:
    void addFilter(const Filter<T>& f){
        filters.push_back(&f);
    }
    std::string getFilterType()const override{
        return "logical filter";
    }
    virtual ~LogicalFilters() = default;

};
int main() {
    return 0;
}