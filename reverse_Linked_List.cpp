#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data1,Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=NULL;
    }
};
void printList(Node* head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    printList(head->next);
}
Node* usingStack(Node* head){
    stack<int>st;
    Node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    temp=head;
    while(temp!=NULL){
        temp->data=st.top();
        st.pop();
        temp=temp->next;
    }
    return head;
}

Node* reversePlace(Node* head){
    Node* prev=NULL;
    Node* temp=head;
    while(temp!=NULL){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* usingRecursion(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* newHead=usingRecursion(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}
int main(){
    Node* head=new Node(1);
    head->next=new Node(3);
    head->next->next=new Node(2);
    head->next->next->next=new Node(4);

    cout<<"Origional Linked List :";
    printList(head);

    // head=usingStack(head);
    // head=reversePlace(head);
    head=usingRecursion(head);

    cout<<endl<<"Reverse Linked List :";
    printList(head);
    return 0;
}