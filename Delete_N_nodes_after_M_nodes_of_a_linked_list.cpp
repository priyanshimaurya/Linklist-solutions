#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int value){
        val=value;
        next=NULL;
        prev=NULL;
    }
};
class DoubleLL{
    public:
    Node* head;
    Node* tail;
    DoubleLL(){
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
            return ;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            return;
        }
    }
    void deleteNandM(int m,int n){
        
    }
};
