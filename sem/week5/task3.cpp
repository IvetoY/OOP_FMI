#include <iostream>
#include <cstring>
class BankAccount{
    private:
        char * accNumber;
        double balance;
        char* holder;
        
    public:
        BankAccount(){
            this->accNumber = nullptr;
            this->holder = nullptr;
            this->balance = 0.00;
        } 
        BankAccount(const char* accNumber, const char* holder, const double balance){
            this->accNumber = new char [strlen(accNumber)+1];
            strcpy(this->accNumber,accNumber);
            this->holder = new char [strlen(holder)+1];
            strcpy(this->holder, holder); 
            this->balance = balance;
        }
        BankAccount(const BankAccount& other){
            this->accNumber = new char [strlen(other.accNumber)+1];
            strcpy(this->accNumber,other.accNumber);
            this->holder = new char [strlen(other.holder)+1];
            strcpy(this->holder, other.holder);
            this->balance = other.balance;
        } 
        BankAccount& operator=(const BankAccount& other){
        if(this != &other) {
            delete []this->accNumber;
            delete []this->holder;
            
            this->accNumber = new char [strlen(other.accNumber)+1];
            strcpy(this->accNumber,other.accNumber);
            this->holder = new char [strlen(other.holder)+1];
            strcpy(this->holder, other.holder);
            this->balance = other.balance;
        }
        return * this;
        }
        ~BankAccount(){
            delete []accNumber;
            delete [] holder;
        }
        void deposit(double amount){
            if(amount>0){
                this->balance = this->balance + amount;
            }
            else {
                std::cout<<"error, adding negative amount"<<std::endl;
            }
            
        }
        void withdraw(double amount){
            if(amount>0 && amount<=this->balance){
                this->balance = this->balance - amount;
            }
            else {
                std::cout<<"you are broke xoxo"<<std::endl;
            }
        }

    void print(){
        std::cout<<"bank account number: "<<this->accNumber<<std::endl;
        std::cout<<"holder: "<<this->holder<<std::endl;
        std::cout<<"balance: "<<this->balance<<std::endl;
    }
};
int main (){
    BankAccount acc1("BG123456", "John Doe", 500.00);
    acc1.deposit(200);
    acc1.withdraw(100);
    BankAccount acc2 = acc1;
    acc2.print();
    return 0;
}