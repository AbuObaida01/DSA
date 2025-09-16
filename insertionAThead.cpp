#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1=nullptr){
        data=data1;
        next=next1;

    }
};
void printLL(Node* head){
    Node* mover=head;
    while(mover!=NULL){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}
Node* insertionAtHead(Node* head, int val){
    return new Node(val,head);

}
int main(){
    vector<int > arr={5,7,9,10};
    Node* head=new Node(arr[0],nullptr);
    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i], nullptr);
        curr->next=temp;
        curr=temp;
    }
    head=insertionAtHead(head,10);
    printLL(head);

}