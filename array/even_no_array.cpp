#include<iostream>
using namespace std;
int main(){
    int arr[6]={10, 15, 21, 31, 40, 51};
    int count=0;
    for(int i=0;i<5;i++){
        if(arr[i]%2==0){
            count++;
        }
    }
      cout<<"even number in an array = "<<count;
}