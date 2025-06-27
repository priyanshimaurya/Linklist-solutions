#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};
class Doublelinklist{
    public:
   Node* head;
   Node* tail;
   Doublelinklist(){
    head=NULL;
    tail=NULL;
   }
   void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
   }
   void inserthead(int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head=newnode;
        tail=newnode;
        return;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
   }
   void deletemid(Node* &head,Node* &tail){
        
        if(head==NULL || tail==NULL|| head==tail){
            return;
        }
        Node* left=head;
        Node* right=head;
        while(right!=NULL&& right->next!=NULL){
            left=left->next;
            right=right->next->next;
        }
            left->prev->next = left->next;
            left->next->prev = left->prev;
        

        delete left;
   }
};
int main(){
    Doublelinklist dll;
    dll.inserthead(1);
    dll.display();
    dll.inserthead(2);
    dll.display();
    dll.inserthead(3);
    dll.display();
    dll.inserthead(4);
    dll.display();
    dll.inserthead(5);
    dll.display();
    dll.deletemid(dll.head,dll.tail);
    dll.display();
    return 0;
}