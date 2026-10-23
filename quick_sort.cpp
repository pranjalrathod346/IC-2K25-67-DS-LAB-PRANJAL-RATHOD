#include<iostream>
using namespace std;
int partition(int arr[], int  low ,int high)
{
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            int temp=arr[i];
             arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1];
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}
void quick_sort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pivot_index= partition(arr, low , high);
         quick_sort(arr, low , pivot_index-1);
         quick_sort(arr, pivot_index+1 , high);
    }
}
int main()
{
    int arr[]={7,4,6,3,5,1,2};
    int n=7;
    int low=0, high=n-1;
    quick_sort(arr, low , high);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}