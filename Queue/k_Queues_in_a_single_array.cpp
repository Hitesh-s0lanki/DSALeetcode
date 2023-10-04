#include<iostream>
using namespace std;

class kQueue{
    public:
    int size;
    int k;
    int *front;
    int *rear;
    int *arr;
    int freeSpot;
    int *next;

    kQueue(int size,int k){

        this -> size = size;
        this -> k = k;
        front = new int[k];
        rear = new int[k];
        for(int i = 0; i < k ;i++){
            front[i] = -1;
            rear[i] = -1;
        }
        next = new int[size];
        for(int i = 0 ; i < size ;i++){
            next[i] = i + 1; 
        }
        next[size - 1] = -1;
        arr = new int[size];
        freeSpot = 0;
    }

    void enqueue(int data,int qn){

        //Overflow
        if(freeSpot == -1){
            cout<<"No Space to push in queue"<<endl;
            return ;
        }

        //finding the first free node
        int index = freeSpot;

        //update the freeSpot
        freeSpot = next[index];

        //check weather it is first node;
        if(front[qn - 1] == -1){
            front[qn - 1] = index;
        }else{
            //link the new element to the prev element
            next[rear[qn - 1]] = index; 
        }

        //update next 
        next[index] = -1;

        //update rear
        rear[qn - 1] = index;

        //push element
        arr[index] = data;

    }

    int dequeue(int qn){

        //UnderFlow
        if(front[qn - 1] == -1){
            cout<<"Queue is empty "<<endl;
            return -1;
        }

        //find the index to pop
        int index = front[qn - 1];

        //front to next node
        front[qn - 1] = next[index];

        //freeSpot ko manage
        next[index] = freeSpot;
        freeSpot = index;

        return arr[index];
    }

};

int main(){

    kQueue *q = new kQueue(5,3);

    q->enqueue(1,1);
    q->enqueue(2,2);
    q->enqueue(3,3);
    q->enqueue(4,1);

    // cout<<q->dequeue(1)<<endl;
    // cout<<q->dequeue(1)<<endl;
    // cout<<q->dequeue(1)<<endl;
    for(int i = 0; i < 5 ; i++){
        cout<<q -> next[i]<<"\t";
    }
}