#include<iostream>
using namespace std;
int main(){
    int n=5;
    int arr[n]={4,3,5,2,1};

    for(int i=1;i<n;i++)
    {
      int key=arr[i];
      int pre=i-1;

      while(pre>=0 && arr[pre]<key)
      {
        arr[pre+1]=arr[pre];
        pre--;
      }
      arr[pre+1]=key;
    }

    for(int i=0;i<n;i++)
    {
          cout<<arr[i]<<" ";
    }
}