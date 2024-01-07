#include<iostream>
using namespace std;
class node{  //creating a node
    public:
    int data;
    node* next;

    node(int data){
        this->data=data;
        this->next=NULL;
    }
};
    void insertAtHead(node* &head,int data){   //inserting node at head   // here(node* &head is pointer to pointer to make changes in it)
        node* new_node=new node(data);  //dynamic allocating and creating new node 
       // new_node->data=data;        //new node data=data given
        new_node->next=head;        //new node head=head given
        head=new_node;   
    }
    void insertAtTail(node* &head,int data){
        node* new_node=new node(data);
        node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void insertAtPos(node*head,int data,int pos){
        if(pos==0){
            insertAtHead(head,data);
        }
        node* new_node=new node(data);
        node* temp=head;
        int current_pos=0;
        while(current_pos!=pos-1){
            temp=temp->next;
            current_pos++;
        }
        new_node->next=temp->next;
        temp->next=new_node;
    }
    void updating(node* &head,int data,int pos){
        node* temp=head;
        int curr_pos=0;
        while(curr_pos!=pos){
            temp=temp->next;
            curr_pos++;
        }
        temp->data=data;
    }
    void deleteAtHead(node* &head){
        node* temp=head;
        head=head->next;
        free(temp);
    }
    void deleteAtTail(node* &head){
        node* sec_Last=head;
        while(sec_Last->next->next!=NULL){
            sec_Last=sec_Last->next;
        }
        node* temp=sec_Last->next;
        sec_Last->next=NULL;
        free(temp);
    }
    void deleteAtPos(node* &head,int pos){
        node*prev=head;
        int curr_pos=0;
        while(curr_pos!=pos-1){
            prev=prev->next;
            curr_pos++;
        }
        node* temp=prev->next;
        prev->next=temp->next;
        free(temp);
    }
    void display(node* head){  // displaying (here we just passing the head as no changes needed)
        node* temp;                   
        for(temp=head;temp!=NULL;temp=temp->next){  //creating temp = head so that we use temp for traversal without changing head
            cout<<temp->data<<"->";
        }
        cout<<"NULL"<<endl;
    }

    int main(){
        node* head=NULL;
        insertAtHead(head,90);
        insertAtHead(head,53);
        display(head);
        insertAtTail(head,32);
        display(head);
        insertAtPos(head,21,2);
        display(head);
        updating(head,23,2);
        display(head);
        /*deleteAtHead(head);
        display(head);
        deleteAtTail(head);
        display(head);*/
        deleteAtPos(head,2);
        display(head);
        return 0;
    }
