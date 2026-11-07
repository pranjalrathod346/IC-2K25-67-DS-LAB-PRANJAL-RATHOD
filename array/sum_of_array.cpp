#include<iostream>
using namespace std;
int main(){
    int arr[5]={12,34,56,67,88};
    int sum=0;
    for(int i=0;i<5;i++){
        sum+=arr[i];
    }
    cout<<"sum of array is = "<<sum;

    
}