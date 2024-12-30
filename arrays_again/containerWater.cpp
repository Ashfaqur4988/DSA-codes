int maxArea(vector<int>& height) {
        int maxi = INT_MIN;
        int i = 0; int j = height.size()-1;

        while(i < j){
            int mini = min(height[i], height[j]);
            int water = (j-i)*min(height[i], height[j]);
            maxi = max(maxi, water);
            if(mini == height[i]){
                i++;
            } else {
                j--;
            }
        }
        
        return maxi;
    }