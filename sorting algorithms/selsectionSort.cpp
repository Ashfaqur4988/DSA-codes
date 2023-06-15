#include<iostream>
using namespace std;

void selection(int ar[], int n){
    int i, j, min;
    for(i = 0; i < n-1; i++){  //loop will run till n-1
        //min is the smallest element in unsorted array.
        min = i;
        for(j = i+1; j < n; j++){
            if(ar[j] < ar[min]){ //comparing to find the minimum element
                min = j; //assigning min value 
            }
        }
        if(min!=i){ //checking for min not equal to i
        swap(ar[min], ar[i]); //swapping the elements
        }
    }
}

void printArray(int ar[], int n){
    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int main(){

    int arr[5] = {4,6,1,3,0};
    int num = 5;
    printArray(arr, num);
    selection(arr, num);
    printArray(arr, num);
    return 0;
}