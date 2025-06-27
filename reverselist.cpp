#include<iostream>
using namespace std;
class Node{
    public:
    string val;
    Node* prev;
    Node* next;
    Node(string data){
        val=data;
        prev=NULL;
        next=NULL;
    }
};
class Doublell{
    public:
    Node* head;
    Node* tail;
    Doublell(){
        head=NULL;
        tail=NULL;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<"<->";
            temp=temp->next;
        }
        cout<<endl;
    }
    void inserthead(string val){
        Node * newnode=new Node(val);
        if(head==NULL){
            head=newnode;
            tail=newnode;
            return;
        }
        else{
            newnode->next=head;
            head->prev=newnode;
            head=newnode;
            return ;
        }
    }
    void reverseNode(Node* &head,Node*& tail){
        Node* curr=head;
        while(curr!=NULL){
            Node* nextnode=curr->next;
            curr->next=curr->prev;
            curr=nextnode;
        }
        Node* newhead=tail;
        tail=head;
        head=newhead;

    }
};
int main(){
    Doublell dll;
    dll.inserthead("red");
    dll.inserthead("white");
    dll.inserthead("green");
    dll.display();
    dll.reverseNode(dll.head,dll.tail);
    dll.display();
    return 0;
}