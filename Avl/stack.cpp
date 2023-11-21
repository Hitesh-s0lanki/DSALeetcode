#include<iostream>
using namespace std;

class stack{
    int *arr;
    int num;
    int size;
    public:
    stack(int size){
        this -> size = size;
        this -> arr = new int[size];
        this -> num = -1;
    }
    bool push(int val){
        if(num == size - 1){
            cout<<"Stack is Full"<<endl;
            return false;
        }
        num++;
        arr[num] = val;
        return true;
    }
    bool pop(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return false;
        }
        num--;
        return true;
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
        return arr[num];
    }
    bool isEmpty(){
        if(num == -1)
            return true;
        return false;
    }  
};

class queue{
    int *arr;
    int front;
    int rear;
    int size;
    public:
    queue(int size){
        this -> size = size;
        this -> arr = new int[size];
        this -> front = -1;
        this -> rear = -1;
    }
    bool push(int val){
        if(isFull()){
            cout<<"queue is Full"<<endl;
            return false;
        }
        if(rear == size - 1){
            rear = 0;
        }else{
            rear++;
        }

        if(front == -1)
            front = 0;
            
        arr[rear] = val;

        return true;
    }
    bool pop(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return false;
        }
        arr[front] = -1;
        if(front == rear){
            front = -1;
            rear = -1;
        }else if(front == size - 1){
            front = 0;
        }else{
            front++;
        }

        return true;
    }
    int top(){
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
        if(front == -1)
            return true;
        return false;
    }  
    bool isFull(){
        if((front != -1) && ((rear == size - 1 && front == 0) || (front - 1 == rear))){
            return true;
        }
        return false;
    }  
    void print(){
        for(int i = 0 ;i< size ;i++){
            cout<<arr[i]<<"\t";
        }
    }
};

int main(){

    // stack *s = new stack(3);
    // s->push(1);
    // s->push(2);
    // s->push(3);
    // cout<<s->top()<<endl;
    

    queue *q = new queue(3);
    q->push(1);
    q->push(2);
    q->push(3);
    q->pop();
    q->push(4);
    q->pop();
    q->pop();
    q->pop();
    q->push(4);
    cout<<q->top()<<endl;

    q->print();



}