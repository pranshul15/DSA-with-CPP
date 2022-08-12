#include<bits/stdc++.h>
using namespace std;

void swap(int a,int b){
    int var=b;
    b=a;
    a=var;
}

int main(){
    int n;
    cin>>n;
    int mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
    return 0;
}