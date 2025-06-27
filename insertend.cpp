#include<iostream>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;
    Node(string data) {
        val = data;
        next = NULL;
        prev = NULL;
    }
};

class doublell {
public:
    Node* head;
    Node* tail;

    doublell() {
        head = NULL;
        tail = NULL;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " <--> ";
            temp = temp->next;
        }
        cout << endl;
    }

    void insertend(string val) {
        Node* newnode = new Node(val);
        if (tail == NULL) {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
};

int main() {
    doublell dll;
    dll.insertend("orange");
    dll.insertend("pink");
    dll.insertend("red");

    dll.display(); 

    return 0;
}
