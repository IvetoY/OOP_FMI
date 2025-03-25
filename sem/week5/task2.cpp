#include <iostream>
#include <cstring>
class Book{
    private:
    char* title;
    char* author;
    public:
    Book() {
        this->title = nullptr; 
        this->author = nullptr; 
        
    }
    
    Book(const char* title, const char* author){
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->author = new char [strlen(author) + 1];
        strcpy(this->author,author);
        std::cout<<"cc"<<std::endl;
    }
    Book(const Book& other) {
        this->title = new char[strlen(other.title) + 1];
        strcpy(this->title, other.title);
        this->author = new char[strlen(other.author) + 1];
        strcpy(this->author, other.author);
        std::cout << "cc" << std::endl;
    }
    
Book& operator=(const Book& other) {
        if (this != &other) { // Проверка за самоприсвояване
            delete[] this->title; // Освобождаваме старата памет
            delete[] this->author;

            this->title = new char[strlen(other.title) + 1];
            strcpy(this->title, other.title);
            this->author = new char[strlen(other.author) + 1];
            strcpy(this->author, other.author);
        }
        return *this;
    }
    ~Book(){
        delete []this->title;
        delete []this->author;
    }
    const char* getTitle () const{
        return this->title;
    }
    const char* getAuthor() const {
        return this->author;
    }
    void printBookInfo(){
        std::cout<<"title: "<<this->title<<std::endl;
        std::cout<<"author: "<<this->author<<std::endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os <<"Title:"<< book.getTitle()<<" "<<"Author:"<<" "<<book.getAuthor();
        return os;
    }
};
class Library{
    private:
    Book* books;
    int size;
    public:
    Library(){
        this->books = nullptr; 
        this->size = 0;   
    }
    Library(const Library& other){
        this->size = other.size;
        this->books = new Book [this->size];
        for(int i=0;i<this->size;i++){
            this->books[i]=other.books[i];
        }
    }
    ~Library(){
        delete []this->books;
    }
    void resize(int newSize){
        Book* newBooks = new Book[newSize];
        //int copySize = (newSize < this->size) ? newSize : this->size;
        for (int i = 0; i < this->size; i++) {
            newBooks[i] = this->books[i];
        }
        delete[] this->books;
        this->books = newBooks;
        this->size = newSize;
    }
    void addBook(const Book& book){
        resize(this->size + 1);
        this->books[this->size - 1] = book;
    }
    
    void printAllBooks(){
         if (this->size == 0) {
            std::cout << "Library is empty.\n";
            return;
        }
        std::cout << "Books in library:\n";
        for (int i = 0; i < this->size; i++) {
            std::cout <<  "("<<i + 1 << ")"<<". " << this->books[i] << std::endl; 
        }
    }
};
int main (){
     Library lib;
    lib.addBook(Book("1984", "George Orwell"));
    lib.addBook(Book("Brave New World", "Aldous Huxley"));
    lib.addBook(Book("Fahrenheit 451", "Ray Bradbury"));

    lib.printAllBooks();  
    return 0;
}