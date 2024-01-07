#include<iostream>
#include<stack>
using namespace std;
int main(){

    stack<int> s;
    s.push(83);
    s.push(21);
    s.push(13);
    s.push(42);
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;
    s.pop();
    s.pop();
    cout<<s.size()<<endl;
    cout<<s.top()<<endl;



    return 0;
}