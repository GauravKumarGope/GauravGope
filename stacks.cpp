#include<iostream>
using namespace std;
class stacks{
    //properties
    public:
    int *arr;
    int top;
    int size;

    //behaviour
    stacks(int size){
        this->size=size;
        arr=new int(size);
        top=-1;

    }

    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflowing"<<endl;
        }
    }

    void peek(){
        cout<<arr[top]<<endl;
    }
};
int main(){
    stacks stack(5);
    stack.push(43);
    stack.peek();
    stack.push(98);
    stack.peek();
    stack.push(21);
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.peek();
    stack.pop();
    stack.pop();
    if(stack.isEmpty()){
        cout<<"Stack is empty";
    }
    else{
        cout<<"Stack is not empty";
    }
    return 0;
}