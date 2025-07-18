#include <iostream>
#include <string>
#include <cctype> // for isalnum()
using namespace std;

// Stack implementation using linked list
struct Node {
    char data;
    Node* next;
    Node(char d) : data(d), next(nullptr) {}
};

class Stack {
    Node* top;
public:
    Stack() : top(nullptr) {}
    
    void push(char x) {
        Node* newNode = new Node(x);
        newNode->next = top;
        top = newNode;
    }
    
    char pop() {
        if (isEmpty()) return '\0';
        Node* temp = top;
        char val = top->data;
        top = top->next;
        delete temp;
        return val;
    }
    
    char peek() {
        if (isEmpty()) return '\0';
        return top->data;
    }
    
    bool isEmpty() {
        return top == nullptr;
    }
};

// Function to check if character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// Main conversion function
string infixToPostfix(string infix) {
    Stack s;
    string postfix;
    
    for (char c : infix) {
        // If operand, add to output
        if (isalnum(c)) {
            postfix += c;
        }
        // If '(', push to stack
        else if (c == '(') {
            s.push(c);
        }
        // If ')', pop until '('
        else if (c == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            s.pop(); // Remove '(' from stack
        }
        // If operator
        else if (isOperator(c)) {
            while (!s.isEmpty() && precedence(c) <= precedence(s.peek())) {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    
    // Pop remaining operators
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    
    return postfix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    
    return 0;
}
