/*Given an array of 0's and 1's and we can convert K 0's into
1's such that the length of the subsequence obtained 
is maximum*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n,K;
    cin>>n>>K;
    vector<int> arr(n);
    for(auto &i : arr){
        cin>>i;
    }

    int zerocnt = 0,i=0,ans=0;

    for(int j=0;j<n;j++){
        
        if(arr[j]==0){
            zerocnt++;
        }

        while(zerocnt > K){

            if(arr[i]==0){
                zerocnt--;
            }

            i++;
        }

        ans = max(ans,j-i+1);
    }

    cout<<ans<<endl;
    return 0;
}

