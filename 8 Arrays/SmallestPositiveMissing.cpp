#include<bits/stdc++.h>
using namespace std;

int FirstMissingPos(int A[],int n)
{   
    //to mark the occurance of the elements
    bool present[n+1] = {false};

    //mark the occurance
    for(int i=0;i<n;i++)
    {
        //only mark the required elements
        //all non positive element and elements greater than n+1
        //can never be the answer
        //for example for{1,2,3} only 4 can be the answer
        if(A[i]>0 && A[i]<=n)
        {
            present[A[i]]=true;
        }
    }

    //Find the first element which didn't appear in the original array
    for(int i=1;i<=n;i++)
    {
        if(!present[i])
        {
            return i;
        }
    }

    //if the first element was the sort of type
    //{1,2,3}then the answer is n+1
    return n+1;
}

int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i=0;i<n;i++){cin>>arr[i];}

    cout<<FirstMissingPos(arr,n);
    return 0;
}