#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> pairSum(int arr[], int n, int sum){
    vector<int> ans;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i] + arr[j] == sum){
                ans.push_back(min(arr[i], arr[j]));
                ans.push_back(max(arr[i], arr[j]));
            }
        }
    }
    //sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    vector<int> ans = pairSum(arr, n, 5);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}