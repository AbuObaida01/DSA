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
    while(mover!=NULL){
        cout<<mover->data<<" ";;
        mover=mover->next;
    } 
}
Node* insertAtAny(Node* head, int ele, int k){
    if (head==NULL){
        if(k==1){
            return new Node(ele);

        }
        else{
            return head;

        }
    }
    if(k==1){
        return new Node(ele,head);
    }
    int cnt=0;
    Node*temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==(k-1)){
            Node* x=new Node(ele,temp->next);
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}
int main(){
    vector<int>arr={5,6,7,8,};
    Node* head=new Node(arr[0],nullptr);
    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr);
        curr->next=temp;
        curr=temp;
    }
    head=insertAtAny(head,30,3);
    printLL(head);
}