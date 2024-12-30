//brute
int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;

        int maxi = INT_MIN;
        for(int i = 0; i < s.size(); i++){
            unordered_set<char> st;

            for(int j = i; j < s.size(); j++){
                if(st.find(s[j]) != st.end()){
                    maxi = max(maxi, j-i);
                    break;
                }
                st.insert(s[j]);
            }
        }
        return maxi;
    }

//better
int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        int maxi = INT_MIN;
        int i = 0;
        unordered_set<int> set;
        for(int j = 0; j < s.size(); j++){
            if(set.find(s[j]) != set.end()){
                while(i < j && set.find(s[j]) != set.end()){
                    set.erase(s[i]);
                    i++;
                }
            }
            set.insert(s[j]);
            maxi = max(maxi, j-i + 1);
        }
        return maxi;
    }