#include<iostream>
#include<vector>
using namespace std;
class node{
    public:
    int data;
    node* next;
    public:
    node(int data1, node* next1=nullptr){
        data=data1;
        next=next1;

    }
};
void printLL(node* head){
    node* mover=head;
    while(mover!=NULL){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}
node* insertAtTail(node* head, int val){
    if(head==NULL){
        return new node (val);}
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    node* newNode=new node(val);
    temp->next=newNode;
    return head;    
    
}
int main(){
    vector<int>arr={3,6,7,9};
    node* head=new node(arr[0], nullptr);
    node* curr=head;
    for(int i=1;i<arr.size();i++){
        node* temp=new node(arr[i],nullptr);
        curr->next=temp;
        curr=temp;
    }
    head=insertAtTail(head,30);
    printLL(head);
}