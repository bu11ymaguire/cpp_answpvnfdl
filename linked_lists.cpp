#include <cstdlib>
#include <cstddef>
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
const char ADD = 'A';
const char DELETE = 'D';
const char FIND = 'F';

class Student {
//TODO
private:
    int id;
    string name;
    Student* next;
public:
    Student(int s_id, string s_name) : id(s_id), name(s_name), next(nullptr){}
};

class Course {
//TODO
public:
    Student* head;
    Course() {
        head = nullptr;
    }
    ~Course() {
        Student* address = head;
        while (address != nullptr) 
        {
            Student* temp = address;
            address=address->next;
            delete temp;
        }
    }

    bool isEmpty() {
        return (head == nullptr);
    }

    bool addStudent(int id, string name);
    bool deleteStudent(int id);
    Student* find(int id);
    void write(ofstream& outFile);
};

bool Course::addStudent(int id, string name) {
    //TODO
}

bool Course::deleteStudent(int id) 
{
  //TODO  
  Student* address = head;
    if (isEmpty()) 
    {
        return false;
    }
    if (head->id == id) 
    {
        Student* tmp = head;
        head = head->next;
        tmp->next = nullptr;
        delete tmp;
        return true;
    }
    Student* previous = nullptr;
    while (address != nullptr) 
    {
        if (address->id == id) 
        {
            if (address->next == nullptr) 
            {
                previous->next = nullptr;
                delete address;
            }
            else 
            {
                previous->next = address->next;
                address->next = nullptr;
                delete address;
            }
            return true;
        }
        previous = address;
        address = address->next;
    }
    return false;
}

Student* Course::find(int id) {
    //TODO
}

void Course::write(ofstream& outFile) {
    //TODO
}
