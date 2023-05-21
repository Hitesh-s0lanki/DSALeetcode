#include <iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

class node{
    public:
    int data;
    int row;
    int col;
    node(int data,int row,int col){
        this->data = data;
        this->row = row;
        this->col = col;
    }
};

class compare{
    public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

vector<int> smallestRange(vector<vector<int>>& nums) {

        int mini=INT_MAX,maxi=INT_MIN;
        priority_queue<node* ,vector<node*> , compare> minheap;
        int k = nums.size();
        //load the data
        for(int i=0;i<k;i++){
            minheap.push(new node(nums[i][0],i,0));
            mini = min(mini,nums[i][0]);
            maxi = max(maxi,nums[i][0]);
        }

        int start = mini, end = maxi;

        while(!minheap.empty()){

            node* temp = minheap.top();
            minheap.pop();
            mini = temp->data;

            if(maxi - mini < end - start){
                start = mini;
                end = maxi;
            }

            if(temp -> col + 1 < nums[temp->row].size()){
                cout<<nums[temp->row][temp->col+1]<<endl;
                minheap.push(new node(nums[temp->row][temp->col+1],temp->row,temp->col+1));
                maxi = max(maxi,nums[temp->row][temp->col+1]);
            }
            else{
                break;
            }
        }
        return {start,end};
    }
int main(){
    // [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    vector<vector<int>> nums={{4,10,15,24,26},{0,9,12,20},{5,18,22,30}};

    vector<int> ans=smallestRange(nums);
    for(auto i:ans)
        cout<<i<<"\t";
}