#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pairSum(int arr[], int size, int sum){
    vector<int> ans;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            if(arr[i] + arr[j] == sum){
                // vector<int> temp;
                ans.push_back(min(arr[i], arr[j]));
                ans.push_back(max(arr[i], arr[j]));
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int size = 5;
    int arr[size] = {1,2,3,4,5};
    vector<int> ans = pairSum(arr, size, 5);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}