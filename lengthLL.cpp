#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};
int countnode(Node* head) {
    int count = 0;
    Node* curr = head;
    while (curr != NULL) {
        count++;
        curr = curr->next;
    }
    return count;
}
void printLL(Node* head) {  
    Node* curr = head;

    while (curr != nullptr) {
        cout << curr->data;
        if (curr->next != nullptr) {
            cout << " -> ";
        }
        curr = curr->next;
    }
    cout << endl;
}
Node* deletenodeatfirst(Node* head){
    if(head==NULL){
        return NULL;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
Node* deletenodeatend(Node* head){
    if(head==NULL){
        return NULL;
    }
    if(head->next==NULL){
        delete head;
        return nullptr;
    }
    Node* secondlast=head;
    while(secondlast->next->next!=nullptr){
        secondlast=secondlast->next;
    }
    delete secondlast->next;
    secondlast->next=nullptr;
    return head;
}
Node* nodeinsertfront(Node* head, int x) {
    Node* newNode = new Node(x);
    newNode->next = head;
    return newNode;
}
Node* deleteatposition(Node* head,int pos){
    Node* temp=head;
    if(pos==1){
        head=temp->next;
        delete temp;
        return head;
    }
    Node* prev=nullptr;
    for(int i=1;i<pos;i++){
        prev=temp;
        temp= temp->next;
    }
    prev->next=temp->next;
    delete temp;
    return head;
}
bool searchnode(Node* head, int key) {   
    Node* curr = head;
    while (curr != NULL) {
        if (curr->data == key) {
            return true;
        }
        curr = curr->next;
    }
    return false;
}
int middleNode(Node* head){
    Node* slow=head;
    Node* fast=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow->data;
}
int  countkey(Node* head,int key){
    if(head==NULL){
        return 0;
    }
    int ans=countkey(head->next,key);
    if(head->data==key){
        ans++;
    }
    return ans;

}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next=new Node(4);
    head->next->next->next->next= new Node(1);
    head->next->next->next->next->next= new Node(5);
    // int key=1;

    cout<<countnode(head);
    return 0;
}