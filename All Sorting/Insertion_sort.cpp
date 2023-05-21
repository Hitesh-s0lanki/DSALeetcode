#include <iostream>
#include <vector>

using namespace std;
void insertionSort(vector<int> &a){
    int n=a.size();
    for(int i=1;i<n;i++){

        int temp=a[i];
        int j=i-1;
        while(j>=0){
            if(a[j]>temp){
                a[j+1]=a[j];
            }
            else{
                break;
            }
            j--;
        }
        a[j+1]=temp;

    }
}

int main()
{
    vector<int> a = {4, 2, 3, 1, 3, 2};
    insertionSort(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << "\t";
    }
}