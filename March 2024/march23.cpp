#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtTail(node* &head, node* &tail, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        tail=n;
        return;
    }
    tail->next=n;
    tail=n;
}

void display(node* head){
    node* temp = head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* getMiddle(node* head){
    node* fast = head->next;
    node* slow = head;
    while (fast && fast -> next) {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}

node* reverseLL(node* &head){
    if(!head || !head->next ){
        return head;
    }
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    while(curr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

void reorderList(node* head){
    node* mid = getMiddle(head);
    node* first = head;
    node* second = mid->next;
    mid->next = NULL;
    second = reverseLL(second);
    while(second){
        node* temp1 = first->next;
        first->next = second;
        node* temp2 = second->next;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

int main(){
    node* head = NULL;
    node* tail = NULL;
    int arr[]={1,2,3,4,5,6,7};
    for(int i=0;i<7;i++){
        insertAtTail(head,tail,arr[i]);
    }
    display(head);
    reorderList(head);
    display(head);
    return 0;
}