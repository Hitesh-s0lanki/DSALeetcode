#include<iostream>
#include<vector>

using namespace std;
void BubbleSort(vector<int> &a){
    int n=a.size();
   for(int i=1;i<n-1;i++){
    bool check=true;
    for(int j=0;j<n-i;j++){
        if(a[j]<a[j+1]){
            swap(a[j],a[j+1]);
            check=false;
        }
    }
    if(check){
        break;
    }
   }
}
int main(){
    vector<int> a={4,2,3,1,3,2};
    BubbleSort(a);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"\t";
    }
}