#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;
    Node(int val){
        data=val;
        next=nullptr;
        prev=nullptr;
    }
};
Node* insertathead(Node* head,int newdata){
    Node *newnode= new Node(newdata);
    newnode->next=head;
    if(head!=nullptr){
        head->prev=newnode;
    }
    return newnode;
}
void printDl(Node* head){
    Node* curr=head;
    while(curr!=nullptr){
        cout<<" "<<curr->data;
        curr=curr->next;
    }
    cout<<endl;
}
Node* insertionatend(Node* head, int newdata){
    Node* newnode= new Node(newdata);
    if(head==nullptr){
        head=newnode;
    }
    else{
        Node* curr=head;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=newnode;
        newnode->prev=curr;
    }
    return head;
}
Node* insertatpos(Node* head, int newdata,int pos){
    Node* newnode= new Node(newdata);
    if(pos==1){
        newnode->next=head;
    }
    if(head!=nullptr){
        head->prev=newnode;
    }
    head=newnode;
    return newnode;
}
Node* reversenode(Node* curr){
    if(curr==nullptr){
        return nullptr;        
    }
    swap(curr->prev,curr->next);
    if(curr->prev==nullptr){
        return curr;
    }
    return reversenode(curr->prev);
}
int sizeofdll(Node* curr){
    int size=0;
    while(curr!=nullptr){
        size++;
        curr=curr->next;
    }
    return size;
}
int main(){
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head = reversenode(head);
    printDl(head);

}
