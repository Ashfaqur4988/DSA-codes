#include<iostream>
using namespace std;

int unique(int arr[], int n){
    int ans;
    for(int i=0; i<n; i++){
        //same number XOR will give 0.
        //this will remove all the same numbers.
        ans = ans ^ arr[i];
    }
    return ans;
}

int main()
{
    int n = 5;
    int arr[n] = {3,4,4,6,3};
    int ans = unique(arr, n);
    cout<<ans<<endl;

    return 0;
}