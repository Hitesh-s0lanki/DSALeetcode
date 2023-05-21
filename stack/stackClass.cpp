#include <iostream>
using namespace std;
template <typename t>
class Stack
{
public:
    int size;
    t *arr;
    int top = -1;
    Stack(int size)
    {
        this->size = size;
        arr = new t[size];
    }
    void push(t data)
    {
        top++;
        if (top < size)
        {
            arr[top] = data;
        }
        else
        {
            cout << "stack overflow";
            top--;
        }
    }
    void pop()
    {
        if (top > -1)
        {
            top--;
        }
        else{
            cout<<"stack underflow"<<endl;
        }
    }
    t peek(){
        if(top>-1){
            return arr[top];
        }
    }
};
int main()
{
    Stack<int> s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.pop();
    cout<<"the peek element is "<<s.peek();
}