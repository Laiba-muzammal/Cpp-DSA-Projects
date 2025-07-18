#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ticketNumber;
    string movieName;
    string customerName;
    Node* next;
};

void reserveTicket(Node*& head, int ticketNumber, string movieName, string customerName);
void displayReservations(Node* head);
void cancelReservation(Node*& head, int ticketNumber);

int main() {
    Node* head = NULL; 
    int choice, ticketNumber;
    string movieName, customerName;

    do {
        cout << "\n--- Movie Ticket Reservation System ---\n";
        cout << "1. Reserve Ticket\n";
        cout << "2. Display Reservations\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Ticket Number: ";
                cin >> ticketNumber;
                cin.ignore();
                cout << "Enter Movie Name: ";
                getline(cin, movieName);
                cout << "Enter Customer Name: ";
                getline(cin, customerName);
                reserveTicket(head, ticketNumber, movieName, customerName);
                break;
            case 2:
                displayReservations(head);
                break;
            case 3:
                cout << "Enter Ticket Number to Cancel: ";
                cin >> ticketNumber;
                cancelReservation(head, ticketNumber);
                break;
            case 4:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

void reserveTicket(Node*& head, int ticketNumber, string movieName, string customerName) {
    Node* newNode = new Node();
    newNode->ticketNumber = ticketNumber;
    newNode->movieName = movieName;
    newNode->customerName = customerName;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    cout << "Ticket reserved successfully!\n";
}

void displayReservations(Node* head) {
    if (head == NULL) {
        cout << "No reservations found.\n";
        return;
    }

    Node* temp = head;
    cout << "\n--- Reservations List ---\n";
    while (temp != NULL) {
        cout << "Ticket Number: " << temp->ticketNumber << "\n";
        cout << "Movie Name: " << temp->movieName << "\n";
        cout << "Customer Name: " << temp->customerName << "\n\n";
        temp = temp->next;
    }
}

void cancelReservation(Node*& head, int ticketNumber) {
    if (head == NULL) {
        cout << "No reservations to cancel.\n";
        return;
    }

    if (head->ticketNumber == ticketNumber) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Reservation cancelled successfully!\n";
        return;
    }

    Node* temp = head;
    Node* prev =NULL;
    while (temp != NULL && temp->ticketNumber != ticketNumber) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Reservation not found.\n";
        return;
    }

    prev->next = temp->next;
    delete temp;
    cout << "Reservation cancelled successfully!\n";
}
