/*
You are given an array. Your task is to find the maximum sum of subarray which can
be found using the above array.
*/ 
#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin>>a[i];

    int curr = 0;
    int maxTillNow = 0;

    for(int i=0;i<n;i++){
        curr += a[i];
        maxTillNow = max(curr,maxTillNow);
        if(curr<0)
            curr = 0;
    }
    cout<<maxTillNow<<endl;
    return 0;
}

/*
8
-5 -1 5 -3 -1 2 3 -6
*/ 