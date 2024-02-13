#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(int arr1[], int arr2[], int n, int m){
    vector<int> ans;
    int i, j = 0;
    while(i < n && j < m){

        if(arr1[i] == arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        } else if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }
    return ans;
}

int main()
{
    int arr1[6] = {1,2,2,3,3,4};
    int arr2[4] = {2,2,3,3};
    vector<int> ans = intersection(arr1, arr2, 6, 4);
    for(int i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}