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

void insertAtTail(Node *&head, Node *&tail, int integerValue)
{
    Node *newNode = new Node(integerValue);
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    tail->nextPointer = newNode;
    newNode->previousPointer = tail;
    tail = newNode;
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
    Node *head = NULL;
    Node *tail = NULL;

    int inputValue;
    while (true)
    {
        cin >> inputValue;
        if (inputValue == -1)
        {
            break;
        }
        else
        {
            insertAtTail(head, tail, inputValue);
        }
    }

    printForward(head);

    return 0;
}