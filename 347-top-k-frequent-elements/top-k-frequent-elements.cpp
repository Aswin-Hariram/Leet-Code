class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums)
            freq[num]++;

        int n = nums.size();

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for(auto [key,value]:freq){
            pq.push({value,key});
            while(pq.size()>k){
                pq.pop();
            }
        }

        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};