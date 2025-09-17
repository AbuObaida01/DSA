#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1=nullptr){
        data=data1;
        next=next1;

    }
};

void printLL(Node* head){
    Node* mover=head;
    while(mover!=nullptr){
        cout<<mover->data<<" ";
        mover=mover->next;
    }
}
Node* reverseLL(Node* head){
    Node*prev=nullptr;
    Node* curr=head;
    Node* nextnode=nullptr;
while(curr!=nullptr){
    Node* nextnode=curr->next;
    curr->next=prev;
    prev=curr;
    curr=nextnode;
}
return prev;}

bool isP(Node* head){
    if(!head||!head->next) return true;
    Node* slow=head;
    Node* fast=head;
    while(fast->next!=nullptr && fast->next->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
    }

Node* secondH=reverseLL(slow->next);
Node* p1=head;
Node* p2=secondH;
while(p2!=nullptr){
    if(p1->data!=p2->data) return false;
    p1=p1->next;
    p2=p2->next;
}
return true;
}
int main(){
    vector<int> arr={1,3,22,1};
    Node* head=new Node(arr[0], nullptr);
    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i], nullptr);
        curr->next=temp;
        curr=temp;
    }
    if(isP(head)) cout<<"true";
    else cout<<"false";
    return 0;
}
