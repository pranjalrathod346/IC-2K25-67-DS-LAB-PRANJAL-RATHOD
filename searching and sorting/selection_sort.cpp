#include<iostream>
using namespace std;

int main()
{
     int n=5;
    int arr[n]={5,3,1,4,2};

    for(int i=0;i<n-1;i++)
    {
       int min_index=i;

        for(int j=i+1;j<n;j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index=j;
            }
        }
        int temp= arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}