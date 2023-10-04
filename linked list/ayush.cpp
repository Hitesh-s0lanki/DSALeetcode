#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        int value=this->data;
        while(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"the value which is deleted is "<<value<<endl;
    }
};

void insertAtHead(Node* &head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        temp->next=head;
        head=temp;
    }
}

void insertAtTail(Node*&head,Node* &tail,int data){
    Node* temp=new Node(data);
    if(head==NULL){
        head=temp;
        tail=temp;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

void insertAtPostion(Node*&head,Node* &tail,int data){
    cout<<"Enter the position : "<<endl;
    int pos;
    cin>>pos;
    //for postion ==1 that is for head
    if(pos==1){
        insertAtHead(head,tail,data);
        return;
    }
    //reaching for postion 
    Node* temp=head;
    int count=1;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    //last node then insert after last
    if(temp->next==NULL){
        insertAtTail(head,tail,data);
        return;
    }
    //for that position
    Node*nodeToInsert=new Node(data);
    nodeToInsert->next=temp->next;
    temp->next=nodeToInsert;
}

void deleteNode(Node* &head,Node* &tail,int val){
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
    Node* ptr=head;
    Node* ptr2=head->next;
    while(ptr2->data!=val && ptr2!=NULL){
        ptr=ptr->next;
        ptr2=ptr2->next;
    }
    if(ptr2==NULL&& ptr2->data!=val){
        cout<<"No deletion is possible"<<endl;
    }
    //update tail here
    else if(ptr2->next==NULL && ptr2->data==val){
        ptr->next=ptr2->next;
        tail=ptr;
        ptr->next =NULL;
        delete ptr2;
    }
    //any middle node
    else{
        ptr->next=ptr2->next;
        ptr2->next=NULL;
        delete ptr2;
    } 
    }
}

void print(Node*& head){
    cout<<"Linked List : ";
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

bool search(Node*&head,int val){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==val){
            return true;
        }
        else{
            temp=temp->next;
        }
    }
    return false;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    int val;
    bool play = true;
    while(play){
        cout<<"Choose 1"<<endl;
        cout<<"0 to quit"<<endl;
        cout<<"1 for insertion At head of Linked List"<<endl;
        cout<<"2 for insertion At end of Linked List"<<endl;
        cout<<"3 for insertion At particular position of Linked List"<<endl;
        cout<<"4 for Print of Linked List"<<endl;
        cout<<"5 for deletion of node of Linked List"<<endl;
        cout<<"6 for Searching of node of Linked List"<<endl;
        int num,data;
        cin>>num;
        if(num == 1||num == 2 || num == 3){
            cout<<"Enter the data : ";
            cin>>data;
        }
        switch (num){
        case 0:
            play = false;
        break;
        case 1:
            insertAtHead(head,tail,data);
        break;
        case 2:
            insertAtTail(head,tail,data);
        break;
        case 3:
            insertAtPostion(head,tail,data);
        break;
        case 4:
            print(head);
        break;
        case 5:
            cout<<"Enter the value of node to be deleted : "<<endl;
            cin>>val;
            deleteNode(head,tail,val);
        break;
        case 6:
            cout<<"Enter the value of node to be search : "<<endl;
            cin>>val;
            search(head,val);
        break;
        default:
            cout<<"Choose from above option";
        }
    }

    return 0;
}