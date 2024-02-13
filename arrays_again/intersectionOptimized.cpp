#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(int v1[], int v2[], int n, int m){
    vector<int> ans;
    int i, j = 0;
    while(i < n && j < m){

        if(v1[i] == v2[j]){
            ans.push_back(v1[i]);
            i++;
            j++;
        } else if(v1[i] < v2[j]){
            i++;
        } else {
            j++;
        }
    }
    return ans;
}

int main()
{
    int v1[6] = {1,2,2,3,3,4};
    int v2[4] = {2,2,3,3};

    vector<int> ans = intersection(v1, v2, 6, 4);
    for(int i: ans){
        cout<<i<<" ";
    }
    return 0;
}