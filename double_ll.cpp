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
};
int main(){
    Node* new_node=new Node(3);

    Doublell dll;
    dll.head=new_node;
    dll.tail=new_node;
    cout<<dll.head->val<<endl;
    
    
       
}