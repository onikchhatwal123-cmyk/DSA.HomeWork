#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
public:
    Node *head;

    DoublyLinkedList()
    {
        head = NULL;
    }

    void Display()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    
     void insertFront(int x) {
        Node* node = new Node(x);
        node->next = head;
        if (head)
            head->prev = node;
        head = node;
    }
     void insertEnd(int x) {
        Node* node = new Node(x);
        if (head == NULL) {
            head = node;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = node;
        node->prev = temp;
    }
};

int main()
{
    DoublyLinkedList LL;
    LL.insertFront(10);
    LL.insertFront(20);
    LL.insertFront(30);
    LL.insertFront(40);
    LL.insertFront(50);
    LL.insertEnd(15);
    LL.insertEnd(25);


    LL.Display();

}
