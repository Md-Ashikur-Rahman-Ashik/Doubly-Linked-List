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

void deleteAtHead(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *deleteNode = head;
        head = head->nextPointer;
        head->previousPointer = NULL;
        delete deleteNode;
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

    deleteAtHead(head);
    printForward(head);

    return 0;
}