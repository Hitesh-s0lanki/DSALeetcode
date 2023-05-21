#include<iostream>
#include<vector>

using namespace std;
void selectionSort(vector<int> &a){
    int n=a.size();
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]>a[j]){
                swap(a[i],a[j]);
            }
        }
    }
}
int main(){
    vector<int> a={4,2,3,1,3,2};
    selectionSort(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"\t";
    }
}