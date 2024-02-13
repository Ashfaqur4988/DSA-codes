#include<iostream>
#include<vector>
using namespace std;

vector<int> intersection(int v1[], int v2[], int n, int m){
    vector<int> ans;
    for(int i = 0; i < n; i++){
        int element = v1[i];
        for(int j = 0; j < m; j++){

            if(element < v2[j]){
                break;
            }

            if(element == v2[j]){
                ans.push_back(element);
                v2[j] = INT_MIN;
                break;
            }

        }
    }
    return ans;
}

int main()
{
    
    int v1[3] = {1,2,3};
    int v2[2] = {3,4};
    vector<int> ans = intersection(v1, v2, 3, 2);
    for( int i: ans){
        cout<<i<<" ";
    }

    return 0;
}