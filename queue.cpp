#include<iostream>
using namespace std;
class queue{
    public:
    int *arr;
    int qfront;
    int rear;
    int size;
    
    //constructor
    queue(){
        size=1001;
        arr=new int(size);
        qfront=0;
        rear=0;
    }

    void enqueue(int data){
        if(rear==size){
            cout<<"queue is full"<<endl;
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue(){
        if(qfront==rear){
            cout<<"queue is empty"<<endl;
            return -1;
        }
        else
        {
            int ans=arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
        return ans;
        }
    }

    void front(){
        if(qfront==rear){
            cout<<"it's empty"<<endl;
        }
        else{
            cout<<arr[qfront]<<endl;
        }
    }

    bool isEmpty(){
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }
};
int main(){
    queue q;
    if(q.isEmpty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
    q.enqueue(143);
    q.front();
    q.enqueue(8005);
    q.enqueue(666);
    q.dequeue();
    q.front();
    if(q.isEmpty()){
        cout<<"queue is empty"<<endl;
    }
    else{
        cout<<"queue is not empty"<<endl;
    }
    return 0;
}