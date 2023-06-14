#include<iostream>
using namespace std;

void insertion(int ar[], int n){
    for(int i = 1; i < n; i++){
        int temp = ar[i];
        int j = i - 1;
        for(; j >=0; j--){
            if(ar[j]> temp){
                //shift
                ar[j+1] = ar[j];
            } else {
                break;
            }
        }
        ar[j+1] = temp;
    }
}

void insertionSort(int ar[],int n){
    //for loop to iterate from the second element as the first one we consider as sorted. 
    for(int i = 1; i < n-1; i++){
        int temp = ar[i]; //saving the element in a temp variable.
        int j = i - 1; //setting up j to iterate left side of ar[i]

        while(j >= 0 && temp < ar[j]){ //going left side to compare the elements
                ar[j+1] = ar[j];  //shifting elements one step to right
            j--;  //iterating left of the array.
        }
        ar[j+1] = temp; //out of loop now placing the a[i] element in front.
    }
}

void printArr(int ar[], int n){
    for(int i = 0; i < n; i++){
        cout<<ar[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int arr[5] = {5,2,6,3,9};
    int num = 5;
    printArr(arr,num);
    insertionSort(arr,num);
    printArr(arr,num);

    return 0;
}