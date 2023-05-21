#include<iostream>
#include<vector>
using namespace std;
int partiton(vector<int> &a,int s,int e){
    int pivot=a[s];
    int cnt=0;
    for(int i=s;i<=e;i++){
        if(a[i]<pivot){
            cnt++;
        }
    }

    int pivotIndex=s+cnt;
    swap(a[pivotIndex],a[s]);

    int i=s;
    int j=e;
    while(i<pivotIndex&&j>pivotIndex){
        while(a[i]<a[pivotIndex]){
            i++;
        }
        while(a[j]>a[pivotIndex]){
            j--;
        }
        if(i<pivotIndex &&j>pivotIndex)
        swap(a[i++],a[j--]);
    }


    return pivotIndex;
}
void quickSort(vector<int> &a,int s,int e){

    if(s>=e){
        return ;
    }
    int p=partiton(a,s,e);

    quickSort(a,s,p-1);
    quickSort(a,p+1,e);
}
int main(){
    vector<int> a={6,5,43,3,2,1,5};
    quickSort(a,0,a.size()-1);
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<"\t";
    }
}