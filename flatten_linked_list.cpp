#include<bits/stdc++.h>
using namespace std;

class node {
public:
    int data;
    node *next;
    node *child;

    node() : data(0), next(nullptr), child(nullptr) {};
    node(int x) : data(x), next(nullptr), child(nullptr) {}
    node(int x, node *nextnode, node *childnode) : data(x), next(nextnode), child(childnode) {}
};

node* bruteFlatten(node* head){
    // 1. convert linked list into array
    vector<int>nums;
    while(head!=nullptr){
        node* temp=head;
        while(temp!=nullptr){
            nums.push_back(temp->data);
            temp=temp->child;
        }
        head=head->next;
    }
    // 2. sort the array
    sort(nums.begin(),nums.end());

    // 3. create new linkedlist and add sorted data
    node* dummy=new node(-1);
    node* temp=dummy;
    for(auto i:nums){
        temp->child=new node(i);
        temp=temp->child;
    }
    return dummy->child;
}
node* merge(node* l1,node* l2){
    node* dummy=new node(-1);
    node* temp=dummy;

    while(l1!=nullptr && l2!=nullptr){
        if(l1->data < l2->data){
            temp->child=l1;
            temp=l1;
            l1=l1->child;
        }else{
            temp->child=l2;
            temp=l2;
            l2=l2->child;
        }
        temp->next=nullptr;
    }

    if(l1) temp->child=l1;
    else temp->child=l2;

    if(dummy->child){
        dummy->child->next=nullptr;
    }
    return dummy->child;
}

node* optimalFlatten(node *head){
    if(head==nullptr || head->next==nullptr) return head;
    node* mergeHead=optimalFlatten(head->next);
    head=merge(head,mergeHead);
    return head;
}

void printList(node *head){
    while(head!=nullptr){
        node* temp=head;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->child;
        }
        cout<<endl;
        head=head->next;
    }
}

int main(){
    node* head = new node(5);
    head->child = new node(14);
    
    head->next = new node(10);
    head->next->child = new node(4);
    
    head->next->next = new node(12);
    head->next->next->child = new node(20);
    head->next->next->child->child = new node(13);
    
    head->next->next->next = new node(7);
    head->next->next->next->child = new node(17);

    cout<<"\nOrigional List :"<<endl;
    printList(head);

    node* newHead1=bruteFlatten(head);
    node* newHead2=optimalFlatten(head);

    cout<<"\nBrute Force Flatten List :"<<endl;
    printList(newHead1);

    cout<<"\nOptimal Flatten List :"<<endl;
    printList(newHead2);
    return 0;
}