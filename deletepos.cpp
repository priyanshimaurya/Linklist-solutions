#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int data){
        val=data;
        prev=NULL;
        next=NULL;
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
    
    // Method to delete a node at a specified position
    void deletepos(int pos) {
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }
        
        Node* temp = head;
        int count = 1;
        while (temp != NULL && count < pos) {
            temp = temp->next;
            count++;
        }
        
        if (temp == NULL) {
            cout << "Out of range" << endl;
            return;
        }
        
        if (temp == head) {
            head = temp->next;
        } 
        
        else {
            temp->prev->next = temp->next;
            if (temp->next != NULL) {
                temp->next->prev = temp->prev;
            }
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
    
    cout << "After delete :-" << endl;
    dll.deletepos(8);
    dll.display();
    
    return 0;
}
