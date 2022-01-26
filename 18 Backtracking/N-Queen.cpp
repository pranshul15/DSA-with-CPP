#include<iostream>
using namespace std;

bool column(int **arr,int n,int i,int j){
    while(j>0){
        if(arr[i][j]==1){
            return true;
        }
        j--;
    }
    return false;
}
bool left_diagonal(int **arr,int n,int i,int j){
    while(i>0 and j>0){
        if(arr[i][j]==1){
            return true;
        }
    }
    return false;
}
bool right_diagonal(int **arr,int n,int i,int j){
    while(i<n and j>0){
        if(arr[i][j]==1){
            return true;
        }
    }
    return false;
}
//current position is safe or not
bool safe (int**arr,int n,int i,int j){              
    if(column(arr,n,i,j)){
        return false;
    }
    if(left_diagonal(arr,n,i,j)){
        return false;
    }
    if(right_diagonal(arr,n,i,j)){
        return false;
    }
    return true;
}

void NQueen (int**arr, int n,int i,int j){
    if(safe(arr,n,i,j)){
        arr[i][j]=1;
    }
    else{
        NQueen(arr,n,i+1,j);
    }
    
}

int main(){
    int n;
    cin>>n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i]= new int[n];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            arr[i][j]=0;
        }
    }
    NQueen(arr,n,0,0);
    
    return 0;
}