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
            cout<<temp->val<<"  ";
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
    void deletesameneighboursNode(Node* &head, Node* &tail) {
        Node* curNode = tail->prev;
        while (curNode != head) {
            Node* prevnode = curNode->prev;
            Node* nextnode = curNode->next;
            if (prevnode->val == nextnode->val) {
                prevnode->next = nextnode;
                nextnode->prev = prevnode;
                free(curNode);
            }
            curNode = prevnode;
        }
    }
};
int main() {
    Doublell dll;
    dll.inserthead(2);
    dll.inserthead(1);
    dll.inserthead(1);
    dll.inserthead(2);
    dll.inserthead(1);
    
    dll.display(); 
    cout<<"after delete neighbours"<<endl;
    dll.deletesameneighboursNode(dll.head, dll.tail); 
    dll.display(); 
    
    return 0;
}
