#include <iostream>
#include <cstring>
class Student {
    private:
    unsigned int grade;
    char* name;
    public:
    Student(){
        this->grade = 2;
        name = new char[1];
        name[0]='\0';
    }
    Student(char* n, unsigned int g){
        this->name = new char [strlen(n)+1];
        strcpy(this->name, n);
        this->grade = g;
    }
    Student(const Student& other){
        this->grade = other.grade;
        this->name = new char [strlen(other.name)+1];
        strcpy(this->name, other.name);
    }
    Student& operator=(const Student& other){
        if(this!=&other){
            delete [] this->name;
            this->name = new char [strlen(other.name)+1];
            strcpy(this->name, other.name);
            this->grade = other.grade;
        }
        return *this;
    }
    ~Student(){
        delete []this->name;
    }
    int getGrade(){
        return this->grade;
    }
    char* getName(){
        return this->name;
    }
};
class Classroom{
    private:
    Student* students;
    size_t size;
    size_t capacity;
    public:
    Classroom(){
        this->students = nullptr;
        this->size = 0;
        this->capacity = 0;
    }
    
    ~Classroom(){
        delete []this->students;
    }
    void resize(){
        if (capacity != 0){
            capacity = capacity * 2;
        }
        else{
            capacity = 1;
        }
        Student* newStudents = new Student [capacity];
        for(size_t i=0;i<size;i++){
            newStudents[i] = students[i];
        }
        delete [] this->students;
        this->students = newStudents;

    }
    void addStudent(Student s){
        if(size>=capacity){
            resize();
        }
        this->students[size++]=s;
    }
    double averageGrade(){
        if(this->size == 0){
            return 0;
        }
        else {
            double sum = 0 ;
            for(size_t i=0;i<this->size;i++){
                sum +=students[i].getGrade();
            }
            return sum/size;
        }
    }
     void removeStudent(const char* name) {
        for (size_t i = 0; i < size; i++) {
            if (strcmp(students[i].getName(), name) == 0) {
                for (size_t j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                break;
            }
        }
    }
    void print() const {
        for (size_t i = 0; i < size; i++) {
            std::cout << "Name: " << students[i].getName() 
                      << ", Grade: " << students[i].getGrade() << std::endl;
        }
    }
};
int main (){
    Classroom c1;
    char name1[256];
    char name2[256];
    char name3[256];
    std::cout<<"name1: ";
    std::cin.getline(name1,255);
    std::cout<<std::endl<<"name2: ";
    std::cin.getline(name2,255);
    std::cout<<std::endl<<"name3: ";
    std::cin.getline(name3,255);

    Student s1(name1,5);
    Student s2(name2,5);
    Student s3(name3,3);
    c1.addStudent(s1);
    c1.addStudent(s2);
    c1.addStudent(s3);
    std::cout << "Classroom 1:" << std::endl;
    c1.print();
    std::cout << "Average grade: " << c1.averageGrade() << std::endl;
    c1.removeStudent(name1);
    std::cout << "\nAfter removing "<<name1<<" :" << std::endl;
    c1.print();


    return 0;
}