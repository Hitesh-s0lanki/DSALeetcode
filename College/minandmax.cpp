#include <iostream>
using namespace std;
class Max
{
    int a;

public:
    Max(int a)
    {
        this->a = a;
    }
    friend void maxii(Max m1, Max m2);
};
void maxii(Max m1, Max m2)
{
    if (m1.a > m2.a)
    {
        cout << m1.a;
    }
    else
    {
        cout << m2.a;
    }
}
int main()
{
    Max m1(1), m2(2);
    maxii(m1, m2);
}