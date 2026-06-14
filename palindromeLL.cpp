#include<iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node* middleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    while(curr) {
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(Node* head) {
   //  Find middle
    Node* mid = middleNode(head);

    // Reverse second half
    Node* secondHalf = reverse(mid);

    // Compare both
    Node* first  = head;
    Node* second = secondHalf;

    while(second) {
        if(first->data != second->data)
            return false;
        first  = first->next;
        second = second->next;
    }
    return true;
}

void printList(Node* head) {
    while(head) {
        cout << head->data;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << " -> NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    printList(head);
    cout << "Is Palindrome : " << (isPalindrome(head) ? "True" : "False");
    
}