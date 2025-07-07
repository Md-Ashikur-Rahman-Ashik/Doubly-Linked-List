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

void deleteAtAnyPosition(Node *&head, Node *&tail, int desiredPosition)
{
    if (head == NULL)
    {
        return;
    }

    if (desiredPosition == 0)
    {
        if (head->nextPointer == NULL)
        {
            Node *deleteNode = head;
            head = NULL;
            tail = NULL;
            delete deleteNode;
            return;
        }
        else
        {
            Node *deleteNode = head;
            head = head->nextPointer;
            head->previousPointer = NULL;
            delete deleteNode;
            return;
        }
    }

    Node *tmp = head;
    for (int i = 0; i < desiredPosition - 1; i++)
    {
        tmp = tmp->nextPointer;
    }

    if (tmp->nextPointer == tail)
    {
        Node *deleteNode = tail;
        tail = tail->previousPointer;
        tail->nextPointer = NULL;
        delete deleteNode;
        return;
    }

    Node *deleteNode = tmp->nextPointer;
    tmp->nextPointer = deleteNode->nextPointer;
    deleteNode->previousPointer = tmp;
    delete deleteNode;
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

    deleteAtAnyPosition(head, tail, 1);
    printForward(head);

    return 0;
}