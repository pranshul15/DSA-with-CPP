#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef vector<pair<int,int>> vpi;
typedef pair<int,int> pi;
#define PB push_back
#define F first
#define S second
#define rep(i,a,b) for(int i=a;i<b;i++)
#define reb(i,a,b) for(int i=a-1;i>=b;i--)

priority_queue<int,vi,greater<int>> pqmin;
priority_queue<int,vi> pqmax;

void insert(int x){

    if(pqmax.size() == pqmin.size()){
       
        if(pqmax.size()==0){
            pqmax.push(x);
        }
        
        else{

            if(x >= pqmax.top()){
                pqmin.push(x);
            }

            else{
                pqmax.push(x);
            }
        }
    }
    
    else{

        if(pqmax.size() > pqmin.size()){

            if(x >= pqmax.top()){
                pqmin.push(x);
            }

            else{
                int temp = pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }

        else{

            if(x <= pqmin.top()){
                pqmax.push(x);
            }

            else{
                int temp = pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian(){
    if(pqmax.size()==pqmin.size()){
        return (pqmax.top() + pqmin.top()) / 2.0;
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main(){
    insert(10);
    cout<< findMedian() << "\n";
    // 10
    insert(8);
    cout<< findMedian() << "\n";
    // 9
    insert(12);
    cout<< findMedian() << "\n";
    // 10
    insert(9);
    cout<< findMedian() << "\n";
    // 9.5
    insert(18);
    cout<< findMedian() << "\n";
    // 10
    return 0;
}