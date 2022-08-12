#include<iostream>
#include<ctime>
using namespace std;

int main(){
    string deck[4][13];
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            cin>>deck[i][j];
        }
    }
    srand(time(0));
    //shuffling all the rows
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            int x1=rand()%13;
            int x2=rand()%13;
            string temp=deck[i][x1];
            deck[i][x1]=deck[i][x2];
            deck[i][x2]=temp;
        }
    }
    //shuffling all the columns
    for(int j=0;j<13;j++){
        for(int i=0;i<3;i++){
            int x1=rand()%4;
            int x2=rand()%4;
            string temp=deck[x1][j];
            deck[x1][j]=deck[x2][j];
            deck[x2][j]=temp;
        }
    }
    cout<<"output:"<<endl;
    for(int i=0;i<4;i++){
        for(int j=0;j<13;j++){
            cout<<deck[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}