#include<bits/stdc++.h>
using namespace std;

int main(){
    string input,output;
    getline(cin,input);
    int cursor=0;
    int wordend;
    int start=0;
    int end;

        while(input[cursor]<=input.length())
        {
            while(input[cursor]!=' ')
            {
                cursor=cursor+1;
            }
            end=cursor-1;
            wordend=end;
            while(start<=wordend)
            {
                output[start]=input[end];
                ++start;
                --end;
            }
            start=wordend+1;
            output[start]=' ';
            ++start;
            ++cursor;
        }
}