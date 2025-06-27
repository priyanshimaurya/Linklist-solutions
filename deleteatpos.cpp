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
        }
        else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
    }

    void deleteposition(int pos) {
        if (head == NULL) {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        Node* temp = head;
        int count = 1;

        
        while( count < pos) {
            temp = temp->next;
            count++;
        }

        if (temp == NULL) {
            cout << "Position " << pos << " is out of range.\n";
            return;
        }

        
        if (temp == head) {
            head = temp->next;
        
        }
        
        
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp; 
    }
};

int main() {
    Doublell dll;
    dll.inserthead(1);
    dll.inserthead(2);
    dll.inserthead(3);
    dll.display();
    cout << "Deleting at position 2:\n";
    dll.deleteposition(2);
    dll.display();
    cout << "Deleting at position 5:\n";
    dll.deleteposition(1); 
    dll.display();

    return 0;
}
