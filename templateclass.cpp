#include<iostream>
using namespace std;
template <typename T>
class Node{// this is template class
    public:
    T val;
    Node* next;
    Node(T data){
        val=data;
        next=NULL;
    }
};
int main(){
    Node<int>* node1=new Node(10);
    
    cout<<node1->val<<" "<<endl;
    Node<char>* node2=new Node('o');
    cout<<node2->val<<" "<<endl;

}