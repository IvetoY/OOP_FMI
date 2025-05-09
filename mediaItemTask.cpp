#include <iostream>

enum MediaType{book, movie, album};
class MediaItem{
    private:
    std::string title;
    int year;
    double rating;
    public:
    virtual void display() const = 0;      
    virtual void saveToFile(std::ofstream& out) const = 0;  
    virtual MediaType getType() const = 0;
};