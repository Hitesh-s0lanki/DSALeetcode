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

class List{
    ListNode* head;
    ListNode* tail;
    public:
    List(){
        head = NULL;
        tail = NULL;
    }
    void print(){
        ListNode* ptr = head;
        while(ptr != NULL){
            cout<<ptr -> val<<"\t";
            ptr = ptr -> next;
        }
        cout<<endl;
    }
    void insertAtEnd(int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
        }else{
            tail -> next = temp;
        }
        tail = temp;
    }
    void insertAtHead(int val){
        ListNode* temp = new ListNode(val);
        if(head == NULL){
            head = temp;
        }else{
            temp -> next = head;
        }
        head = temp;
    }
    void search(int val){
        ListNode* ptr = head;
        while(ptr != NULL && ptr -> val != val){
            ptr = ptr -> next;
        }
        if(ptr != NULL){
            cout<<"Found the Data"<<endl;
        }else {
            cout<<"Data Not Found"<<endl;
        }
    }
    void deleteAtEnd(){
        if(head != NULL){
            ListNode* ptr = head;
            while(ptr != NULL && ptr != tail && ptr-> next != tail){
                ptr = ptr -> next;
            }
            if(ptr != NULL){
                if(ptr == head){
                    head = tail = NULL;
                }else{
                    ptr -> next = NULL;
                }
            }
        }
    }
};


int main(){
    bool quit = false;
    string arr[] = {"Insert at End Data by Entering 1","Print List by Entering 2","Delete Data by Entering 3","Insert Data at start enter 4","Quit 5"};
    List list;
    int val;
    while(!quit){
        for(int i = 0; i< 5;i++){
            cout<<arr[i]<<endl;
        }
        int data;
        cin>>data;
        switch (data){
            case 1:
                cout<<"Enter the Value : ";
                cin>>val;
                list.insertAtEnd(val);
            break;
            case 2:
                list.print();
            break;
            case 3:
                list.deleteAtEnd();
            break;
            case 4:
                cout<<"Enter the Value : ";
                cin>>val;
                list.insertAtHead(val);
            break;
            case 5:
                quit = true;
            break;
            default:
                cout<<"Nikal Abhey";
        }
        cout<<endl;
    }
}