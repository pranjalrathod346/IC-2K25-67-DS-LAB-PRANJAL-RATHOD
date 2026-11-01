#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int arr[n]={1,2,3,4,5};
    int pass=0;

    for(int i=0;i<n-1;i++)
    {
        bool swap=false;

        for(int j=0; j<n-1-i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=true;
            }
        }
        pass++;

        if(swap==false){
            break;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"the number of interation or passes = "<<pass;
}