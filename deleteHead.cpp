#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
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
    cout<<endl;
}
Node* deleteHead(Node*head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}

int main(){
    vector<int> arr={23,56,43,76};;
    Node* head=new Node(arr[0],nullptr);    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr);
        curr->next=temp;
        curr=temp;

    }

    head=deleteHead(head);
    cout<<head->data;
    printLL(head);
}