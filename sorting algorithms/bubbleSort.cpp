#include<iostream>
using namespace std;

void bubbleSort(int ar[], int n){
    // iterate through the loop for the rounds
    for(int round = 1; round < n; round++){

        bool swapped = false; //optimizing the code

        // iterating and comparing elements
        for(int i = 0; i < n-round; i++){

            //checking the elements and swapping
            if(ar[i] > ar[i + 1]){
                swap(ar[i], ar[i+1]);
                swapped = true;
            }
        }
        if(swapped == false){
            //if already then break
            break;
        }
    }
}


void printArr(int ar[], int n){
    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[5] = {6,2,8,4,10};
    int num = 5;
    printArr(arr, num);
    bubbleSort(arr, num);
    printArr(arr, num);
    return 0;
}