#include<iostream>
using namespace std;
class Node{
    public:
    string val;
    Node* next;
    Node* prev;
    Node(string data){
        val=data;
        next=NULL;
    }
};
class doublell{
    public:
    Node*head;
    Node*tail;
    doublell(){
        head=NULL;
        tail=NULL;
    }
void insertNode(string val){
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
            return ;
        }
}
void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" <-> ";
        temp=temp->next;
    }
    cout<<endl;
}
};
int main(){
    doublell dll;
    dll.insertNode("orange");
    dll.display();
    dll.insertNode("Green");
    dll.display();
    dll.insertNode("red");
    dll.display();
    return 0;
}