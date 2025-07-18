#include <iostream>
#include <string>
using namespace std;

struct Node {
    int ticketNumber;
    string movieName;
    string customerName;
    Node* next;
};

int main() {
    Node* head = NULL;
    int choice, ticketNumber;
    string movieName, customerName;
5
    do {
        cout << "\n--- Movie Ticket Reservation System ---\n";
        cout << "1. Reserve Ticket\n";
        cout << "2. Display Reservations\n";
        cout << "3. Cancel Reservation\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter Ticket Number: ";
                cin >> ticketNumber;
                cout << "Enter Movie Name: ";
                cin >> movieName;
                cout << "Enter Customer Name: ";
                cin >> customerName;

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
                break;
            }
            case 2: {
                if (head == NULL) {
                    cout << "No reservations found.\n";
                } else {
                    Node* temp = head;
                    cout << "\n--- Reservations List ---\n";
                    while (temp !=NULL) {
                        cout << "Ticket Number: " << temp->ticketNumber << "\n";
                        cout << "Movie Name: " << temp->movieName << "\n";
                        cout << "Customer Name: " << temp->customerName << "\n\n";
                        temp = temp->next;
                    }
                }
                break;
            }
            case 3: {
                cout << "Enter Ticket Number to Cancel: ";
                cin >> ticketNumber;

                if (head == NULL) {
                    cout << "No reservations to cancel.\n";
                } else if (head->ticketNumber == ticketNumber) {
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                    cout << "Reservation cancelled successfully!\n";
                } else {
                    Node* temp = head;
                    Node* prev = NULL;

                    while (temp != NULL && temp->ticketNumber != ticketNumber) {
                        prev = temp;
                        temp = temp->next;
                    }
                    
                    if (temp == NULL) {
                        cout << "Reservation not found.\n";
                    } else {
                        prev->next = temp->next;
                        delete temp;
                        cout << "Reservation cancelled successfully!\n";
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting system...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
