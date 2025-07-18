#include <iostream>
#include <string>
using namespace std;

struct Task {
    int id, priority;
    string desc;
    Task* next;
    Task(int i, int p, string d) : id(i), priority(p), desc(d), next(nullptr) {}
};

class TaskManager {
    Task* head;
public:
    TaskManager() : head(nullptr) {}
    
    void addTask(int id, int priority, string desc) {
        Task* newTask = new Task(id, priority, desc);
        if(!head || priority < head->priority) {
            newTask->next = head;
            head = newTask;
            return;
        }
        Task* temp = head;
        while(temp->next && temp->next->priority <= priority)
            temp = temp->next;
        newTask->next = temp->next;
        temp->next = newTask;
    }
    
    void display() {
        Task* temp = head;
        while(temp) {
            cout << "ID: " << temp->id << " | Priority: " << temp->priority 
                 << " | Task: " << temp->desc << endl;
            temp = temp->next;
        }
    }
};

int main() {
    TaskManager tm;
    tm.addTask(1, 2, "Fix bugs");
    tm.addTask(2, 1, "Urgent server fix");
    tm.addTask(3, 3, "Code review");
    tm.display();
    return 0;
}
