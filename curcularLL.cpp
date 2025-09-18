#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=nullptr;
    }
};
Node* insertathead(Node* last,int key){
    Node* newnode= new Node(key);
    if(last==nullptr){
        newnode->next=newnode;
        return newnode;
    }
    newnode->next=last->next;
    last->next=newnode;
    return last;
}
Node* insertatend(Node* tail,int key){
    Node* newnode= new Node(key);
    if(tail==nullptr){
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        newnode->next=tail->next;
        tail->next=newnode;
        tail=newnode;
    }
    return tail;
    
}   
void printll(Node* last){
    if(last==NULL){
        return ;
    }
    Node* head=last->next;
    Node* temp=head;
    do{
        cout<<temp->data;
        temp=temp->next;
        if(temp!=head){
            cout<<"->";
        }
    }
    while(temp!=head);
    cout<<endl;
}
int main(){
    Node* first = new Node(2);
    first->next = new Node(3);
    first->next->next = new Node(4);

    Node* last = first->next->next;
    last->next = first;
    last=insertatend(last,5);
    printll(last);
}