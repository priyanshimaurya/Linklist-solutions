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
    void inserthead(int val){
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

    void AddAtIndex(int val,int pos){
        if(tail==NULL){
            head=NULL;
            tail=NULL;
            return;
        }
        Node*newnode=new Node(val);
        Node*temp=head;
        int count=1;
        while(count<pos-1){
            temp=temp->next;
            count++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next->prev=newnode;
        return ;
    }
};
int main(){
    Doublell dll;
    dll.inserthead(1);
    dll.inserthead(2);
    dll.inserthead(3);
    dll.display();
    cout<<"after inserting  val at postion"<<endl;
    dll.AddAtIndex(0,2);
    dll.display();
    return 0;
}