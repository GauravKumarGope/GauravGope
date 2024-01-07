#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    
    //constructor
    node(int data){
        this->data=data;
        this->next=NULL;
    }
    //destructor
    ~node(){
        int value = this->data;
        if (this->next !=NULL){
            delete next;
            next=NULL;
        }
        cout<<"Memory is free for node with data"<<value<<endl;
    }
};

void insertNode(node* &tail,int element,int data){
       //case 1 - empty list
       if(tail==NULL){
        node* newNode=new node(data);
        tail=newNode;
        newNode->next=newNode;
       }
       else{
        //non empty list
        node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        node* temp=new node(data);
        temp->next=curr->next;
        curr->next=temp;
       }
}

void print(node* tail){
    
    node* temp=tail;
    
    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail !=temp);
    cout<<endl;

}

int main(){
    node* tail=NULL;
    insertNode(tail,5,1);
    insertNode(tail,1,2);
    insertNode(tail,2,3);
    insertNode(tail,3,4);
    insertNode(tail,4,5);
    print(tail);
    return 0;
}