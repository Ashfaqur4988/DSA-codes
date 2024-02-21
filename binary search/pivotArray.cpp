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

int main()
{
    int n = 5;
    int arr[n] = {8,9,1,2,3};
    int ans = pivot(arr, n);
    cout<<arr[ans]<<endl;
    return 0;
}