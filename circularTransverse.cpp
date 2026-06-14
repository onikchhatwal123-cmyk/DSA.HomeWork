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

class CircularDoublyLinkedList
{
public:
    Node *head;

    CircularDoublyLinkedList()
    {
        head = NULL;
    }

    void insertFront(int x)
    {
        Node *node = new Node(x);
        if (head == NULL) {
            head = node;
            node->next = head;
            node->prev = head;
            return;
        }
        Node *tail = head->prev;

        node->next = head;
        node->prev = tail;
        head->prev = node;
        tail->next = node;
        head = node;
    }

    void insertEnd(int x)
    {
        Node *node = new Node(x);
        if (head == NULL) {
            head = node;
            node->next = head;
            node->prev = head;
            return;
        }
        Node *tail = head->prev;

        tail->next = node;
        node->prev = tail;
        node->next = head;
        head->prev = node;
    }

    void traverseCircular() {
        if (head == NULL) {
            cout << "  [Empty Circular List]\n";
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data;
            temp = temp->next;
            if (temp != head) cout << " <-> ";
        } while (temp != head);
        cout << " <-> (back to " << head->data << ")\n";
    }
};

int main()
{
    CircularDoublyLinkedList LL;
    LL.insertFront(10);
    LL.insertFront(20);
    LL.insertFront(30);
    LL.insertEnd(15);
    LL.insertEnd(25);

    LL.traverseCircular(); 

    return 0;
}