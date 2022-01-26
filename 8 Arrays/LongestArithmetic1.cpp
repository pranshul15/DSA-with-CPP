//to find longest arithmetic series from given array
#include<bits//stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[n];
    }

    int d = arr[1] - arr[0];
    int curr = 2;
    int ans = 2;
    int j = 2;

    while(j<n-1)
    {
        if((arr[j] - arr[j-1]) == d)
        {
            curr ++;
        }
        else
        {
            d = arr[j] - arr[j-1];
            curr = 2;
        }        
        ans = max(ans, curr);
        j++;
    }
    cout << ans << endl;
    return 0;
}