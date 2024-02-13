#include<iostream>
using namespace std;

int min(int arr[], int n){
    int mini = INT_MAX;
    for(int i = 0; i < n; i++){
        if(arr[i] < mini){
            mini = arr[i];
        }
    }
    return mini;
}

int max(int arr[], int n){
    int maxi = INT_MIN;
    for(int i = 0; i < n; i++){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
    }
    return maxi;
}


int main()
{

    int n = 5;
    int arr[n] = {3,6,8,9,1};
    int mini = min(arr, n);
    cout<<"min "<<mini<<endl;
    int maxi = max(arr, n);
    cout<<"max "<<maxi<<endl;
    return 0;
}