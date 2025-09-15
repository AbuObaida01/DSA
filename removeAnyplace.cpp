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
    cout<<endl;

}
Node* removeAnyPlace(Node* head, int elm){
    if (head==NULL) return head;
    if(elm==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;

    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==elm){
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
    vector<int> arr={4,7,5,9};
    Node*head=new Node(arr[0], nullptr);
    Node* curr=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr);
        curr->next=temp;
        curr=temp;
    }
    printLL(head);
    head=removeAnyPlace(head,3);
    printLL(head);
}
