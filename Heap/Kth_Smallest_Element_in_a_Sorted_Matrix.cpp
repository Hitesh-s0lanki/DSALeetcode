#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//Solve karnu hai
class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int row,int col){
        this->data=data;
        this->row=row;
        this->col=col;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};
int kthSmallest(vector<vector<int>>& matrix, int k) {
    priority_queue<node*,vector<node*> ,compare> minheap;
    int row = matrix.size();
    int col = matrix[0].size();
    for(int i=0;i<row;i++){
        minheap.push(new node(matrix[i][0],i,0));
    }
    int ans;
    while(k){
        node* temp = minheap.top();
        minheap.pop();
        ans=temp->data;
        int i = temp->row;
        int j = temp->col;

        if(j+1 < col ){
            node * tmp = new node(matrix[i][j+1],i,j+1);
            minheap.push(tmp);
        }
        k--;
    }
    return ans;
}
int main(){
    vector<vector<int>> mat={{1,2},{1,3}};
    cout<<kthSmallest(mat,1);
}