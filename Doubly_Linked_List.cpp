
#include <stdio.h>
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* prev = NULL;
    node* next = NULL;
    
    node(int val){
        data = val;
    }
};

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    
    n->next = head;
    if(head != NULL){
        head->prev = n;
    }
    
    head = n;
};

void insertAtTail(node* &head, int val){
    node* n = new node(val);
    
    if(head == NULL){
        insertAtHead(head, val);
        return;
    }
    
    node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = n;
    n->prev = temp;
};

void deleteAtHead(node* &head){
    node* toDelete = head;
    
    head = head->next;
    head->prev = NULL;
    
    delete toDelete;
}

void deletion(node* &head, int pos){
    if(pos == 1){
        deleteAtHead(head);
        return;
    }
    
    node* temp = head;
    int i = 1;
    
    while(temp != NULL && i != pos){
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next; 
    
    if(temp->next != NULL){
        temp->next->prev = temp->prev;
    }
    
    delete temp;
}

void display(node* head){
    node* temp = head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
};

node* reverse(node* head) {
    node* prevp = NULL;
    node* current = head;
    node* np;
    
    while(current != NULL){
        np = current->next;
        current->next = prevp;
        current->prev = np;
        
        prevp = current;
        current = np;
    }
    
    head = prevp;
    return head;
}


int main(){
    cout<<"\n WE'RE LEARNING DOUBLY LINKED LISTS\n"<<endl;
    
    node* head = NULL;
    insertAtHead(head, 0);
    
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    
    display(head);
    
    deletion(head, 5);
    
    display(head);
    return 0;
}
