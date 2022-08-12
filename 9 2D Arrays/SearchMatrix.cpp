#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
/*  Brute force
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j]==k){
                cout<<"ElementFound";
                break;
            }
        }
    }
*/   

//matrix is sorted from both ends
    int a=0,b=n-1;
    while(b>=0 && a<n){
        if(mat[a][b]==k){
            cout<<a<<" "<<b<<endl<<"Element found";
            break;
        }
        else if(mat[a][b]>k){
            b--;
        }
        else{
            a++;
        }
    }

    return 0;
}