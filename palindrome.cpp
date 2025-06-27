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
    void palindrome(Node* & head,Node* & tail){
        while(head!=tail&& tail->prev!=NULL){
            if(head->val!=tail->val){
                cout<<"this is not a palindrome number";
                break;
            }
            head=head->next;
            tail=tail->prev;
           
        }
        cout << "it is a palindrome number " << endl;

    }

};
int main(){
    Doublell dll;
    dll.inserthead(1);
    dll.inserthead(2);
    dll.inserthead(3);
    dll.inserthead(4);
    dll.inserthead(3);
    dll.inserthead(2);
    dll.inserthead(1);
    dll.display();
    dll.palindrome(dll.head,dll.tail);

}