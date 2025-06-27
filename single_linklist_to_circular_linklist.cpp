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
void addsinglelinklist(int val) {
        Node* new_node = new Node(val);
        if (head == NULL) {
            head = new_node;
            head->next = head; // Point to itself
        } else {
            new_node->next = head;
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = new_node;
            head = new_node;
        }
    }
};
int main() {
    circularll cll;
    cll.addsinglelinklist(6);
    cll.addsinglelinklist(8);
    cll.addsinglelinklist(10);
    cll.display();

    return 0;
}