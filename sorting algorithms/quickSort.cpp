#include <bits/stdc++.h> 

int partition(vector<int> &nums, int s, int e){
        int p = nums[s];
        int i = s;
        int j = e;

        while(i < j){

            while(nums[i] <= p && i <= e - 1){
                i++;
            }

            while(nums[j] > p && j >= s + 1){
                j--;
            }

            if(i < j){
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[s], nums[j]);
        return j;
    }

    void qs(vector<int> &nums, int s, int e){
        if(s < e){
            int pInd = partition(nums, s, e);
            qs(nums, s, pInd-1);
            qs(nums, pInd+1, e);
        }
    }


vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    int s = 0;
    int e = arr.size()-1;
    qs(arr, s, e);
    return arr;
}


