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

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
}

void display(node* head){
    node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }cout<<endl;
}

node* getMiddle(node* head){
    node* slow = head;
    node* fast = head -> next ;
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node* reverse(node* &head){
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    return prev;
}

bool checkPalindrome(node* &head){
    if(head->next==NULL){return true;}
    node* mid = getMiddle(head);
    node* temp = mid->next;
    mid->next = reverse(temp);

    node* head1 = head;
    node* head2 = mid->next;
    while(head2!=NULL){
        if(head1->data!=head2->data){return false;}
        head1=head1->next;
        head2=head2->next;
    }
    return true;
}

int main(){
    //ex: 1
    node* head = NULL;
    int arr[]={1,2,3,3,2,1};
    for (auto i :arr) {insertAtTail(head,i);}
    display(head);
    bool ans = checkPalindrome(head);
    cout<<"Ans: "<<ans<<endl;
    
    cout<<endl;
    
    //ex: 2
    node* head1 = NULL;
    int arr1[]={1,2,3,4};
    for (auto i :arr1) {insertAtTail(head1,i);}
    display(head1);
    bool ans1 = checkPalindrome(head1);
    cout<<"Ans: "<<ans1<<endl;
    return 0;
}