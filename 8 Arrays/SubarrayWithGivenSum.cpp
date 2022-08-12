//Input an array of size n and a number S
//Output is an subarray which sums downs to S
#include<bits/stdc++.h>
using namespace std;

//Optimised Approach
void printarray(int a[],int i,int j)
{
    for(int x=i;x<=j;x++)
    {
        cout<<a[x]<<" ";
    }
}

void SubarrySum(int a[],int n,int s)
{
    int i,j,sum=0;
    for(i=0;i<n;i++)
    {
        sum=0;
        for(j=i;j<n;j++)
        {
            if(sum<s)
            {
                sum=sum+a[j];
            }
            else if(sum==s)
            {
                printarray(a,i,j);
                break;
            }
        }
    }
}
//Optimised Approach

int main()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int s;
    cin>>s;
    SubarrySum(a,n,s);
    return 0;
}