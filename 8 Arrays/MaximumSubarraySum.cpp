#include<bits/stdc++.h>
using namespace std;

//Brute Force Approach [O N^3]

int bruteforce(int a[],int n){
    int sum=0;int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int x=i;x<=j;x++){
                sum+=a[x];
            }
            maxsum=max(maxsum,sum);
            sum=0;
        }
    }
    return maxsum;
}

//Prefix Sum Technique [O N^2]

int prefixsum(int a[],int n){
    int commutative[n+1];
    commutative[0]=0;
    for(int i=1;i<=n;i++){
        commutative[i]=commutative[i-1]+a[i-1];
    }
    int maxsum=INT_MIN;
    for(int i=1;i<=n;i++){
        int sum=0;
        maxsum=max(maxsum,commutative[i-1]);
        for(int j=1;j<=i;j++){
            sum=commutative[j-1]-commutative[j-1];
            maxsum=max(maxsum,sum); 
        }
    }
    return maxsum;
}

//Kadane's Method [O (N)]

int Kadane(int a[],int n){
    int currsum=0;
    int maxsum=INT_MIN;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum<0){
            currsum=0;
        }
        maxsum=max(maxsum,currsum);
    }
    return maxsum;
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
    return 0;
}