#include<iostream>
using namespace std;

void reverse(int arr[], int s){
    int start = 0;
    int end = s-1;
    while(start <= end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void print(int arr[], int s){
    for(int i = 0; i < s; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int n = 4;
    int arr[n] = {1,4,6,9};

    cout<<"before "<<endl;
    print(arr, n);
    reverse(arr, n);
    
    cout<<"after "<<endl;
    print(arr, n);

    return 0;
}