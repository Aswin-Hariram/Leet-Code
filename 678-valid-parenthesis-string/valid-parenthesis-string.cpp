#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> openStack;  // stores indexes of '('
        stack<int> starStack;  // stores indexes of '*'
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') {
                openStack.push(i);
            } 
            else if (c == '*') {
                starStack.push(i);
            } 
            else if (c == ')') {
                if (!openStack.empty()) {
                    openStack.pop(); // match '(' with ')'
                } 
                else if (!starStack.empty()) {
                    starStack.pop(); // use '*' as '('
                } 
                else {
                    return false; // no match
                }
            }
        }

        // Match remaining '(' with '*' after them
        while (!openStack.empty() && !starStack.empty()) {
            if (openStack.top() > starStack.top()) {
                // '(' occurs after '*', cannot match
                return false;
            }
            openStack.pop();
            starStack.pop();
        }

        return openStack.empty();
    }
};
