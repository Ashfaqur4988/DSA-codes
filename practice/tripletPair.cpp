#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> tripletSum(int arr[], int n, int sum){
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            for (int k = j+1; k < n; k++)
            {
                if(arr[i] + arr[j] + arr[k] == sum){
                    ans.push_back(arr[i]);
                    ans.push_back(arr[j]);
                    ans.push_back(arr[k]);
                }
            }
            
        }
        
    }
    return ans;
    
}

int main()
{
    int n = 5;
    int arr[n] = {1,2,3,4,5};
    vector<int> ans = tripletSum(arr, n, 12);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}