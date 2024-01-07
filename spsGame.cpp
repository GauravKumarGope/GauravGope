#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;

//get comp moves
string getcompmove(){
    int move;
    srand(time(NULL));
    move=rand()%3;
    //returning move
    if(move==0){
        return "paper";
    }
    else if(move==1){
        return "rock";
    }
    return "scissor";
}

//func. to return result
int getresult(string playermove,string compmove){
    //condition to draw
    if(playermove==compmove){
        return 0;
    }
    //condition to win
    if(playermove=="rock" && compmove=="paper"){
        return -1;
    }
    else if(playermove=="rock" && compmove=="scissor"){
        return 1;
    }

    if (playermove=="paper" && compmove=="rock"){
        return 1;
    }
    else if(playermove=="paper" && compmove=="scissor"){
        return -1;
    }
    if (playermove=="scissor" && compmove=="paper"){
        return 1;
    }
    else if(playermove=="scissor" && compmove=="rock"){
        return -1;
    }
    return 0;
}

//Driver code
int main(){
    string playermove;
    string compmove;
    int result;
    char ans;
    do{
        cout<<"  Welcome to Stone paper scissor Game"<<endl;
        cout<<" Enter your move "<<endl<<"i.e 1.rock"<<endl<<"    2.paper"<<endl<<"    3.scissor"<<endl;
        cin>>playermove;
        
        //getcomp move
        compmove= getcompmove();
        cout<<"compmove="<<compmove<<endl;

        //getting result

        if(playermove=="rock"||playermove=="paper"||playermove=="scissor"){
            break;
        }
        else{
            cout<<"invalid input";
            break;
        }

        result=getresult(playermove,compmove);

        if(result==0){
            cout<<"Its a Draw"<<endl;
        }
        else if(result==1){
            cout<<"You Won"<<endl;
        }
        else {
            cout<<"You Lost"<<endl;
        }

        cout<<"do you wanna continue (y/n)";
        cin>>ans;        
    }while(ans=='y');

    return 0;
    
}