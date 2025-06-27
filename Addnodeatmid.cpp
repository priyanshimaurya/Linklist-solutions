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
class doublell{
    public:
    Node* head;
    Node* tail;
    doublell(){
        head=NULL;
        tail=NULL;
    }
    void insertend(int val){
        Node* newnode=new Node(val);
        if(tail==NULL){
            head=newnode;
            tail=newnode;
            return;
        }
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
   void insertAfterMid(int val) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    
    Node* left = head;
    Node* right = head;
    Node* prev = NULL;

    
    while (right != NULL && right->next != NULL) {
        prev = left;
        left = left->next;
        right = right->next->next;
    }
    
    Node* newNode = new Node(val);
    newNode->next = left->next;
    left->next = newNode;
}

    

};
int main(){
    doublell dll;
    dll.insertend(5);
    dll.insertend(4);
    dll.insertend(3);
    dll.insertend(2);
    dll.insertend(1);
    // dll.insertend(0);
    dll.display();
    
   dll.insertAfterMid(45);
   dll.display();
    return 0;
}