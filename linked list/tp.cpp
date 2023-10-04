#include<iostream>
using namespace std;

class ListNode {
    public:
    int val;
    ListNode* next;
    ListNode(int val){
        this -> val = val;
        this -> next = NULL;
    }
};

void insertAtTail(ListNode* &head,ListNode* &tail,int data){
    ListNode* temp = new ListNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
    } else {
        tail -> next = temp;
        tail = temp;
    }
    tail -> next = head;
}

void insertAtHead(ListNode* &head,ListNode* &tail,int data){
    ListNode* temp = new ListNode(data);
    if(head == NULL){
        head = temp;
        tail = temp;
    } else {
        temp -> next = head;
        head = temp;
    }
    tail -> next = head;
}

int length(ListNode* head){
    if(head == NULL)
        return 0;
    
    int count = 1;
    ListNode* ptr = head -> next;
    while(ptr != head){
        count++;
        ptr = ptr -> next;
    }
    return count;
}

void insertAtParticularPosition(ListNode* &head,ListNode* &tail,int position,int data){
    if(position == 1){
        insertAtHead(head,tail,data);
    } else if(position == length(head) + 1){
        insertAtTail(head,tail,data);
    } else if(position < length(head) + 1 && position > 1){
        ListNode* temp = new ListNode(data);
        ListNode* ptr = head;
        while(position != 2){
            ptr = ptr -> next;
            position -- ;
        }
        temp -> next = ptr -> next;
        ptr -> next = temp;
    }
}

void searchNode(ListNode* head,int data){
    if(head != NULL){

        ListNode* ptr = head -> next;

        while(ptr != head && ptr -> val != data)
            ptr = ptr -> next;

        if(head -> val == data || ptr != head){
            cout<<"Found the data"<<endl;
            return;
        }
    }
    cout<<"Not found"<<endl;
}

ListNode* deleteNodeHead(ListNode* head){
    if(head == NULL || head -> next == head)
        return NULL;

    ListNode* ptr = head -> next;
    while(ptr -> next != head){
        ptr = ptr -> next;
    }
    head = head -> next;
    ptr -> next = head;

    return head;
}

ListNode* deleteNodeTail(ListNode* head){
    if(head == NULL || head -> next == head)
        return NULL;

    ListNode* ptr1 = NULL;
    ListNode* ptr2 = head;
    while(ptr2 -> next != head){
        ptr1 = ptr2;
        ptr2 = ptr2 -> next;
    }

    ptr1 -> next = ptr2 -> next;

    return head;
}

ListNode* deleteParticularNode(ListNode* head,int data){
    if(head == NULL || (head -> val == data && head -> next == head))
        return NULL;

    if(head -> val == data)
        return deleteNodeHead(head);

    ListNode* ptr1 = head;
    ListNode* ptr2 = head -> next;

    while(ptr2 != head && ptr2 -> val != data){
        ptr1 = ptr2;
        ptr2 = ptr2 -> next;
    }

    if(ptr2 -> next == head){
        return deleteNodeTail(head);
    }
    if(ptr2 != head){
        ptr1 -> next = ptr2 -> next;
    }

    return head;
    
}

void print(ListNode* head){
    if(head == NULL){
        cout<<"Linked List is Empty"<<endl;
        return;
    }
    
    ListNode* ptr = head -> next;
    cout<<head -> val<<"\t";

    while(ptr != head){
        cout<<ptr -> val << "\t";
        ptr = ptr -> next;
    }
    cout<<endl;
}

int main(){
    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertAtTail(head,tail,1);
    insertAtTail(head,tail,2);
    insertAtTail(head,tail,3);
    insertAtTail(head,tail,4);
    print(head);
    insertAtParticularPosition(head,tail,3,10);
    print(head);
    head = deleteNodeHead(head);
    print(head); 
    head = deleteNodeTail(head);
    print(head); 
    head = deleteParticularNode(head,10);
    print(head);
    searchNode(head,10);
}