#include<iostream>
#include<vector>
using namespace std;

vector<int> allDups(int arr[], int n){
    vector<int> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] == arr[j]){
                ans.push_back(arr[i]);
            }
        }
    }
    return ans;
}

int main()
{
    int n = 8;
    int arr[n] = {4,3,2,7,8,2,3,1};
    vector<int> ans = allDups(arr, n);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}