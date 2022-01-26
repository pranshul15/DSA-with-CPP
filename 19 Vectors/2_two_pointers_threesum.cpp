#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool threesum(vector<int> arr,int key){
    int n=arr.size();
    if(n<3){
        return false;
    }
    for(int i=0;i<n-2;i++){
        int check = key-arr[i];
        int low = i+1;
        int high = n-1;
        
        while(low<high){
            if(arr[low] + arr[high] == check){
                return true;
            }
            else if (arr[low] + arr[high] < check)
            {
                low++;
            }
            else
            {
                high--;
            }
        }

    }
    return false;
}

int main(){
    int key;
    cin>>key;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i : arr){
        cin>>i;
    }

    sort(arr.begin(),arr.end());

    if(threesum(arr,key)){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
    return 0;
}