#include<iostream>
#include<algorithm>
using namespace std;

int k,n;
int arr[100];
class Triplets
{
    public:

    Triplets()
    {
        k=0; n=0;
    }

    void accept()
    {
        cout<<"\nEnter the value of k: "; cin>>k;
        cout<<"\nEnter the size of array: "; cin>>n;
        if(n==0) cout<<"AE SETH... BADI MASTI KARTA HAI TU....<nasty smile>";
        else
        {
        cout<<"\nEnter array: ";
        for(int i=0; i<n; i++) cin>>arr[i];
        }
    }

    bool check()
    {
        bool v=false;
        sort(arr,arr+n);
        for(int i=0; i<n-1; i++)
        {
            int a=i+1,b=n-1,c;
            while(a<b)
            {
                c=arr[i]+arr[a]+arr[b];
                if(c==k) {v=true; break;}
                else if(c<k) {a++;}
                else {b--;}
            }
        }
        return v;
    }

    void display(bool m)
    {
        if(m==true) cout<<"\nYES\n";
        else cout<<"\nNO\n";
    }
};

int main()
{
    Triplets t;
    t.accept();
    t.display(t.check());
    cout<<endl;
    return 0;
}