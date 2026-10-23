#include<iostream>
using namespace std;

void merge(int arr[],int start, int end, int mid)
{
    int i=start, j=mid+1, k=0;
int temp[100];
while(i<=mid && j<=end)
{
    if(arr[i]<arr[j])
    {
        temp[k]=arr[i];
        i++;
    }
    else
    {
        temp[k]=arr[j];
        j++;
    }
    k++;
}
while(i<=mid)
{
    temp[k]=arr[i];
        i++;
        k++;
}
while(j<=end)
{
    temp[k]=arr[j];
        j++;
        k++;
}
for(int x=0;x<k;x++)
{
    arr[start+x]=temp[x];
}
}
void merge_sort(int arr[],int start, int end)
{
 if(start<end)
 {
    int mid= (start+end)/2;
   merge_sort(arr,start,mid);
   merge_sort(arr,mid+1,end);
   merge(arr,start,end,mid);
}
}
int main()
{
    int arr[]={6,3,4,5,1,2};
    int n=6;
    int start=0, end=n-1;

    merge_sort(arr,start,end);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}