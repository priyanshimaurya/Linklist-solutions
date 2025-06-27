// #include<iostream>
// using namespace std;
// bool pairsum(int arr[],int size,int x ){
//     for(int i=0;i<size-1;i++){
//         for(int j=i+1;j<size;j++){
//             if(arr[i]+arr[j]==x){
//                 cout<< " present at index " << i << " " << j<< endl;
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// void maxrepetedchar(string arr[]){

// }
// int main(){
//     int arr[]={0, -3,-1, 2, 1 };
//     int x=-2;
//     int size=sizeof(arr)/sizeof(arr[0]);
//     if(pairsum(arr,size,x)){}
        
    
//     else{
//         cout<<"no";
//     }
//     return 0;
// }
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node* prev;
    Node(int data){
        val=data;
        next=NULL;
        
    }
};
class doublell{
    public:
    Node* head;
    Node* tail;
    doublell(){
        head=NULL;
        tail=NULL;
    }
    void addhead(int val){
    Node* newnode=new Node(val);
    if(head==NULL){
        head= newnode;
        tail=newnode;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
}
void display(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<"->"<<temp->val;
        temp=temp->next;
    }
    cout<<endl;
}
void middle() {
        if (head == NULL) {
            cout << "empty linklist" << endl;
            return;
        }
        
        Node* left = head;
        Node* right = head;
        
        while (right != NULL && right->next != NULL) {
            left = left->next;
            right = right->next->next;
        }
        
        cout << "middle value of linklist is: " << left->val << endl;
    }
};
int main(){
    doublell dll;
    dll.addhead(1);
    dll.addhead(2);
    dll.addhead(3);
    dll.addhead(4);
    dll.addhead(5);
    dll.display();
    dll.middle();
    return 0;
}