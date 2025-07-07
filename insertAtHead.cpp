#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *previousPointer;
    Node *nextPointer;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->previousPointer = NULL;
        this->nextPointer = NULL;
    }
};

void insertAtHead(Node *&head, Node *&tail, int integerValue)
{
    Node *newNode = new Node(integerValue);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->nextPointer = head;
        head->previousPointer = newNode;
        head = newNode;
    }
}

void printForward(Node *&head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->integerValue << " ";
        tmp = tmp->nextPointer;
    }
}

int main()
{
    Node *head = new Node(10);
    Node *secondNode = new Node(20);
    Node *tail = new Node(30);

    head->nextPointer = secondNode;
    secondNode->previousPointer = head;

    secondNode->nextPointer = tail;
    tail->previousPointer = secondNode;

    insertAtHead(head, tail, 100);
    printForward(head);

    return 0;
}