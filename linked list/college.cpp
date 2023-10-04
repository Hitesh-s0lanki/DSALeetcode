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
    ~ListNode(){
        cout<<"Free all Memory"<<endl;
    }
};

void insertAtTail(ListNode* &head,ListNode* &tail,int data){
    ListNode* temp = new ListNode(data);
    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    tail -> next = temp;
    tail = temp;
}

void insertAtHead(ListNode* &head,ListNode* &tail,int data){
    ListNode* temp = new ListNode(data);
    if(head == NULL) {
        head = temp;
        tail = temp;
        return;
    }
    temp -> next = head;
    head = temp;
}

void print(ListNode* head){
    while(head != NULL){
        cout<<head -> val<<"\t";
        head = head -> next;
    }
    cout<<endl;
}

ListNode* deleteNode(ListNode* head,int data){
    if(head == NULL){
        return head;
    }
    ListNode* ptr1 = NULL; 
    ListNode* ptr2 = head; 

    while(ptr2 -> next!= NULL && ptr2 -> val != data){
        ptr1 = ptr2;
        ptr2 = ptr2 -> next;
    }

    if(ptr2 -> val == data){
        if(ptr1 == NULL)
            return head -> next;
        ptr1 -> next = ptr2 -> next;
    }

    return head;
}

int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);

    head = deleteNode(head,3);

    print(head);
}