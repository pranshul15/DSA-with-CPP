/*
Given an array arr.
You are supposed to find maximum value of 
(arr[a]^arr[a+1]^....^arr[b])+(arr[c]^arr[c+1]...^arr[d])
where 1<=a<=b < c<=d<=N, where N is the size of the array.
^ denotes XOR operation
*/ 
#include<bits/stdc++.h>
using namespace std;

int getBit(int val,int position){
    return (val & (1<<position))!=0;
}

// Continuous XOR from i to j
int arrayXOR(vector<int> &nums,int i,int j){
    int ans = 0;
    for(int x=i;x<=j;x++){
        ans = ans^nums[x];
    }
    return ans;
}

// Brute Force Approach
int maxVal1(vector<int> &nums){
    int ans = 0;

    for(int a=0;a<nums.size()-1;a++){
        for(int b=a;b<nums.size()-1;b++){
            for(int c=b+1;c<nums.size();c++){
                for(int d=c;d<nums.size();d++){
                    ans = max(ans, arrayXOR(nums,a,b)+arrayXOR(nums,c,d));
                }
            }
        }
    }

    return ans;
}

// through kadane's algorithm
int maxVal2(vector<int> &nums){
    int n = nums.size();
    
    vector<int> prefixXOR(n,0);
    vector<int> suffixXOR(n,0);

    prefixXOR[0] = nums[0];
    suffixXOR[n-1] = nums[n-1];

    int maxEnd = nums[0];
    int maxStr = nums[n-1];

    for(int i=1 ; i<nums.size() ; i++){

        maxEnd = max(nums[i] , nums[i]^maxEnd);
        prefixXOR[i] = max(prefixXOR[i-1] , maxEnd);

        int x = n-i-1;
        maxStr = max(nums[x] , nums[x]^maxStr);
        suffixXOR[x] = max(suffixXOR[x+1] , maxStr);

    }

    int ans = 0;

    for(int i=0;i<n;i++){
        cout<<prefixXOR[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<suffixXOR[i]<<" ";
    }
    cout<<endl;

    for(int i=0 ; i<(n-1) ; i++)
        ans = max(ans , prefixXOR[i]+suffixXOR[i+1]);
    
    return ans;
}

// using Trie
class TrieNode
{
public:
    int value;
    TrieNode* next[2];
    TrieNode() {
        value = 0;
        next[0] = next[1] = NULL;
    }
};

void insert (TrieNode* &root,int val){
    TrieNode* it = root;

    for(int i=30 ; i>=0 ; i--){
        int x = getBit(val,i);

        if(it->next[x] == NULL){
            it->next[x] = new TrieNode();
        }

        it = it->next[x];
    }

    it->value = val;
}

// this query will return the maximum XOR till now array
int Query(TrieNode* &root,int preXOR){
    TrieNode* it = root;

    for(int i=30 ; i>=0 ; i--){
        int x = getBit(preXOR,i);

        // if opposite bit is there, then move iterator there
        if((it->next[1-x]) != NULL)
            it = it->next[1-x];

        // if opposite bit is not there, then move iterator to same place
        else
            it = it->next[x];
    }

    return (it->value)^preXOR;
}

int maxVal3(vector<int> &nums){
    int n = nums.size();
    
    TrieNode* root1;
    insert(root1,0);

    int preXOR = 0;
    int result = INT_MIN;
    vector<int> prefixXOR(n,0);

    for(int i=0 ; i<n ; i++){
        preXOR = preXOR^nums[i];
        insert(root1,preXOR);

        result = max(result,Query(root1,preXOR));
        prefixXOR[i] = result;
    }

    TrieNode* root2;
    insert(root2,0);

    int sufXOR = 0;
    result = INT_MIN;
    vector<int> suffixXOR(n,0);

    for(int i=n-1 ; i>=0 ; i--){
        sufXOR = sufXOR^nums[i];
        insert(root2,sufXOR);

        result = max(result,Query(root2,sufXOR));
        suffixXOR[i] = result;
    }

    int ans = 0;

    for(int i=0 ; i<(n-1) ; i++)
        ans = max(ans , prefixXOR[i]+suffixXOR[i+1]);

    return ans;
}

int main(){
    int n;
    cin>>n;

    vector<int> nums(n);

    for(int i=0;i<n;i++){
        cin>>nums[i];
    }

    cout<<maxVal3(nums);

    return 0;
}

/*
arr [] : 4 8 3 5 2

*/ 