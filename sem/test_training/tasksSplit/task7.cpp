#include <iostream>
#include <cstring>
class Movie{
    private:
    char* title;
    unsigned int duration;
    public:
    Movie(){
        this->title = new char [1];
        this->title[0]='\0';
        this->duration = 0;
    }
    Movie(const char* t, const unsigned int d){
        this->duration = d;
        this->title = new char [strlen(t)+1];
        strcpy(this->title,t);
    }
    void copy(const Movie& other){
        this->duration = other.duration;
        this->title = new char[strlen(other.title)+1];
        strcpy(this->title, other.title);
    }
    Movie (const Movie& other){
        copy(other);
    }
    Movie& operator=(const Movie& other){
        if(this!=&other){
            copy(other);
        }
        return *this;
    }
    ~Movie(){
        delete [] this->title;
    }
    void print(){
        std::cout<<"Your film: "<<std::endl;
        std::cout<<"Title: "<<this->title<<std::endl;
        std::cout<<"Duration: "<<this->duration<<std::endl;
    }
    bool compareByDuration(Movie m){
        if(this->duration>m.duration){
            return true;
        }
        else {
            return false;
        }
    }
    const char* getTitle() const {
        return this->title;
    }
     unsigned int getDuration() const{
        return this->duration;
    }
    friend std::ostream& operator<<(std::ostream& os, const Movie& other);
     
    
};
std::ostream& operator<<(std::ostream& os, const Movie& other){
     
        os << "Film: "<<other.getTitle()<<std::endl<<"Duration: "<<other.getDuration()<<std::endl;
        return os;
    }

int main (){
    char title1 [256];
    char title2[256];
    std::cout<<"First title: "<<std::endl;
    std::cin.getline(title1,255);
    std::cout<<"SEcond title: "<<std::endl;
    std::cin.getline(title2,255);
    Movie m1(title1,100);
    Movie m2(title2,200);
    m1.print();
    m2.print();
    switch(m1.compareByDuration(m2)){
        case 0: std::cout<<"false"<<std::endl; break;
        case 1: std::cout<<"True"<<std::endl; break;
    }
    std::cout<<m1;
    //std::cout<<(bool)m1.compareByDuration(m2);
    return 0;
}