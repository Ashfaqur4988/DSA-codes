#include<iostream>
using namespace std;

void printArray(int ar[], int n){
    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

void reverse(int ar[], int n){
    int temp;
    int i = 0, j = n-1;
    while(i <= j){
        //swap the elements at index i and j
        temp = ar[i];
        ar[i] = ar[j];
        ar[j] = temp;
        i++;
        j--;
    }
}

int main(){

int arr[6] = {1,2,3,4,5,6};
int size = 6;
printArray(arr, size);
reverse(arr,size);
printArray(arr, size);

    return 0;
}