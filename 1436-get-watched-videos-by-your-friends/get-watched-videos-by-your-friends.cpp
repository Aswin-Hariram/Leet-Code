class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        int n = friends.size();
        vector<bool> vis(n, false);
        queue<int> q;

        q.push(id);
        vis[id] = true;

        // BFS to reach the required level
        while (level--) {
            int sz = q.size();
            while (sz--) {
                int node = q.front(); q.pop();
                for (int nei : friends[node]) {
                    if (!vis[nei]) {
                        vis[nei] = true;
                        q.push(nei);
                    }
                }
            }
        }

        // Count videos of friends at that level
        unordered_map<string, int> cnt;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (string &v : watchedVideos[node])
                cnt[v]++;
        }

        // Sort by frequency then name
        vector<pair<string,int>> v(cnt.begin(), cnt.end());
        sort(v.begin(), v.end(), [](auto &a, auto &b) {
            return a.second == b.second ? a.first < b.first : a.second < b.second;
        });

        vector<string> ans;
        for (auto &p : v) ans.push_back(p.first);
        return ans;
    }
};
