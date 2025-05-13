#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <cctype>

// Базов интерфейс за филтри
template <typename T>
class Filter {
public:
    virtual ~Filter() = default;
    virtual bool matches(const T& item) const = 0;
    virtual std::string getFilterName() const = 0;
    virtual std::string getFilterType() const = 0;
    virtual void printDescription() const {
        std::cout << getFilterType() << " filter: " << getFilterName();
    }
};

// Числови филтри
template <typename T>
class NumericFilter : public Filter<T> {
public:
    std::string getFilterType() const override { return "Numeric"; }
};

// Интервален филтър (без промени)
template <typename T>
class RangeFilter : public NumericFilter<T> {
    T low, high;
public:
    RangeFilter(T l, T h) : low(l), high(h) {}
    bool matches(const T& item) const override { return item >= low && item <= high; }
    std::string getFilterName() const override { 
        return "Range[" + std::to_string(low) + "," + std::to_string(high) + "]"; 
    }
};

// Филтър за четност (без промени)
template <typename T>
class EvenFilter : public NumericFilter<T> {
public:
    bool matches(const T& item) const override { return item % 2 == 0; }
    std::string getFilterName() const override { return "Even numbers"; }
};

// Филтър за делимост (без промени)
template <typename T>
class DivisibleFilter : public NumericFilter<T> {
    T divisor;
public:
    DivisibleFilter(T d) : divisor(d) {}
    bool matches(const T& item) const override { return item % divisor == 0; }
    std::string getFilterName() const override { 
        return "Divisible by " + std::to_string(divisor); 
    }
};

// Низови филтри
class StringFilter : public Filter<std::string> {
public:
    std::string getFilterType() const override { return "String"; }
};

// Upper филтър (променен начин на проверка за главни букви)
class UpperCaseFilter : public StringFilter {
public:
    bool matches(const std::string& item) const override {
        for (char c : item) {
            if (!isupper(c)) return false;
        }
        return !item.empty();
    }
    std::string getFilterName() const override { return "Uppercase only"; }
};

// Lower филтър (променен начин на проверка за малки букви)
class LowerCaseFilter : public StringFilter {
public:
    bool matches(const std::string& item) const override {
        for (char c : item) {
            if (!islower(c)) return false;
        }
        return !item.empty();
    }
    std::string getFilterName() const override { return "Lowercase only"; }
};

// Letters филтър (заменен std::string::npos с ръчна проверка)
class LettersFilter : public StringFilter {
    std::string allowed;
public:
    LettersFilter(const std::string& chars) : allowed(chars) {}
    bool matches(const std::string& item) const override {
        for (char c : item) {
            bool found = false;
            for (char a : allowed) {
                if (c == a) {
                    found = true;
                    break;
                }
            }
            if (!found) return false;
        }
        return true;
    }
    std::string getFilterName() const override { 
        return "Only letters from: " + allowed; 
    }
};

// Логически филтри (премахнати shared_ptr)
template <typename T>
class LogicalFilter : public Filter<T> {
protected:
    std::vector<Filter<T>*> filters; // Промяна: обикновени указатели
public:
    virtual ~LogicalFilter() = default;
    void addFilter(Filter<T>& filter) { filters.push_back(&filter); }
    std::string getFilterType() const override { return "Logical"; }
};

// AND филтър
template <typename T>
class AndFilter : public LogicalFilter<T> {
public:
    bool matches(const T& item) const override {
        for (const Filter<T>* f : this->filters) {
            if (!f->matches(item)) return false;
        }
        return !this->filters.empty();
    }
    std::string getFilterName() const override { return "AND filter"; }
};

// OR филтър
template <typename T>
class OrFilter : public LogicalFilter<T> {
public:
    bool matches(const T& item) const override {
        for (const Filter<T>* f : this->filters) {
            if (f->matches(item)) return true;
        }
        return false;
    }
    std::string getFilterName() const override { return "OR filter"; }
};

