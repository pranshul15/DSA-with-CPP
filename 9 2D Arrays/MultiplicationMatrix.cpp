#include<bits/stdc++.h>
using namespace std;

int main(){
    int n1,n2,n3;
    cin>>n1>>n2>>n3;
    int mat1[n1][n2] , mat2[n2][n3] ;
    cout<<"Enter elements of first matrix"<<endl;
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            cin>>mat1[i][j];
        }
    }
    cout<<"Enter elements of second matrix"<<endl;
    for(int i=0;i<n2;i++){
        for(int j=0;j<n3;j++){
            cin>>mat2[i][j];
        }
    }

    int ans[n1][n3];
    int sum;

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            sum=0;
            for(int k=0;k<n2;k++){
                sum+=(mat1[i][k]*mat2[k][j]);
            }
            ans[i][j]=sum;
        }
    }

    for(int i=0;i<n1;i++){
        for(int j=0;j<n3;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}