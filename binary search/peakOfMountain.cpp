#include<iostream>
using namespace std;

int peak(int arr[], int n){
    int s = 0;
    int e = n-1;
    int m = s + (e-s)/2;

    while(s<e){
        if(arr[m] < arr[m+1]){
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
    int n = 4;
    int arr[n] = {0,2,1,0};
    int ans = peak(arr,n);
    cout<<ans<<endl;
    return 0;
}