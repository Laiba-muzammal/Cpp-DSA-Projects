#include <iostream>
#include <string>
using namespace std;

// Stack Node Structure
struct Node {
    char data;
    Node* next;
};

// Stack Operations
void push(Node*& top, char value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    char value = top->data;
    Node* temp = top;
    top = top->next;
    delete temp;
    return value;
}

char peek(Node* top) {
    if (top == nullptr) return '\0';
    return top->data;
}

// Helper Functions
string reverseString(string str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        if (str[i] == '(') reversed += ')';
        else if (str[i] == ')') reversed += '(';
        else reversed += str[i];
    }
    return reversed;
}

bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || 
           (c >= 'A' && c <= 'Z') || 
           (c >= '0' && c <= '9');
}

int precedence(char op) {
    if (op == '^') return 4;
    if (op == '*' || op == '/') return 3;
    if (op == '+' || op == '-') return 2;
    return 1; // For parentheses
}

// Infix to Postfix Conversion
string infixToPostfix(string infix) {
    Node* stack = nullptr;
    string postfix;
    
    for (char c : infix) {
        if (isOperand(c)) {
            postfix += c;
        }
        else if (c == '(') {
            push(stack, c);
        }
        else if (c == ')') {
            while (peek(stack) != '(') {
                postfix += pop(stack);
            }
            pop(stack); // Remove '('
        }
        else { // Operator
            while (stack != nullptr && precedence(c) <= precedence(peek(stack))) {
                postfix += pop(stack);
            }
            push(stack, c);
        }
    }
    
    // Pop remaining operators
    while (stack != nullptr) {
        postfix += pop(stack);
    }
    
    return postfix;
}

// Main Conversion Function
string infixToPrefix(string infix) {
    // Step 1: Reverse the infix expression
    string reversed = reverseString(infix);
    
    // Step 2: Convert to postfix
    string postfix = infixToPostfix(reversed);
    
    // Step 3: Reverse the postfix to get prefix
    string prefix = reverseString(postfix);
    
    return prefix;
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    
    string prefix = infixToPrefix(infix);
    cout << "Prefix expression: " << prefix << endl;
    
    return 0;
}
