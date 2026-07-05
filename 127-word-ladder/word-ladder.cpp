#include <unordered_set>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> visited;
        visited.insert(beginWord);

        while (!q.empty()) {
            auto [word, length] = q.front();
            q.pop();

            if (word == endWord) return length;

            // Try all one letter transformations
            for (int i = 0; i < word.size(); ++i) {
                char originalChar = word[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == originalChar) continue;
                    word[i] = c;
                    if (dict.find(word) != dict.end() && visited.find(word) == visited.end()) {
                        visited.insert(word);
                        q.push({word, length + 1});
                    }
                }
                word[i] = originalChar;  // revert back
            }
        }
        return 0;
    }
};