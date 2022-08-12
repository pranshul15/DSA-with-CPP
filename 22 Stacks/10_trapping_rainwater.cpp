#include <iostream>
#include <stack>
using namespace std;

int rainwater_trapped(int arr[], int n)
{
    stack <int> st;
    int i = 0,j;
    int ans = 0;
    while (i < n-1)
    {
        while(arr[i+1] > arr[i]){
            i++;
        }
        j = i;
        while((arr[j+1] < arr[j]) and (j<n-1)){
            j++;
        }
        if(j<n-1){
            j++;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<rainwater_trapped(arr,n);
    return 0;
}