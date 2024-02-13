#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tripletSum(int arr[], int size, int sum){
    vector<int> ans;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size; j++){
            for(int k=j+1; k<size; k++){
                if(arr[i] + arr[j] + arr[k] == sum){
                    ans.push_back(min(arr[i], arr[j], arr[k]));
                }
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
    vector<int> ans = tripletSum(arr, size, 12);
    for(int i : ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}