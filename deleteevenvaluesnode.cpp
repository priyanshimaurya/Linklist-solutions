#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* prev;
    Node* next;
    
    Node(int data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class Doublell {
public:
    Node* head;
    Node* tail;
    
    Doublell() {
        head = NULL;
        tail = NULL;
    }
    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void inserthead(int val) {
        Node* newnode = new Node(val);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }
    
    void deleteevennodevalue() {
        Node* temp = head;
        Node* prev = NULL;

        while (temp != NULL) {
            if (temp->val % 2 == 0) { 
                if (temp == head) { 
                    head = temp->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    }
                } else {
                    prev->next = temp->next;
                    if (temp->next != NULL) {
                        temp->next->prev = prev;
                    }
                }
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
    }
};
int main() {
    Doublell dll;
    dll.inserthead(1);
    dll.inserthead(2);
    dll.inserthead(3);
    dll.inserthead(4);

    cout << "Original List:" << endl;
    dll.display();

    dll.deleteevennodevalue();
    cout << "List after deleting even nodes:" << endl;
    dll.display();
    return 0;
}
