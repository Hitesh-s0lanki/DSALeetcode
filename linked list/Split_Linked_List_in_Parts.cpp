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
void insertAtTail(ListNode* &head,ListNode* &tail,int val){
    ListNode* temp=new ListNode(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    tail->next=temp;
    tail=temp;
}
void print(ListNode* head){
    while(head!=NULL){
        cout<<head->val<<"\t";
        head=head->next;
    }
    cout<<endl;
}
int lengthList(ListNode* head){
    int cnt=0;
    while(head!=NULL){
        head=head->next;
        cnt++;
    }
    return cnt;
}
vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length=lengthList(head);
        int div=length/k;
        int rem=length%k;
        vector<int> NumberStore;
        int i=0;
        while(i<k){
            if(rem>0){
               NumberStore.push_back(div+1);
               rem--;
            }
            else{
              NumberStore.push_back(div);
            }
            i++;
        }
        vector<ListNode*> ans;
        ListNode* curr=head;
        ListNode* store=head;
        for(int i=0;i<NumberStore.size();i++){
            curr=store;
            ans.push_back(curr);
            if(curr!=NULL){
                while(curr!=NULL&&NumberStore[i]){
                if(NumberStore[i]!=1)
                curr=curr->next;
                if(curr!=NULL)
                store=curr->next;
                else
                store=curr;
                NumberStore[i]--;
                }
                if(curr!=NULL)
                curr->next=NULL;
            }
        }
        return ans;
    }
int main(){
    ListNode* head=NULL;
    ListNode* tail=NULL;
    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    print(head);
    int k=5;
    // [[1],[2],[3],[],[]]
    splitListToParts(head,k);
}