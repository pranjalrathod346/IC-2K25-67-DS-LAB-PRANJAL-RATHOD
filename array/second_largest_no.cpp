#include<iostream>
using namespace std;
int main(){
    int arr[5] = {101, 20, 30, 40, 50};
    int largest= INT_MIN;
    int sec_largest= INT_MIN;

    for(int i=0;i<5;i++){
        if(arr[i]>largest){
              sec_largest=largest;
            largest=arr[i];
          
        }

        else if(arr[i]>sec_largest){
            sec_largest=arr[i];
        }
    }
    cout<<"largest no is an array is = "<<largest<<endl;
   cout<<"sec largest no is an array is = "<<sec_largest<<endl;
}