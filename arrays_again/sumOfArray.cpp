#include<iostream>
using namespace std;

int main(){

    int n = 4;
    int arr[n] = {1,4,6,9};
    int sum = 0;
    for(int i = 0; i < n; i++){

        sum = sum + arr[i];
    }
    cout<<sum<<endl;

    return 0;
}