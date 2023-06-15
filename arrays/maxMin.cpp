#include<iostream>
using namespace std;

int minVal(int ar[], int n){
    int min = INT_MAX;
    for(int i = 0; i < n; i++){
        if(ar[i] < min){
            min = ar[i];
        }
    }
    return min;
}

int maxVal(int ar[], int n){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(ar[i] > max){
            max = ar[i];
        }
    }
    return max;
}

void printArray(int ar[], int n){
    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[5] = {4,12,6,8,10};
    int size = 5;

    printArray(arr, size);
    int minimum = minVal(arr, size);
    cout << minimum << endl;
    int maximum = maxVal(arr, size);
    cout << maximum << endl;
    return 0;
}