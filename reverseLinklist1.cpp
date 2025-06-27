#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
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
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"->";
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
    void reverse(){
        Node* current_node=head;
        while(current_node!=NULL){
            Node* nextnode=current_node->next;
            current_node->next=current_node->prev;
            current_node=nextnode;
        }
        Node* newhead=tail;
        tail=head;
        head=newhead;
    }
};
int main(){
    doublell dll;
    dll.inserthead(1);
    dll.inserthead(2);
    dll.inserthead(3);
    dll.display();
    dll.reverse();
}