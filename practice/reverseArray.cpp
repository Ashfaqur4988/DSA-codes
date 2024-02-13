#include<iostream>
#include<algorithm>
using namespace std;

void reverse(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s <= e){
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{

    int n = 6;
    int arr[n] = {3,6,8,9,1,7};
    cout<<"before reverse "<<endl;
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<endl;
    reverse(arr, n);
    return 0;
}