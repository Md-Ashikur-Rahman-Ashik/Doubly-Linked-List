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

void deleteAtTail(Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        return;
    }
    else if (head->nextPointer == NULL)
    {
        Node *deleteNode = tail;
        head = NULL;
        tail = NULL;
        delete deleteNode;
        return;
    }

    Node *deleteTail = tail;
    tail = tail->previousPointer;
    tail->nextPointer = NULL;
    delete deleteTail;
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

    deleteAtTail(head, tail);
    printForward(head);

    return 0;
}