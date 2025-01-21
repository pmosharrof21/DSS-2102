#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};
void insertEnd(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = *head;

    if (*head != nullptr) {
        Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
    } else {
        newNode->next = newNode;
        *head = newNode;
    }
}
void printList(Node* head) {
    if (head != nullptr) {
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    insertEnd(&head, 15);
    insertEnd(&head, 30);
    insertEnd(&head, 45);
    insertEnd(&head, 60);
    cout << "Circular Linked List: ";
    printList(head);
    return 0;
}

