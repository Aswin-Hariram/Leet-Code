#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count("0000")) return -1;
        if(target == "0000") return 0;

        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int turns = 0;

        while(!q.empty()) {
            int sz = q.size();
            turns++;
            for(int i = 0; i < sz; i++) {
                string curr = q.front();
                q.pop();
                // Generate neighbors
                for(int j = 0; j < 4; j++) {
                    char c = curr[j];
                    // Turn wheel up
                    curr[j] = c == '9' ? '0' : c + 1;
                    if(curr == target) return turns;
                    if(!dead.count(curr) && !visited.count(curr)) {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    // Turn wheel down
                    curr[j] = c == '0' ? '9' : c - 1;
                    if(curr == target) return turns;
                    if(!dead.count(curr) && !visited.count(curr)) {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    // Restore original char
                    curr[j] = c;
                }
            }
        }
        return -1;
    }
};
