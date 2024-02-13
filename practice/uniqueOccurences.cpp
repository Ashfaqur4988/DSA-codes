#include<iostream>
#include<vector>
using namespace std;

bool uniqueOcc(int arr[], int n){
    vector<int> freq(n+1);
    for(int i = 1; i<=n; i++){
        for(int j=0; j<n; j++){
            if(arr[j] == i){
                freq[i - 1]++;
            }
        }
    }

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            if(freq[i]==0 || i == j){
                //no action, loop continue
                continue;
            }
            if(freq[i] == freq[j]){
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 5;
    int arr[n] = {1,2,2,1,3};
    bool ans = uniqueOcc(arr, n);
    if(ans){
        cout<<"true"<<endl;
    } else {
        cout<<"false";
    }
    cout<<endl;
    return 0;
}