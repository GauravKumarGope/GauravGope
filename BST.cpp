#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    //constructor
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* insertIntoBST(node* root,int data){
    //base case
    if (root==NULL){
        root=new node(data);
        return root;
    }
    if(data>root->data){
        //big num goes to right
        root->right=insertIntoBST(root->right,data);
    }
    else{
        //small num goes to left
        root->left=insertIntoBST(root->left,data);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin >> data;

    while(data !=-1){
        root= insertIntoBST(root,data);
        cin>>data;
    }
}

bool searchIntoBST(node* root,int x){
    node* temp=root;
    while(temp !=NULL){
        if(temp->data==x){
            return true;
        }
        if(temp->data>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}

node* minval(node* root){
    node* temp =root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node* maxval(node* root){
    node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node* deleteFromBST(node* &root,int x){
    if(root==NULL){
        return root;
    }

    if(root->data == x){
        // 0 child
        if(root->left==NULL && root->right==NULL){
        delete root;
        return NULL;
    }

        // 1 child
        
        //left child
        if(root->left!=NULL && root->right ==NULL){
            node* temp =root->left;
            delete root;
            return temp;
        }

        //right child
        if(root->left==NULL && root->right !=NULL){
            node* temp=root->right;
            delete root;
            return temp;
        }

        // 2 child
        if(root->left !=NULL && root->right!=NULL){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    else if(root->data > x){
        //left pe jao
        root->left =deleteFromBST(root->left,x);
        return root;
        }
    else{
        root->right =deleteFromBST(root->right,x);
        return root;
        }
    }
}

void preorder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    node* root=NULL;

    cout<<"Enter the data to create bst"<<endl;
    takeInput(root);
    cout<<"displaying tree"<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Min value is:"<<minval(root)->data<<endl;
    cout<<"Max value is:"<<maxval(root)->data<<endl;
    deleteFromBST(root,12);
    preorder(root);

    /*bool x=searchIntoBST(root,23);
    if(x==true){
        cout<<endl<<"its their"<<endl;
    }else{
        cout<<endl<<"its not their"<<endl;
    }*/

    
    return 0;
}