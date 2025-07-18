#include <iostream>
#define MAX 100
using namespace std;

class Stack {
    int top;
    int arr[MAX];
public:
    Stack() : top(-1) {}
    
    bool push(int x) {
        if(top >= MAX-1) return false;
        arr[++top] = x;
        return true;
    }
    
    int pop() {
        if(top < 0) return -1;
        return arr[top--];
    }
    
    int peek() {
        if(top < 0) return -1;
        return arr[top];
    }
    
    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    cout << s.pop() << " popped\n";
    cout << "Top: " << s.peek() << endl;
    return 0;
}
