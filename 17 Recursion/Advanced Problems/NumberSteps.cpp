//program to find the number of ways to go from startin point to end point
//we can move 1-6 steps thaht of a dice at a sighle time

#include<bits/stdc++.h>
using namespace std;

// int NumberSteps[] = {1,1,2,4,8,16,32};

// int NumWays(int start,int end,int counter){
//     if(start>end){
//         return counter;
//     }

//     if(end-start<=6){
//         counter+=NumberSteps[end-start];
//         NumWays(start+1,end,counter);        
//     }
//     else{

//         NumWays(start+6,end,counter+32);
//     }
// }

int countWays(int s,int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count =0;
    for(int i=0;i<=6;i++){
        
        count+=countWays(s+i,e);
    }
    return count;
}

int main(){
    // int a,b;
    // cin>>a>>b;
    cout<<countWays(0,3);
    return 0;
}