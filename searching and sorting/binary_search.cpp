#include<iostream>
using namespace std;
int main()
{
    int n=5;
    int arr[n]={10,20,30,40,50};
    int target=400;
    int left=0, right=n-1;
    bool found =false;

    while(left<=right)
    {
        int mid=(left+right)/2;

        if(target==arr[mid])
        {
            cout<<"element found at index "<<mid;
            found=true;
            break;
        }

        else if(target<arr[mid])
        {
            right=mid-1;
        }
        
         else 
        {
            left=mid+1;
        }
    }
    if(found==false){
        cout<<"element not found";
        }
}