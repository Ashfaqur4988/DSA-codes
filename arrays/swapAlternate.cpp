#include<iostream>
using namespace std;

void printArray(int ar[], int n){
    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}


void swapAlt(int ar[], int n){
    for(int i = 0; i < n; i+=2){
        if(i + 1 < n){
            swap(ar[i], ar[i+1]);
        }
    }
}

int main(){

    int arr[5]= {1,2,3,4,5};
    int size = 5;
    printArray(arr, size);
    swapAlt(arr, size);
    printArray(arr, size);


    return 0;
}