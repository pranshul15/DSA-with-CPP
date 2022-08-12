#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int largest_area_bruteforce(int arr[],int n){
    int area;
    int height;
    int breadth;

    for(int i=0;i<n;i++){
        height = arr[i];
        for(int j=i;j<n;j++){
            height = min(height,arr[j]);
            breadth = i-j+1;
            area = max(area,height*breadth);
        }
    }

    return area;
}

int largest_area_rectangle(int arr[],int n){
    
    stack <int> st;
    st.push(0);

    for(int i=0; i<n; i++)
    {

        if(st.top() < arr[i])
        {
            st.push(arr[i]);
        }

        int b=i+1;
        while((arr[i] < arr[b]) and b<n)
        {
            if(st.top() < arr[i]*(b-i+1))
            {
                st.push(arr[i]*(b-i+1));
            }
            b++;
        }
    }

    return st.top();
}

int main(){
    int* arr;
    int n;
    cin>>n;
    arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<largest_area_rectangle(arr,n);
    return 0;
}