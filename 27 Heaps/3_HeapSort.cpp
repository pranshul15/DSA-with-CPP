#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define reb(i,a,b) for(int i=a-1;i>=b;i--)


void heapify(vi &a,int heapsize){
    reb(i,heapsize,0){
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;
        if(l<heapsize && a[l]>a[largest]){
            largest = l;
        }
        if(r<heapsize && a[r]>a[largest]){
            largest = r;
        }
        if(largest != i){
            swap(a[largest],a[i]);
        }
    }
}

void heapsort(vi &a){

    int heapsize = a.size();

    while(heapsize){
        heapify(a,heapsize);
        swap(a[0],a[heapsize-1]);
        heapsize--;
    }
}

int main(){
    int n;
    cin>>n;

    vi a(n);

    rep(i,0,n){
        cin>>a[i];
    }

    heapsort(a);

    rep(i,0,n){
        cout<<a[i]<<" ";
    }
    return 0;
}