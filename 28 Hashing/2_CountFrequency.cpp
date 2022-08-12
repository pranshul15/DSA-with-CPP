#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

#define rep(i,a) for(int i=0;i<a;i++)
#define ff first
#define ss second
typedef vector<int> vi;

int main(){
    int n;
    cin>>n;
    
    vi a(n);
    
    rep(i,n)
        cin>>a[i];
    
    unordered_map<int,int> freq;

    rep(i,n){
        freq[a[i]]++;
    }

    unordered_map<int,int> :: iterator it;

    for(it = freq.begin(); it!=freq.end();it++){
        cout<<it->ff<<" "<<it->ss<<endl;
    }
    return 0;
}