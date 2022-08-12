#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
    string a;
    cout<<"\nEnter the sentence: ";
    getline(cin, a);
    int i=0;
    int j;
    int len=a.length();
    // cout<<len;
    while(i<=len)
    {
        for(j=i; j<=len; j++)
        {
            if((a[j]==' ') || j==len)
            {
                swap(a[i],a[j-1]); 
                break;
            }
        }
        i=j+1;
    }

    cout<<"\nI have no idea why you are making me do this but ...Ok take this:\n"<<a;
    return 0;
}