#include<iostream>
using namespace std;

int pivot(int arr[], int n){
    int s = 0;
    int e = n-1;
    int m = s + (e-s)/2;

    while (s<e)
    {
        if(arr[m] >= arr[s]){
            s = m+1;
        } else {
            e = m;
        }
        m = s + (e-s)/2;
    }
    return e;
}

int binarySearch(int arr[], int p,int n, int k){
    int s = p;
    int e = n;
    int m = s + (e-s)/2;

    while (s <= e)
    {
        if(arr[m] == k){
            return m;
        } 
        if(arr[m] < k){
            s = m+1;
        } else {
            e = m-1;
        }
        m = s + (e-s)/2;
    }
    return -1;
}

int search(int arr[], int n, int k){
    int p = pivot(arr, n);
    if(arr[p] <= k && k <= arr[n-1]){
        return binarySearch(arr, p, n-1, k);
    } else {
        return binarySearch(arr, 0, p-1, k);
    }
}

int main()
{
    int n = 5;
    int arr[n] = {8,9,1,2,3};
    //int arr1[n] = {1,2,3,4,5};
    // int ans1 = binarySearch(arr1, n, 4);
    // cout<<ans1<<endl;
    //int ans = pivot(arr, n);
    int ans = search(arr, n, 2);
    cout<<ans<<endl;
    return 0;
}