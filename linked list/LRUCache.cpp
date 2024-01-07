#include<iostream>
using namespace std;
class Node{
    int key;
    int value;
    int used;
    Node* next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

}
class LRUCache {
    int capacity;
    public:
        LRUCache(int capacity) {
            this->capacity = capacity;
        }
        
        int get(int key) {
            
        }
        
        void put(int key, int value) {
            
        }
};
int main(){

}