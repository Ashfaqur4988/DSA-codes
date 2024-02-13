#include<iostream>
#include<algorithm>
using namespace std;

void reverse(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s<=e){
        while(arr[s]==0 && s < e){
            s++;
        }
        while(arr[e]==1 && s < e){
            e--;
        }
        if(arr[s] == 1 && arr[e] == 0 && s < e){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }
    for(int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n = 6;
    int arr[n] = {0,1,1,0,0,1};
    reverse(arr, n);

    return 0;
}