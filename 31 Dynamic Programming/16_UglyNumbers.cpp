/*
Ugly numbers are numbers whose prime factors are 2,3 or 5.
The first 10 ugly numbers are 1,2,3,4,5,6,8,9,10,12
By convention 1 is included
given a number n, Print the nth ugly number
*/
#include<bits/stdc++.h>
using namespace std;

int main(){
    // nth ugly number
    int n;cin>>n;
    
    vector<int> dp(n,0);

    int i=0,j=0,k=0;
    int a=2,b=3,c=5;
    int ans = 1;

    for(int count = 1 ; count<n ; count++){
        ans = min(a,min(b,c));
        dp[count] = ans;

        if(ans == a){
            i++;
            a = dp[i]*2;
        }
        if(ans == b){
            j++;
            b = dp[j]*3;
        }
        if(ans == c){
            k++;
            c = dp[k]*5;
        }
    }
    cout<<ans<<endl;
    return 0;
}