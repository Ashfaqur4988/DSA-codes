#include<iostream>
#include<algorithm>
using namespace std;

int first(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int m = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[m] == key){
            ans = m;
            e = m - 1;
        } else if(arr[m] < key){
            s = m+1;
        } else {
            e = m-1;
        }
        m = s + (e-s)/2;
    }
    return ans;
}

int last(int arr[], int n, int key){
    int s = 0;
    int e = n-1;
    int m = s + (e-s)/2;
    int ans = -1;

    while(s <= e){
        if(arr[m] == key){
            ans = m;
            s = m + 1;
        } else if(arr[m] < key){
            s = m+1;
        } else {
            e = m-1;
        }
        m = s + (e-s)/2;
    }
    return ans;
}

int main()
{
    int n = 6;
    int arr[n] = {0,5,5,6,6,6};
    int ans = first(arr, n, 6);
    int ans2 = last(arr, n, 6);
    pair<int, int> result;
    result.first = ans;
    result.second = ans2;
    cout<<result.first<<" "<<result.second<<endl;
    cout<<(result.second - result.first) + 1<<endl;
    return 0;
}