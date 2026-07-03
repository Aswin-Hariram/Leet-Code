class Solution {
public:
    string toGoatLatin(string sentence) {
        vector<string> words;
        stringstream ss(sentence);
        string word;

        while (ss >> word) {
            words.push_back(word);
        }

        unordered_set<char> vow = {
            'a','e','i','o','u',
            'A','E','I','O','U'
        };

        string ans;
        string added = "a";

        for (int i = 0; i < words.size(); i++) {
            string cur = words[i];

            if (!vow.count(cur[0])) {
                char first = cur[0];
                cur.erase(0, 1);
                cur.push_back(first);
            }

            cur += "ma";
            cur += added;
            added += 'a';

            ans += cur;
            if (i != words.size() - 1)
                ans += ' ';
        }

        return ans;
    }
};