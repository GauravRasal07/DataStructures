
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
        }
};

class queue{
    node* front; 
    node* back;
    
  public :
    queue(){
        front = NULL;
        back = NULL;
    }
    
    void push(int x){
        node* n = new node(x);
        
        if(front == NULL){
            back = n;
            front = n;
            return;
        }
        
        back->next = n;
        back = n;
    }
    
    void pop(){
        if(front == NULL){
            cout<<"No elements"<<endl;
            return;
        }
        
        node* toDelete = front;
        front = front->next;
        
        delete toDelete;
    }
    
    int peek(){
        if(front == NULL){
            cout<<"No elements"<<endl;
            return -1;
        }
        
        return front->data;
    }
    
    bool empty(){
        if(front == NULL || back->next == front){
            return true;
        }
        
        return false;
    }
  
};

int main()
{
    queue Q;
    cout<<Q.peek()<<endl;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    cout<<""<<endl;
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    cout<<""<<endl;
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    cout<<""<<endl;
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    cout<<""<<endl;
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    cout<<""<<endl;
    
    return 0;
}
