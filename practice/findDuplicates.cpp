#include<iostream>
using namespace std;

int dups(int arr[], int n){
    int ans;
    for(int i=0; i<n; i++){
        ans = ans ^ arr[i];
    }
    for(int i=0; i<n; i++){
        ans = ans ^ i;
    }
    return ans;

}

int main()
{
    int n = 5;
    //a sorted array with duplicate element at the end
    //this means that if we XOR the array with another n-1 array of same elements 
    //then we can achieve the duplicate element
    int arr[n] = {1,2,3,4,3};
    int ans = dups(arr, n);
    cout<<ans<<endl;
    return 0;
}