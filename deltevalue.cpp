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
    void deletevalue(int value) {
        Node* temp = head;

        while (temp != NULL) {
            if (temp->val == value) {
                if (temp->prev != NULL)
                    temp->prev->next = temp->next;
                if (temp->next != NULL)
                    temp->next->prev = temp->prev;
                if (temp == head)
                    head = temp->next;
                if (temp == tail)
                    tail = temp->prev;

                delete temp;  
              
            }
            temp = temp->next;
        }
        cout << "Value " << value << " not found in the list." << endl;
    }
};
int main(){
    Doublell dll;
    dll.inserthead(1);
     dll.inserthead(5);
    dll.inserthead(2);
     dll.inserthead(5);
    dll.inserthead(3);
     dll.inserthead(2);
    dll.inserthead(5);
    cout << "Doubly linked list after insertions:" << endl;
    dll.display();

    dll.deletevalue(2);

    cout << "Doubly linked list after deletion of 2:" << endl;
    dll.display();
    return 0;
}