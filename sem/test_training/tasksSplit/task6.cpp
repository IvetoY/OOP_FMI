#include <iostream>
#include <cstring>
class BankAccount{
    private:
    char* owner;
    unsigned balance;
    public:
    BankAccount(){
        this->owner = new char[1];
        owner[0] = '\0';
        this->balance = 0;
    }
    BankAccount(const char* o, const unsigned b){
        this->owner = new char[strlen(o)+1];
        strcpy(this->owner, o);
        this->balance = b;
    }
    void copy(const BankAccount& other){
        this->owner = new char [strlen(other.owner)+1];
        strcpy(this->owner, other.owner);
        this->balance = other.balance;
    }
    BankAccount(const BankAccount& other){
        copy(other);
    }
    BankAccount& operator=(const BankAccount& other){
        if(this!=&other){
            copy(other);
        }
        return *this;
    }
    ~BankAccount(){
        delete []this->owner;
    }
    void deposit(double amount){
        if(amount>0){
            this->balance = this->balance + amount;
        }
    }
    void withdraw(double amount){
        if(amount>0){
            this->balance = this->balance - amount;
        }
    }
    void print(){
        std::cout<<this->owner<<": "<<this->balance<<std::endl;
    }

    
    unsigned getBalance(){
        return this->balance;
    }
    bool hasHighBalance(BankAccount acc) {
    return acc.getBalance() > 10000;
}

};
int main (){
    char name [256];
    std::cout<<"name: "<<std::endl;
    std::cin.getline(name,255);
    BankAccount b(name,200);
    
    b.deposit(200);
    b.withdraw(100);
    b.print();
    
    return 0;
}