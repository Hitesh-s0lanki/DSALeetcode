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

void insertAtTail(ListNode* &head,ListNode* &tail, int val){
    ListNode* temp = new ListNode(val);
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        tail -> next = temp;
        tail = temp;
    }
    tail -> next = head;
}

void insertAtHead(ListNode* &head,ListNode* &tail, int val){
    ListNode* temp = new ListNode(val);
    if(head == NULL){
        head = temp;
        tail = temp;
    }else{
        temp -> next = head;
        head = temp;
    }
    tail -> next = head;
}

void print(ListNode* head){
    if(head != NULL){
        cout<<head -> val<<"\t";
        ListNode* ptr = head -> next;
        while(ptr != head){
            cout<<ptr -> val<<"\t";
            ptr = ptr -> next;
        }
        cout<<endl; 
    }else{
        cout<<"Linked list is Empty"<<endl;
    }
}

int main(){

    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 3);
    insertAtTail(head, tail, 4);
    insertAtHead(head, tail, 0);

    print(head);
}