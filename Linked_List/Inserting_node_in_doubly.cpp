#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
};
void insertAtBeginning(Node** head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = (*head);
    newNode->prev = nullptr;
    if ((*head) != nullptr)
        (*head)->prev = newNode;
    (*head) = newNode;
}
void insertAtEnd(Node** head, int newData) {
    Node* newNode = new Node();
    Node* last = *head;
    newNode->data = newData;
    newNode->next = nullptr;
    if (*head == nullptr) {
        newNode->prev = nullptr;
        *head = newNode;
        return;
    }
    while (last->next != nullptr)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}
void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
int main() {
    Node* head = nullptr;
    insertAtEnd(&head, 6);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    insertAtEnd(&head, 4);
    cout << "Created Doubly Linked List: ";
    printList(head);
    return 0;
}
