
#include <stdio.h>
#include <iostream>
using namespace std;
#define n 20

class queue{
    int* arr;
    int front;
    int back;
    
    public :
        queue(){
            arr = new int[n];
            front = -1;
            back = -1;
        }
        
        void push(int x){
            if(back == n-1){
                cout<<"queue overflowed"<<endl;
                return;
            }
            
            back++;
            arr[back] = x;
            
            if(front == -1){
                front++;
            }
        }
        
        void pop(){
            if(front == -1 || front > back){
                cout<<"No elements present"<<endl;
                return;
            }
            
            front++;
        }
        
        int peek(){
            if(front == -1 || front > back){
                cout<<"No elements present"<<endl;
                return -1;
            }
            
            return arr[front];
        }
        
        bool empty(){
            if(front == -1 || front > back){
                return true;
            }
            
            return false;
        }
};

int main()
{
    queue Q;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);
    
    cout<<Q.peek()<<endl;
    Q.pop();
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    
    cout<<Q.peek()<<endl;
    Q.pop();
    cout<<Q.empty()<<endl;
    
    cout<<Q.peek()<<endl;
    

    return 0;
}