// Предикатен филтър (без промени)
template <typename T>
class PredicateFilter : public Filter<T> {
    std::function<bool(const T&)> predicate;
public:
    PredicateFilter(std::function<bool(const T&)> p) : predicate(p) {}
    bool matches(const T& item) const override { return predicate(item); }
    std::string getFilterName() const override { return "Custom predicate"; }
    std::string getFilterType() const override { return "Predicate"; }
};

// Blacklist/Whitelist филтри (премахнати shared_ptr)
template <typename T>
class ListFilter : public Filter<T> {
protected:
    std::vector<T> items;
public:
    ListFilter(const std::vector<T>& its) : items(its) {}
    std::string getFilterType() const override { return "List"; }
};

template <typename T>
class BlackListFilter : public ListFilter<T> {
public:
    using ListFilter<T>::ListFilter;
    bool matches(const T& item) const override {
        for (const T& i : this->items) {
            if (i == item) return false;
        }
        return true;
    }
    std::string getFilterName() const override { return "Blacklist filter"; }
};

template <typename T>
class WhiteListFilter : public ListFilter<T> {
public:
    using ListFilter<T>::ListFilter;
    bool matches(const T& item) const override {
        for (const T& i : this->items) {
            if (i == item) return true;
        }
        return false;
    }
    std::string getFilterName() const override { return "Whitelist filter"; }
};

// Колекция с филтри (премахнати shared_ptr)
template <typename T>
class FilteredCollection {
    std::vector<T> items;
    Filter<T>* filter = nullptr; // Промяна: обикновен указател
public:
    ~FilteredCollection() { delete filter; }
    
    void add(const T& item) { items.push_back(item); }
    void remove(const T& item) {
        items.erase(std::remove(items.begin(), items.end(), item), items.end());
    }
    size_t size() const { return items.size(); }
    
    void setFilter(Filter<T>* f) { 
        delete filter;
        filter = f; 
    }
    
    size_t matchCount() const {
        if (!filter) return items.size();
        size_t count = 0;
        for (const T& item : items) {
            if (filter->matches(item)) count++;
        }
        return count;
    }
    
    double matchPercent() const {
        if (items.empty()) return 0.0;
        return (static_cast<double>(matchCount()) / items.size()) * 100;
    }
    
    void readFromStream(std::istream& is, size_t count) {
        for (size_t i = 0; i < count; ++i) {
            T item;
            if (is >> item) {
                add(item);
            } else {
                break;
            }
        }
    }
    
    void writeToStream(std::ostream& os) const {
        for (const T& item : items) {
            if (!filter || filter->matches(item)) {
                os << item << " ";
            }
        }
        os << "\n";
    }
};

int main() {
    // Пример с числа
    FilteredCollection<int> numbers;
    numbers.add(5); numbers.add(10); numbers.add(15); numbers.add(20);
    
    EvenFilter<int> evenFilter;
    RangeFilter<int> rangeFilter(10, 20);
    
    numbers.setFilter(new EvenFilter<int>(evenFilter));
    std::cout << "Even numbers count: " << numbers.matchCount() << "\n";
    
    numbers.setFilter(new RangeFilter<int>(rangeFilter));
    std::cout << "Numbers in range 10-20: " << numbers.matchCount() << "\n";
    
    // Комбиниран филтър
    AndFilter<int> combinedFilter;
    combinedFilter.addFilter(evenFilter);
    combinedFilter.addFilter(rangeFilter);
    numbers.setFilter(new AndFilter<int>(combinedFilter));
    std::cout << "Even numbers in range 10-20: " << numbers.matchCount() << "\n";
    
    // Пример със стрингове
    FilteredCollection<std::string> words;
    words.add("HELLO"); words.add("world"); words.add("TEST"); words.add("filter");
    
    UpperCaseFilter upperFilter;
    words.setFilter(new UpperCaseFilter(upperFilter));
    std::cout << "Uppercase words: " << words.matchCount() << "\n";
    
    // Предикатен филтър
    auto lengthPredicate = [](const std::string& s) { return s.length() > 4; };
    PredicateFilter<std::string> lengthFilter(lengthPredicate);
    words.setFilter(new PredicateFilter<std::string>(lengthFilter));
    std::cout << "Words longer than 4 chars: " << words.matchCount() << "\n";
    
    return 0;
}