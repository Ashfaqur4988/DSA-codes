#include<iostream>
using namespace std;

int isUnique(int arr[], int n){
    int ans = 0;
    for(int i = 0; i<n; i++){
        ans = ans ^ arr[i];
    }

    for(int i = 0; i<n; i++){
        ans = ans ^ i;
    }
    return ans;
}

int main(){

    int n = 7;
    int arr[n] = {1,2,3,4,5,6,4};

    int ans = isUnique(arr, n);
    cout<<ans<<endl;

    return 0;
}