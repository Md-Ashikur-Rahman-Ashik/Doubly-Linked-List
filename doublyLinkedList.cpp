#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *nextPointer;
    Node *previousPointer;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->nextPointer = NULL;
        this->previousPointer = NULL;
    }
};

void printForward(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->integerValue << " ";
        tmp = tmp->nextPointer;
    }

    cout << endl;
}

void printBackward(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->integerValue << " ";
        tmp = tmp->previousPointer;
    }

    cout << endl;
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

    printForward(head);
    printBackward(tail);

    return 0;
}