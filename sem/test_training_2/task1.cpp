#include <iostream>
#include <vector>
#include <memory>
class MathExpression{
    
    public:
    virtual ~MathExpression() = default;
    virtual double value() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual std::unique_ptr<MathExpression> clone() const =0;
    friend std::ostream& operator<<(std::ostream& os, const MathExpression& expr) {
        expr.print(os);
        return os;
    }
};
class Constant: public MathExpression{
    private:
    double val;
    public:
    explicit Constant(double v) : val(v) {}
    Constant(const Constant& other) : val(other.val) {}
    Constant& operator=(const Constant& other) {
        if (this != &other) {
            val = other.val;
        }
        return *this;
    }
    std::unique_ptr<MathExpression> clone() const override {
        return std::make_unique<Constant>(*this);
    }
    double value() const override{return this->val;}
    void print(std::ostream& os) const override {
        os << val;
    }
    
};
class Min: public MathExpression{
    private:
    std::shared_ptr<MathExpression> exp1;  // Променено от референция към shared_ptr
    std::shared_ptr<MathExpression> exp2;
    public:
    
    Min(std::shared_ptr<MathExpression> e1, std::shared_ptr<MathExpression> e2) 
        : exp1(e1), exp2(e2) {}
        Min(const Min& other) 
        : exp1(other.exp1->clone()), exp2(other.exp2->clone()) {}
    Min& operator=(const Min& other) {
        if (this != &other) {
            exp1 = other.exp1->clone();
            exp2 = other.exp2->clone();
        }
        return *this;
    }
    std::unique_ptr<MathExpression> clone() const override {
        return std::make_unique<Min>(exp1->clone(), exp2->clone());
    }
    double value() const override {
        double v1 = exp1->value();
        double v2 = exp2->value();
        return (v1 < v2) ? v1 : v2;
    }
    void print(std::ostream& os) const override {
        os << "min(" << *exp1 << ", " << *exp2 << ")";
    }
};
class Max: public MathExpression{
    private:
    std::shared_ptr<MathExpression> exp1;
    std::shared_ptr<MathExpression> exp2;

    public:
    Max(std::shared_ptr<MathExpression> e1, std::shared_ptr<MathExpression> e2) : exp1(e1),exp2(e2){}
    Max(const Max& other) : exp1(other.exp2->clone()), exp2(other.exp2->clone()) {}
    Max& operator=(const Max& other){
        if(this!=&other){
            exp1 = other.exp1->clone();
            exp2 = other.exp2->clone();
        }
        return *this;
    }
    std::unique_ptr<MathExpression> clone() const override{
        return std::make_unique<Max>(exp1->clone(),exp2->clone());
    }
    double value() const override{
        double v1 = exp1->value();
        double v2 = exp2->value();
        if(v1>v2){return v1;}
        else {return v2;}
    }
    void print(std::ostream& os) const override {
        os << "max(" << *exp1 << ", " << *exp2 << ")";
    }
};
class Sum: public MathExpression{
    private:
    std::vector<std::shared_ptr<MathExpression>> expressions;
    public:
    Sum() = default;
    Sum(const Sum& other) {
        for (const auto& expr : other.expressions) {
            expressions.push_back(expr->clone());
        }
    }
    Sum& operator=(const Sum& other) {
        if (this != &other) {
            expressions.clear();
            for (const auto& expr : other.expressions) {
                expressions.push_back(expr->clone());
            }
        }
        return *this;
    }
    
    
    std::unique_ptr<MathExpression> clone() const override {
        auto newSum = std::make_unique<Sum>();
        for (const auto& expr : expressions) {
            newSum->addExpression(expr->clone());
        }
        return newSum;
    }
    void  addExpression(std::shared_ptr<MathExpression> e){
        expressions.push_back(e);
    }
    double value() const override {
        double sum = 0.0;
        for (const auto& expr : expressions) {
            sum += expr->value();
        }
        return sum;
    }
    void print(std::ostream& os) const override {
        if (expressions.empty()) {
            os << "0";
            return;
        }

        os << "(";
        for (size_t i = 0; i < expressions.size(); ++i) {
            if (i != 0) os << " + ";
            os << *expressions[i];
        }
        os << ")";
    }
    auto begin() const { return expressions.begin(); }
    auto end() const { return expressions.end(); }
    auto cbegin() const { return expressions.cbegin(); }
    auto cend() const { return expressions.cend(); }

};
int main() {
    auto five = std::make_shared<Constant>(5.0);
    auto pi = std::make_shared<Constant>(3.14159);
    auto m1 = std::make_shared<Min>(five, pi);
    
    // Тест за копиране
    auto m2 = std::make_shared<Min>(*m1);
    auto sum1 = std::make_shared<Sum>();
    sum1->addExpression(five);
    sum1->addExpression(pi);
    sum1->addExpression(m1);
    
    auto sum2 = *sum1; // Тест за оператор=
    
    std::cout << "Five: " << *five << " (value: " << five->value() << ")\n";
    std::cout << "Pi: " << *pi << " (value: " << pi->value() << ")\n";
    std::cout << "min1: " << *m1 << " = " << m1->value() << "\n";
    std::cout << "min2 (copy): " << *m2 << " = " << m2->value() << "\n";
    std::cout << "sum1: " << *sum1 << " = " << sum1->value() << "\n";
    std::cout << "sum2 (copy): " << sum2 << " = " << sum2.value() << "\n";
    
    return 0;
}