#include<iostream>
using namespace std;

int unique(int ar[], int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ ar[i];
    }
    return ans;
    
}

void printArray(int ar[], int n){
    for(int i = 0; i < n; i++){
        cout <<ar[i]<<" ";
    }
    cout<<endl;
}

bool isUnique(int arr[], int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = ans ^ arr[i];
    }
    if(ans == 0){
        return false;
    } else {
        return true;
    }
    
}

int main(){

    int arr[5]= {2,4,2,6,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int answer = unique(arr, size);
    bool an = isUnique(arr, size);
    cout<<answer<<endl;
    cout<<an;

    return 0;
}