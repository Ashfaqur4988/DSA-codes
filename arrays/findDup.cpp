#include<iostream>
using namespace std;

//elements present inside is from 1 to n-1 and one element is repeating
int findDup(int ar[], int n){
    int ans = 0;
    //XOR all elements
    for(int i = 0; i < n; i++){
        ans = ans ^ ar[i];
    }

    //XOR [1 to n-1]
    for(int i = 1; i < n; i++){
        ans = ans ^ i;
    }
    return ans;
}

int main(){

    int arr[5]= {1,2,3,4,4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int ans = findDup(arr, size);
    cout<<ans;
    return 0;
}