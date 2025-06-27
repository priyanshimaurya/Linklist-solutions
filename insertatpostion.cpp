#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        val=data;
        next=NULL;
    }
};
class circularll{
    public:
    Node* head;
        circularll(){
            head=NULL;
        }
void display(){
    if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }
    Node* temp=head;
    do{
        cout<<temp->val<<"->";
        temp=temp->next;
    }
    while(temp!=head);
        cout<<endl;
    
}
void insertnode(int val){
    Node* newNode=new Node(val);
    if(head==NULL){
        head=newNode;
        newNode->next=head;// circular ll beacause newnode is head or lastnode thats why newnode->head;
        return ;
    }
    Node* lastnode=head;
    while(lastnode->next!=head){
        lastnode=lastnode->next;
    }
    //now lastnode node we get 
    lastnode->next=newNode;
    newNode->next=head;
    head=newNode;

    }  
    void InsertAtPos(int val,int pos){
        Node* curnode=0;
        Node* newnode=new Node(val);
        if(pos==0){
            head=newnode;
            newnode->next=head;//circular ll;
            return;
        }
        Node* new_node = new Node(val);
        Node* temp = head;
        int current_position = 0;
        while (current_position != pos - 1 ) {
        temp = temp->next;
        current_position++;
        }
        new_node->next = temp->next;
        temp->next = new_node;
}
};
int main() {
    circularll cll;
    cll.insertnode(6);
    cll.insertnode(8);
    cll.insertnode(10);
    cll.display();
    cll.InsertAtPos(1,3);
    cll.display();
    return 0;
}