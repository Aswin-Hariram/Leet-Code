class Solution {
public:

    void dfs(string node,
             unordered_map<string, vector<string>> &mp,
             vector<string> &ans){

        while(!mp[node].empty()){

            string next = mp[node].back();
            mp[node].pop_back();

            dfs(next, mp, ans);
        }

        ans.push_back(node);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        unordered_map<string, vector<string>> mp;

        for(auto &t : tickets){

            string u = t[0];
            string v = t[1];

            mp[u].push_back(v);
        }

        // sort in reverse because we use back()
        for(auto &m : mp){

            sort(m.second.begin(),
                 m.second.end(),
                 greater<string>());
        }

        vector<string> ans;

        dfs("JFK", mp, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};