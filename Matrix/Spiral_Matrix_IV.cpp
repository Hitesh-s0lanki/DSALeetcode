#include<iostream>
#include<vector>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};
void print(ListNode* head){
    ListNode* temp=head;
    while(temp != NULL){
        cout<<temp->val<<"\t";
        temp=temp->next;
    }
    cout<<endl;
}
void insertAtTail(ListNode* &head,ListNode* &tail,int val){
    ListNode* temp = new ListNode(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}

vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
    vector<vector<int>> matrix;
    for(int i=0;i<m;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            temp.push_back(0);
        }
        matrix.push_back(temp);
    }
        int startrow=0;
        int startcol=0;
        int endrow=m-1;
        int endcol=n-1;
        
        int count=0;
        int total=n*m;
        while(count<total){
            
            //for first row
            for(int index=startcol;count<total&&index<=endcol;index++){
                if(head != NULL){
                    matrix[startrow][index] = head->val;
                    head = head->next;
                }
                else
                    matrix[startrow][index] = -1;
                count++;
            }
            startrow++;
            
            //for last column
            for(int index=startrow;count<total&&index<=endrow;index++){
                if(head != NULL){
                    matrix[index][endcol] = head->val;
                    head = head->next;
                }
                else
                    matrix[index][endcol] = -1;
                count++;
            }
            endcol--;
            
            //for last row
            for(int index=endcol;count<total&&index>=startcol;index--){
                if(head != NULL){
                    matrix[endrow][index] = head->val;
                    head = head->next;  
                }
                else
                    matrix[endrow][index] = -1;
                count++;
            }
            endrow--;
            
            //for first column
            for(int index=endrow;count<total&&index>=startrow;index--){
                if(head != NULL){
                    matrix[index][startcol] = head->val;
                    head = head->next;
                }
                else
                    matrix[index][startcol] = -1;
                count++;
            }
             startcol++;
            
            
        }
        return matrix;
}
int main(){
    vector<int> val={3,0,2,6,8,1,7,9,4,2,5,5,0};
    ListNode* head=NULL;
    ListNode* tail=NULL;
    for(auto i:val)
        insertAtTail(head,tail,i);

    vector<vector<int>> ans= spiralMatrix(3,5,head);
    for(auto i:ans){
        for(auto j:i){
            cout<<j<<"\t";
        }
        cout<<endl;
    }
}