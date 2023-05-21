#include<iostream>
#include<vector>
using namespace std;

void heapify(vector<int> &ans,int n,int i){
    int index=i;
    int leftIndex = 2*i + 1;
    int rightIndex = 2*i + 2;

    if(leftIndex < n && ans[index] < ans[leftIndex])
        index = leftIndex;
    if(rightIndex < n && ans[index] < ans[rightIndex])
        index = rightIndex;

    if(index != i){
        swap(ans[index],ans[i]);
        heapify(ans,n,index);
    }
}

vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
    //merge 2 Array
    vector<int> ans;
    for(auto i:a)
        ans.push_back(i);
    for(auto i:b)
        ans.push_back(i);
    for(int i=ans.size()/2 - 1 ; i >= 0 ; i-- )
        heapify(ans,ans.size(),i);

    return ans;
}
int main(){
    vector<int> a={10, 5, 6, 2};
    vector<int> b={12, 7, 9};

    vector<int> ans = mergeHeaps(a,b,a.size(),b.size());

    for(auto i: ans){
        cout<<i<<"\t";
    }
}