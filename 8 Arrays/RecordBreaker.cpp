#include<bits//stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}
    
    int curr=0;
    int var=arr[0];
    if(arr[0]>arr[1])
    {
        curr++;
    }
   
    for(int j=1;j<n-1;j++)
    {
        if(arr[j]>var && arr[j]>arr[j+1])
        {
            curr++;
        }
        var = max(var, arr[j]);
    }

    if(arr[n-1]>var)
    {
        curr++;
    }

    cout << curr;

    return 0;
}