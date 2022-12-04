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

node *insertAtBeginning(node *head, int data)
{
    node *newNode = new node(data);

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    newNode->next = head;
    head = newNode;

    return head;
}
void insertAtEnd(node *head, int data)
{
    node *newNode = new node(data);

    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;

    newNode->next = head;
}

node *insertAtMid(node *head, int data, int pos)
{
    if (pos == 1)
    {
        head = insertAtBeginning(head, data);
        return head;
    }
    node *newNode = new node(data);
    node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *preserver = temp->next;
    temp->next = newNode;
    newNode->next = preserver;
    return head;
}

void deleteAtEnd(node *head)
{
    node *temp = head;
    while (temp->next->next != head)
    {
        temp = temp->next;
    }
    node *nodeToBeDeleted = temp->next;
    temp->next = temp->next->next;
    delete nodeToBeDeleted;
}

node *deleteAtBegin(node *head)
{
    node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;

    node *nodeToBeDeleted = head;
    head = head->next;
    delete nodeToBeDeleted;
    return head;
}

node *deleteAtMid(node *head, int pos)
{
    if (pos == 1)
    {
        head = deleteAtBegin(head);
        return head;
    }
    int count = 1;
    node *temp = head;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    node *nodeToBeDeleted = temp->next;
    temp->next = temp->next->next;
    delete nodeToBeDeleted;

    return head;
}

void display(node *head)
{
    node *temp = head;
    cout << endl;
    do
    {
        cout << temp->value << " ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    node *firstNode = new node(1);
    firstNode->next = firstNode;
    node *head = firstNode;
    head = insertAtBeginning(head, 2);
    insertAtEnd(head, 4);
    display(head);

    head = insertAtMid(head, 6, 3);
    display(head);

    head = insertAtMid(head, 9, 3);
    display(head);

    head = insertAtMid(head, 23, 1);
    display(head);

    deleteAtEnd(head);
    display(head);

    head = deleteAtBegin(head);
    display(head);

    head = deleteAtBegin(head);
    display(head);

    head = deleteAtMid(head, 3);
    display(head);

    return 0;
}
