#include <iostream>
using namespace std;
template <typename t>
class vector
{
public:
    t *arr;
    int capacity = 1;
    int current = -1;
    vector()
    {
        arr = new t[capacity];
    }
    void push(t data)
    {
        current++;
        if (current == capacity)
        {
            t *temp = new t[2 * capacity];
            int i = 0;
            while (i <= current)
            {
                temp[i] = arr[i];
                i++;
            }
            delete[] arr;
            capacity*=2;
            arr = temp;
        }
        arr[current] = data;
    }
    void pop()
    {
        current--;
    }
    int size(){
        return current+1;
    }
    void print()
    {
        for (int i = 0; i <= current; i++)
        {
            cout << arr[i] << "\t";
        }
        cout << endl;
    }
};
int main()
{
    vector<int> a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    a.print();
    cout<<"the size of vector is "<<a.size()<<endl;
}