#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }
};

class operation{
    public:

    void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
        }else{
            tail -> next =  temp;
        }
        tail = temp;
        tail -> next = head;
    }

    void insertAtHead(ListNode* &head, ListNode* &tail, int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            tail = temp;
        }else{
            temp -> next =  head;
        }
        head = temp;
        tail -> next = temp;
    }

    int length(ListNode* head){
        if(head == 0) return 0; 
        int cnt = 1;
        ListNode* ptr = head -> next;
        while(ptr != head){
            cnt++;
            ptr = ptr -> next;
        }
        return cnt;
    }

    void insertAtParticularPosition(ListNode* &head, ListNode* &tail,int val,int pos){
        if(pos == 1){
            insertAtHead(head, tail, val);
        }else if(pos == length(head)){
            insertAtTail(head, tail, val);
        }else{
            ListNode* ptr = head;
            while(pos != 2){
                ptr = ptr -> next;
                pos--;
            }
            ListNode* temp = new ListNode(val);
            temp -> next = ptr -> next;
            ptr -> next = temp;
        }
    }

    void print(ListNode* head){
        if(head == NULL) return;
        cout<<head -> val<<"\t";
        ListNode* ptr = head -> next;
        while(ptr != head){
            cout<<ptr -> val << "\t";
            ptr = ptr -> next;
        }
        cout<<endl;
    }
};

int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    operation o;

    o.insertAtHead(head, tail, 1);
    o.insertAtHead(head, tail, 2);
    o.insertAtHead(head, tail, 3);
    o.insertAtHead(head, tail, 4);
    o.insertAtTail(head, tail, 5);
    o.insertAtParticularPosition(head, tail, 0, 3);
    o.print(head);
}