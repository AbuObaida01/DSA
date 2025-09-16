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
Node* removeAnyEle(Node* head, int val){
    if(head==NULL) return head;
    if(head->data==val){
        Node*temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if (temp->data==val){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;

}
int main(){
    vector<int> arr= {3,5,6,8};
    Node* head=new Node(arr[0],nullptr);
    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr);
        curr->next=temp;
        curr=temp;
    }
    head=removeAnyEle(head, 5);
    printLL(head);
}