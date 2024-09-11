#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;
    Node(): data(0),next(nullptr),random(nullptr){};
    Node(int x): data(x),next(nullptr),random(nullptr){};
    Node(int x,Node* nextNode,Node* randomNode): data(x),next(nextNode),random(randomNode){}; 
};

void printlist(Node* head){
    while(head!=nullptr) {
        cout<<"Data: "<<head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
    cout<<endl;
}

Node* cloneLL(Node* head){
    Node* temp=head;
    unordered_map<Node*,Node*>map;

    while(temp!=nullptr){
        map[temp]=new Node(temp->data);
        temp=temp->next;
    }

    temp=head;
    while(temp!=nullptr){
        Node* cloneNode=map[temp];
        cloneNode->next=map[temp->next];
        cloneNode->random=map[temp->random];
        temp=temp->next;
    }
    return map[head];
}

void insertCopyInBetween(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        Node* cloneNode=new Node(temp->data);
        Node* nextNode=temp->next;
        cloneNode->next=nextNode;
        temp->next=cloneNode;
        temp=nextNode;
    }
}

void connectRandomPointer(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        Node* copyNode=temp->next;
        if(temp->random){
            copyNode->random=temp->random->next;
        }
        else{
            copyNode->random=nullptr;
        }
        temp=temp->next->next;
    }
}

Node* getDeepCopy(Node* head){
    Node* temp=head;
    Node* dummy=new Node(-1);
    Node* res=dummy;
    while(temp!=nullptr){
        res->next=temp->next;
        res=res->next;

        temp->next=temp->next->next;
        temp=temp->next;
    }
    return dummy->next;
}

Node* cloneLLoptimal(Node* head){
    insertCopyInBetween(head);
    connectRandomPointer(head);
    return getDeepCopy(head);
}


int main(){
    Node* head= new Node(7);
    head->next = new Node(14);
    head->next->next = new Node(21);
    head->next->next->next = new Node(28);

    // Assigning random pointers
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout<<"Origional List : "<<endl;
    printlist(head);
    
    Node* clonelist=cloneLL(head);
    Node* clonelistoptimal=cloneLL(head);

    cout<<"Clone List : "<<endl;
    printlist(clonelistoptimal);

    return 0;
}