#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node* prev;
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};
class doublyLL{
    public:
    node* head;
    node*tail;

    doublyLL(){
        head=NULL;
        tail=NULL;
    }
    void insertAtStart(int data){
        node* new_node=new node(data);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }

        new_node->next=head;
        head->prev=new_node;
        head=new_node;
        return;
    }
    void insertAtTail(int data){
        node* new_node=new node(data);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
        return;
        
    }
    void insertAtPos(int data,int pos){
        node* new_node=new node(data);
        node* temp=head;
        int counter=0;
        while(counter==pos-1){
            temp=temp->next;
            counter++;
        }
        new_node->next=temp->next;
        new_node->next->prev=new_node;
        new_node->prev=temp;
        temp->next=new_node;
        return;
    }
    void deleteAtStart( ){
        if(head==NULL){
            return;
        }
        node* temp=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }else{
        head->prev=NULL;
        }
        free(temp);
    }
    void deleteAtTail(){
        if(head==NULL){
            return;
        }
        node* temp=tail;
        tail=tail->prev;
        if (tail==NULL){
            head=NULL;
        }else{
        tail->next=NULL;
        }
        free(temp);
    }
    void deleteAtPos(int pos){
        node* temp=head;
        int counter=1;
        while(counter!=pos){
            temp=temp->next;
            counter++;
        }
        //temp at node to be deleted
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return;
    }
    void display( ){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
        return;
    }


};
int main(){
    doublyLL dll;
    dll.insertAtStart(56);
    dll.insertAtStart(23);
    dll.insertAtStart(89);
    dll.display();
    dll.insertAtTail(77);
    dll.insertAtTail(12);
    dll.display();
    dll.insertAtPos(63,2);
    dll.display();
    dll.deleteAtStart( );
    dll.display();
    dll.deleteAtTail();
    dll.display();
    dll.deleteAtPos(2);
    dll.display();
    return 0;
}