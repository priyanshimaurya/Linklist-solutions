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
class doublelinklist{
    public:
    Node* head;
    Node* tail;
    doublelinklist(){
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
        return ;
    }
}
void findmid(){
    if(head==NULL){
        cout<<"list if empty";
        return ;
    }
    Node* left=head;
    Node* right=head;
    while(right!=NULL&& right->next!=NULL){
        left=left->next;
        right=right->next->next;
    }
    cout<<"middle Node is:- "<<left->val<<endl;
}
};
int main(){
    Node* head=NULL;
    doublelinklist dll;
    dll.inserthead(1);
    dll.inserthead(2);
    dll.inserthead(3);
    dll.inserthead(4);
    dll.inserthead(5);
    // dll.inserthead(6);
    dll.display();
    
    dll.findmid();
    
}