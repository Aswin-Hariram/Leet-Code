class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();

        unordered_map<char,int> mp;

        for(char c:p){
            mp[c]++;
        }
        vector<int> ans;

        int left = 0;
        int count = 0;
        for(int right = 0;right<n;right++){

            if(mp[s[right]] > 0){
                count++;
            }
            mp[s[right]]--;

            while(right-left+1>k){
                mp[s[left]]++;
                if(mp[s[left]]>0){
                    count--;
                }
                left++;
            }

            
            if(right-left+1==k && count==k)
                ans.push_back(left);


        }

        return ans;
    }
};