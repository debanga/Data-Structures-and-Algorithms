// Simple Linked List Implementation

#include <iostream>

struct Node
{
    /* data */
    int data;
    Node *next;

    Node (int x) {
        data = x;
        next = NULL;
    }
};

int main() {
    Node *head = new Node (10);
    head->next = new Node (20);
    head->next->next = new Node (30);
    
    Node *temp = head;
    while (temp->next != NULL) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << temp->data << " ";

    return 0;
}

