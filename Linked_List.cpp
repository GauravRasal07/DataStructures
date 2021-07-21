#include <stdio.h>
#include <iostream>
using namespace std;

class node{
    public :
        int data;
        node* next;
        
    node(int val){
        data = val;
        next = NULL;
    };
};

void insert(node* &Head, int val, int key){
    node* n = new node(val);
    
    node* temp = Head;
    while(temp != NULL){
        if(temp->data == key){
            
            node* temp_1 = temp->next;
            temp->next = n;
            n->next = temp_1;
        }
        
        temp = temp->next;
    }
}

void insertAtTail(node* &Head, int val){
    node* n = new node(val);
    
    if(Head == NULL){
        Head = n;
        return;
    }
    
    node* temp = Head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    temp->next = n;
};

void insertAtHead(node* &Head, int val){
    node* n = new node(val);
    
    n->next = Head;
    Head = n;
}

bool search(node* Head, int key){
    node* temp = Head;
    
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        
        temp = temp->next;
    }
    
    return false;
}

void Display(node* Head){
    node* temp = Head;
    
    while(temp != NULL){
        cout<<temp->data<<" ";
        
        temp = temp->next;
    }
    cout<<endl;
};

void Delete(node* &Head, int key){
    if(Head == NULL){
        return;
    }
    
    else if(Head->data == key){
        node* temp = Head->next;
        
        delete Head;
        Head = temp;
        return;
    }
    
    node* temp = Head;
    
    while(temp->next->data != key){
        temp = temp->next;
    }
    
    node* toDelete = temp->next;
    temp->next = temp->next->next;
    
    delete toDelete;
}

void reverse(node* &Head){
    node* prevptr = NULL;
    node* current = Head;
    node* nextptr;
    
    while(current != NULL){
        nextptr = current->next;
        current->next = prevptr;
        
        prevptr = current;
        current = nextptr;
    }
    
    Head = prevptr;
}

node* reverseRecursive(node* &Head){
    if(Head == NULL || Head->next == NULL){
        return Head;
    }
    
    node* newHead = reverseRecursive(Head->next);
    Head->next->next = Head;
    Head->next = NULL;
    
    return newHead;
}

int main(){
    cout<<"Heyy There, We're Learning Linked List\n"<<endl;
    
    node* Head = NULL;
    insertAtTail(Head, 1);
    insertAtTail(Head, 2);
    insertAtTail(Head, 4);
    
    insertAtHead(Head, 0);
    
    insert(Head, 3, 2);
    
    cout<<"Original Linked List is : ";
    Display(Head);
    
    node* newHead = reverseRecursive(Head);
    cout<<"\nReversed Linked List is : ";
    Display(newHead);
    
    reverse(newHead);
    cout<<"\nAgain Reversed Linked List is : ";
    Display(newHead);
    
    return 0;
}