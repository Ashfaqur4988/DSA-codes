#include<iostream>
using namespace std;

int unique(int arr[], int s){
    int ans = 0;
    for(int i = 0; i < s; i++){
        ans = ans ^ arr[i];
    }
    return ans;
}

int main(){

    int size = 5;
    int arr[size] = {2,3,4,2,3}; 
    int ans = unique(arr, size);
    cout<<ans<<endl;
    return 0;
}