#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    int i;
    int j;
    node(int data,int row,int col){
        this->data = data;
        this->i=row;
        this->j=col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k){
    
    priority_queue<node* ,vector<node*> , compare> minheap;

    for(int i=0;i<k;i++){
        node* tmp = new node(kArrays[i][0],i,0);
        minheap.push(tmp);
    }
    
    vector<int> ans;

    while(!minheap.empty()){
        node* temp = minheap.top();

        ans.push_back(temp->data);
        minheap.pop();
        int i = temp->i; 
        int j = temp->j;

        if(j+1 < kArrays[i].size()){
            node* next = new node(kArrays[i][j+1],i,j+1);
            minheap.push(next);
        } 
    }
    return ans;
}
int main(){
    vector<vector<int>> kArrays = {{3,5,9},{1,2,3,8}};
    vector<int> ans=mergeKSortedArrays(kArrays,2);
    for(auto i : ans){
        cout<<i<<"\t";
    }
}