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

void insertAtAnyPosition(Node *&head, Node *&tail, int desiredIndex, int desiredValue)
{
    Node *newNode = new Node(desiredValue);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    if (desiredIndex == 0)
    {
        newNode->nextPointer = head;
        head->previousPointer = newNode;
        head = newNode;
        return;
    }

    Node *tmp = head;

    for (int i = 0; i < desiredIndex - 1; i++)
    {
        tmp = tmp->nextPointer;
    }

    newNode->nextPointer = tmp->nextPointer;
    newNode->previousPointer = tmp;
    tmp->nextPointer = newNode;

    if (tmp->nextPointer == tail)
    {
        tail = newNode;
        return;
    }
}

void printForward(Node *head)
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

    insertAtAnyPosition(head, tail, 2, 100);
    printForward(head);

    return 0;
}