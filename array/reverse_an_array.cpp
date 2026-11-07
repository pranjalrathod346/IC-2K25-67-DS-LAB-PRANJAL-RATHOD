#include<iostream>
using namespace std;
int main(){
    int n=5;
    int arr[n] = {10, 20, 30, 40, 50};
    int left=0;
    int right= n-1;

    while(right>left){
        int temp=arr[left];
        arr[left]=arr[right];
        arr[right]=temp;

        left++;
        right--;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}