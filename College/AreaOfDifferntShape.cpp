#include<iostream>
using namespace std;
class Area{
    public:
    double Rect(){
        float length;
        float width;
        cout<<"Enter the length of Rectangle"<<endl;
        cin>>length;
        cout<<"Enter the Width of Rectangle"<<endl;
        cin>>width;
        return length*width;
    }
    double triangle(){
        float height;
        float base;
        cout<<"Enter the Height of triangle"<<endl;
        cin>>height;
        cout<<"Enter the base of triangle"<<endl;
        cin>>base;

        return 0.5*height*base;
    }

};
int main(){
    Area a;
    cout<<a.Rect();
}
// Area of Rectangle	Area = l × w	l =  length
// w  = width

// Area of Square	Area  = a2	a = sides of the square
// Area of a Triangle	Area = 1/2 b×h	b = base
// h = height

// Area of a Circle	Area = πr2	r = radius of the circle
// What is the area of sphere?
// 4πr²

// Sphere
// Solve for volume
// V=4/3πr3

// circumference
// C=2πr