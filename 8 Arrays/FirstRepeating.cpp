#include<bits/stdc++.h>
using namespace std;

int FirstRepeatingElement(int arr[],int n)
{
    int N=n+1;
    int idx[N];
    for(int i=0;i<N;i++)
    {
        idx[i]=-1;
    }
    int minidx = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(idx[arr[i]] != -1)
        {
            minidx = min(minidx, idx[arr[i]]);
        }
        else
        {
            idx[arr[i]]=i;
        }
    }

    if(minidx==INT_MAX){return -1;}
    
    else{return minidx +1;}
}

int main(){
    int n;
    cin>> n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}

    cout<<FirstRepeatingElement(arr,n);

    return 0;
}