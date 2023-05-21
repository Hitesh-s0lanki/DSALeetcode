#include <iostream>
using namespace std;
class Queue
{
    int *arr;
    int qfront = -1;
    int rear = -1;
    int size = 10001;

public:
    Queue()
    {
        // Implement the Constructor

        arr = new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty()
    {
        // Implement the isEmpty() function
        return qfront == rear;
    }

    void enqueue(int data)
    {
        // Implement the enqueue() function
          if(rear == size)
            cout << "Queue is Full" << endl;
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue()
    {
           if(qfront == rear) {
            return -1;
        }
        else
        {	int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront = 0;
                rear = 0;
            }
         return ans;
        }

    }

    int front()
    {
    if(qfront == rear) {
            return -1;
        }
        else
        {
            return arr[qfront];
        }
    }
};
int main()
{
    cout << "hello world";
}