#include <iostream>
#include <cstring>
struct Date{
    unsigned int year;
    unsigned int month;
    unsigned int day;
};
class Task{
    private:
    char* description;
    Date deadline;
    public:
    Task(){
        description = new char [1];
        description[0] = '\0';
        deadline = {0,0,0};
    }
    Task(char* desc, Date d){
        this->description = new char [strlen(desc)+1];
        strcpy(this->description, desc);
        this->deadline = d;
    }
    void copy(const Task& other){
        this->description = new char [strlen(other.description)+1];
        strcpy(this->description, other.description);
        this->deadline = other.deadline;
    }
    Task (const Task& other){
        copy(other);
    }
    Task& operator=(const Task& other){
        if(this!=&other){
            delete []this->description;
            copy(other);
        }
        return *this;
    }
    ~Task(){
        delete []this->description;
    }
    friend std::ostream& operator<<(std::ostream& out, const Task& task) {
    out << "Task: " << task.description << " (Deadline: " 
        << task.deadline.year << "-" << task.deadline.month << "-" << task.deadline.day << ")";
    return out;
}
};
class List{
    private:
    Task* tasks;
    size_t size;
    size_t capacity;
    public:
    List(){
        this->size = 0;
        this->capacity = 16;
        this->tasks = new Task [this->capacity];
    }
    List(const List& other){
        copy(other);
    }
    List& operator=(const List& other){
        if(this!=&other){
            delete []this->tasks;
            copy(other);
        }
        return * this;
    }
    ~List(){
        delete []this->tasks;
    }
    void addTask(const Task& t){
        if (this->size == this->capacity){
            resize();
        }
        this->tasks[this->size] = t;
        ++this->size;
    }
    List& operator+=(const List& other){
        for(size_t i=0;i<other.size;i++){
            addTask(other.tasks[i]);
        }
        return *this;
    }
    List operator+(const List& other) const{
        List newList = *this;
        newList+=other;
        return newList;
    }
    bool operator<(const List& other)const{
        return this->size<other.size;
    }
    bool operator==(const List& other)const{
       return !(*this < other) && !(other < *this); 
    }
    bool removeById(const size_t idx)
    {
        if (idx >= this->size)
            return false;
        
        for (size_t i = idx + 1; i < this->size; ++i)
            this->tasks[i - 1] = this->tasks[i];
        --this->size;

        return true;
    }
    
    
    friend std::ostream& operator<<(std::ostream& out, const List& toDoList) {
        out << "This To-Do List contains " << toDoList.size << " notes and here they are:\n";
        for (std::size_t i = 0; i < toDoList.size; ++i) {
            out << i << ". " << toDoList.tasks[i] << '\n';  // Added period after index
        }
        return out;
    }
    private:
    void resize(){
        this->capacity *=2;
        Task* newTasks = new Task [this->capacity];
        for(size_t i=0;i<size;i++){
            newTasks[i]=this->tasks[i];
        }
        delete []this->tasks;
        this->tasks = newTasks;
        
    }
    void copy(const List& other){
        this->capacity = other.capacity;
        this->size = other.size;
        this->tasks = new Task [this->capacity];
        for (size_t i = 0; i < this->size; ++i){
            this->tasks[i] = other.tasks[i];
        }
    }


};
int main (){
    List tdl;
    char t[256];
    std::cin.getline(t,255);
    Task n1(t, {2, 4, 2001});

    for (int i = 0; i < 32; ++i)
        tdl.addTask(n1);

    std::cout << tdl << "\n\n\n";

    tdl.removeById(30);

    std::cout << tdl;
    return 0;
}