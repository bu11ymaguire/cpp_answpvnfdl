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

class Student 
{ 
public:
    int id;
    string name;
    Student* next;
    Student(int s_id, string s_name) : id(s_id), name(s_name), next(nullptr){}
};

class Course {
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
    Student* addward = new Student(id, name);
    Student* current = head;
    Student* previous = nullptr;
    if (current == nullptr) 
    {
        head = addward;
        return true;
    }
    while (current !=nullptr && current->id<id) 
    {
        previous = current;
        current = current->next;
    }
    if (current != nullptr && current->id == id)
    {
        delete addward;
        return false;
    }
    if (previous == nullptr) 
    {
        addward->next = head;
        head = addward;
    }
    else 
    {
        addward->next = current;
        previous->next = addward;
    }
    return true;
}

bool Course::deleteStudent(int id) 
{
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
    Student* address = head;
    if (isEmpty()) 
    {
        return nullptr;
    }
    while (address!= nullptr) 
    {
        if (address->id == id) 
        {
            return address;
        }
        address = address->next;
    }
    return nullptr;
}

void Course::write(ofstream& outFile) 
{
    Student* studant = head;
    while (studant != nullptr) 
    {
        outFile << studant->id << " " << studant->name << endl;
        studant = studant->next;
    }
}


//스켈레톤 코드
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Correct usage: [program] [input] [output]" << endl;
        exit(1);
    }
    Course course;
    ifstream inFile(argv[1]);
    ofstream outFile(argv[2]);
    string line;
    while (getline(inFile, line))
    {
        char op = line[0];
        istringstream iss(line.substr(1));
        int id;
        string name;
        Student* found = nullptr;
        cout << line << endl;
        switch (op)
        {
        case ADD:
            if (!(iss >> id >> name)) {
                cerr << "ADD: invalid input" << endl;
                exit(1);
            }
            if (course.addStudent(id, name))
                course.write(outFile);
            else
                outFile << "Addition failed" << endl;
            break;
        case DELETE:
            if (!(iss >> id)) {
                cerr << "DELETE: invalid input" << endl;
                exit(1);
            }
            if (course.deleteStudent(id))
                course.write(outFile);
            else
                outFile << "Deletion failed" << endl;
            break;
        case FIND:
            if (!(iss >> id)) {
                cerr << "FIND: invalid input" << endl;
                exit(1);
            }
            found = course.find(id);
            if (found == nullptr)
                outFile << "Search failed" << endl;
            else
                outFile << found->id << " " << found->name << endl;
            break;
        default:
            cerr << "Undefined operator" << endl;
            exit(1);
        }
    }
    outFile.close();
    inFile.close();
}
