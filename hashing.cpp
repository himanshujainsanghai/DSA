#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"enter the index of array"<<endl;

    cin>>n;
    int arr[n];
    cout<<"enter the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }


    // precompute
    int hash[13]={0};
    for (int  i = 0; i < n; i++)
    {
        hash[arr[i]]+=1;
    }

    // fetching
    int q;
    cout<<"Enter q"<<endl;
    cin>>q;
    while(q--){
        int number;
        cout<<"enter number"<<endl;
        cin>>number;
        // fetch
        cout<<"The hash[number] is : "<<hash[number]<<endl;
    }
    
    
    
    return 0;
}