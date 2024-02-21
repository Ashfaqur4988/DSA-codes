#include<iostream>
#include<algorithm>
using namespace std;

void sort012(int arr[], int n){
    int s = 0;
    int e = n-1;
    while(s < e){
        while(arr[s] == 0 && s < e){
            s++;
        }
        while(arr[e] == 2 && s < e){
            e--;
        }
        if(arr[s] != 0 && arr[e] != 2){
            swap(arr[s], arr[e]);
            s++;
            e--;
        }
    }

    int s1 = 0;
    int e1 = n-1;
    while(s1 < e1){
        while(arr[s1] == 0 && s1 < e1){
            s1++;
        }
        while(arr[e1] == 1 || arr[e1] == 2 && s1 < e1){
            e1--;
        }
        if(arr[s1] != 0 && arr[e1] != 1){
            swap(arr[s1], arr[e1]);
            s1++;
            e1--;
        }
    }
    
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

//optimized solution
void sort012Optimized(int arr[], int n){
        int l = 0;
        int h = n-1;
        for(int i=0; i < n && i <= h;){
            if(arr[i]==0){
                swap(arr[l],arr[i]);
                l++;
                i++;
            } else if(arr[i]==2){
                swap(arr[i],arr[h]);
                h--;
            } else {
                i++;
            }
        }
        for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
        
    }

int main()
{
    int n = 9;
    int arr[n] = {0,2,2,1,0,1,1,0,2};
    sort012(arr, n);
    sort012Optimized(arr, n);
    return 0;
}