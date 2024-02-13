#include<iostream>
using namespace std;

int getMax(int arr[], int size){
    int max = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
    
}

int getMin(int arr[], int size){
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if(arr[i] < min){
            min = arr[i];
        }
    }
    return min;
    
}

int main(){

    int size = 5;
    int arr[size] = {1,3,6,7,9};
    for(int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int max = getMax(arr, size);
    cout<<"max is "<<max<<endl;

    int min = getMin(arr, size);
    cout<<"min is "<<min<<endl;

    return 0;
}