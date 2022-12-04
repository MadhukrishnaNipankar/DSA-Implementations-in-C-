#include <iostream>

using namespace std;

class node
{

public:
    int value;

    node *next;

    node(int data)
    {
        value = data;
        next = NULL;
    }
};

void insertAtEnd(node *head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

node *insertAtBeginning(node *head, int data)
{
    node *newNode = new node(data);
    if (head == NULL)
    {
        head = newNode;
        exit(0);
    }
    newNode->next = head;
    head = newNode;
    return head;
}

void displayLinkedList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout << endl;
}

node *deleteNode(node *head, int data)
{
    //If LinkedList is Empty
    if(head == NULL){
        return head;
    }

    node *temp = head;

    //if the data is at head
    if (head->value == data)
    {   
        node* nodeToBeDeleted = head;
        head = head->next;
        delete nodeToBeDeleted;
        return head;
    }

    //traverse till n-1 th element 
    while (temp->next->value != data)
    {
        temp = temp->next;
    }

    node *nodeToBeDeleted = temp->next;
    temp->next = temp->next->next;
    delete nodeToBeDeleted;
}

int main()
{
    node *newNode = new node(1);
    node *head = newNode;
    insertAtEnd(head, 5);
    insertAtEnd(head, 10);
    head = insertAtBeginning(head, 70);
    displayLinkedList(head);
    head = deleteNode(head, 70);
    displayLinkedList(head);

    return 0;
}