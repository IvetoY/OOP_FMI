#include <iostream>
#include <cstring>
class Book{
    private:
        char* title;
        char* author;
    public:
    Book(){
        this->title = new char[1];
        this->title[0]='\0';
        this->author = new char[1];
        this->author[0]='\0';
    }
    Book(const char* t, const char* a){
        this->author = new char[strlen(a)+1];
        strcpy(this->author,a);
        this->title = new char [strlen(t)+1];
        strcpy(this->title, t);
   }
   Book(const Book& other){
        this->author = new char[strlen(other.author)+1];
        strcpy(this->author,other.author);
        this->title = new char [strlen(other.title)+1];
        strcpy(this->title, other.title);
   }
   Book& operator=(const Book& other){
    if(this!=&other){
        delete []this->author;
        delete []this->title;
        this->author = new char[strlen(other.author)+1];
        strcpy(this->author,other.author);
        this->title = new char [strlen(other.title)+1];
        strcpy(this->title, other.title);
    }
    return *this;
   }
   ~Book(){
    delete [] this->author;
    delete [] this->title;
   }
   char* getTitle(){
    return this->title;
   }
   char* getAuthor(){
    return this->author;
   }
    void print() const {
        std::cout << "Title: " << title << ", Author: " << author << std::endl;
    }

};
class Library{
    private:
        Book* books;
        size_t size;
    public:
        Library(Book* b, size_t size){
            this->size = size;
            this->books = new Book[size];
            for(size_t i=0;i<size;i++){
                this->books[i]= b[i];
            }
            
        }
        Library (const Library& other){
            this->size = other.size;
            this->books = new Book[other.size];
            for(size_t i=0;i<other.size;i++){
                this->books[i]=other.books[i];
            }
        }
        Library& operator=(const Library& other){
            if(this!=&other){
                delete [] this->books;
                for(size_t i=0;i<other.size;i++){
                this->books[i]=other.books[i];
            }
            }
            return * this;
        }
        ~Library(){
            delete [] this->books;
        }
         Library& operator+=(const Book& other) {
        Book* newBooks = new Book[size + 1];
        for (size_t i = 0; i < size; i++) {
            newBooks[i] = this->books[i];
        }
        newBooks[size] = other;
        delete[] this->books;
        this->books = newBooks;
        this->size++;
        return *this;
    }
        void print() const {
        std::cout << "Library contents (" << size << " books):" << std::endl;
        for (size_t i = 0; i < size; i++) {
            books[i].print();
        }
    }
    void findBookByAuthor(const char* a) {
        bool found = false;
        for (size_t i = 0; i < this->size; i++) {
            if (strcmp(this->books[i].getAuthor(), a) == 0) {
                std::cout << "Book #" << i + 1 << " by author " << a 
                          << ": " << this->books[i].getTitle() << std::endl;
                found = true;
            }
        }
        if (!found) {
            std::cout << "No books found by author " << a << std::endl;
        }
    }
};
int main (){
    char book1[256];
    char book2[256];
    char book3[256];
    char author2 [256];
    char author1 [256];
    char author3 [256];
    std::cout<<"title1: "<<std::endl;
    std::cin.getline(book1, 255);
    std::cout<<"title2: "<<std::endl;
    std::cin.getline(book2, 255);
    std::cout<<"title3: "<<std::endl;
    std::cin.getline(book3, 255);

    std::cout<<"author1: "<<std::endl;
    std::cin.getline(author1, 255);
    std::cout<<"author2: "<<std::endl;
    std::cin.getline(author2, 255);
    std::cout<<"author3: "<<std::endl;
    std::cin.getline(author3, 255);
    Book b1(book1, author1);
    Book b2(book2, author2);
    Book books[] = {b1, b2};
    Library lib(books, 2);
    lib.print();
    Book b3(book3, author3);
    lib += b3; 
    std::cout<<std::endl;
    lib.findBookByAuthor(author2);
    std::cout<<"Title3: "<<b3.getTitle()<<std::endl;
    return 0;
}