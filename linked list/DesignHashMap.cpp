#include<iostream>
using namespace std;
class ListNode{
    public:
    int key;
    int val;
    ListNode* next;
    ListNode(int key,int val){
        this->key = key;
        this->val = val;
        this->next = NULL;
    }
};
void insertAtTail(ListNode* &head,ListNode* &tail,int key,int val){
    ListNode* temp = new ListNode(key,val);
    if(head == NULL){
        head = temp;
        tail = temp;
        return;
    }
    tail -> next = temp;
    tail = temp;
}
class MyHashMap {
public:
    ListNode* head = NULL;
    ListNode* tail = NULL;
    MyHashMap() {
        this -> head = NULL;
        this -> tail = NULL;
    }
    
    void put(int key, int value) {
        insertAtTail(head,tail,key,value);
    }
    
    int get(int key) {
        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> key == key){
                return temp -> val;
            }
            temp = temp -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        if(head -> key == key){
            if(tail == head){
                tail = NULL;
            }
            head = head -> next;
        }
        else {
            ListNode* prev = NULL;
            ListNode* curr = head;
            while(curr != NULL){
                if(curr -> key == key){
                    prev -> next = curr -> next;
                    return;
                }
                prev = curr;
                curr = curr -> next;
            }
        }
    }
};
int main(){

}