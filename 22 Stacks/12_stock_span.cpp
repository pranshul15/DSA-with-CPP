//to find the number of days before which the stock price was lower than that day itself
#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> stockspan(vector<int> prices){
    stack<pair<int,int>> st;
    vector<int> ans;
    for(auto price : prices){
        int days = 1;
        while(!st.empty() and st.top().first <= price){
            days += st.top().second;
            st.pop();
        }
        st.push({price,days});
        ans.push_back(days);
    }
    return ans;
}

int main(){
    vector <int> prices = {100,80,60,70,60,65,80};
    vector <int> res = stockspan(prices);
    for(auto i : res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}