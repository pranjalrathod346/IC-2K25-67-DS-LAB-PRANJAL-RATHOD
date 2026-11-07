#include<iostream>
using namespace std;
int main(){
    int arr[5]={12,34,56,99,88};
    int largest=INT_MIN;
    for(int i=0;i<5;i++){
        if(largest<arr[i]){
            largest=arr[i];
        }
    }
    cout<<"largest element of an array is = "<<largest;
}