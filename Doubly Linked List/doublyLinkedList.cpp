#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

void displayLinkedList(node *head)
{
    node *temp = head;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void insertAtEnd(node *head, int value)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    node *newNode = new node(value);
    temp->next = newNode;
    newNode->prev = temp;
}

node *insertAtBeginning(node *head, int value)
{
    node *temp = head;
    node *newNode = new node(value);
    newNode->next = head;
    head->prev = newNode;
    head = head->prev;
    return head;
}

node *insertAtMid(node *head, int value, int pos)

{
    node *newNode = new node(value);
    if (pos == 1)
    {
        head = insertAtBeginning(head, value);
        return head;
    }
    node *temp = head;
    int count = 1;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = newNode;
    newNode->prev = temp->prev;
    newNode->next = temp;
    temp->prev = newNode;
    return head;
}

void deleteAtEnd(node *head)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    node *nodeToBeDeleted = temp;
    temp->prev->next = NULL;
    delete nodeToBeDeleted;
}

node *deleteAtBeginning(node *head)
{
    node *nodeToBeDeleted = head;
    head = head->next;
    head->prev = NULL;
    delete nodeToBeDeleted;
    return head;
}

void deleteAtMid(node *head, int pos)
{
    node *temp = head;
    int count = 1;

    while (count < pos)
    {
        temp = temp->next;
        count++;
    }

    node *elementToBeDeleted = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete elementToBeDeleted;
}

int main()
{
    node *firstNode = new node(5);
    node *head = firstNode;

    insertAtEnd(head, 10);
    insertAtEnd(head, 12);
    insertAtEnd(head, 13);
    displayLinkedList(head);
    head = insertAtBeginning(head, 6);
    head = insertAtBeginning(head, 4);
    head = insertAtBeginning(head, 454);
    displayLinkedList(head);

    head = insertAtMid(head, 70, 3);
    displayLinkedList(head);

    head = insertAtMid(head, 300, 5);
    displayLinkedList(head);

    deleteAtEnd(head);
    deleteAtEnd(head);
    displayLinkedList(head);

    head = deleteAtBeginning(head);
    head = deleteAtBeginning(head);
    displayLinkedList(head);

    deleteAtMid(head, 3);
    displayLinkedList(head);

    deleteAtMid(head, 3);
    displayLinkedList(head);

    return 0;
}