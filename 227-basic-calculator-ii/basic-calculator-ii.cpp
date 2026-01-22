class Solution {
public:
    int calculate(string s) {
        long result = 0;
        long last = 0;
        long num = 0;
        char op = '+';

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
                if (op == '+') {
                    cout<<result<<" + "<<endl;
                    result += last;
                    last = num;
                }
                else if (op == '-') {
                      cout<<result<<" - "<<endl;
                    result += last;
                    last = -num;
                }
                else if (op == '*') {
                    last = last * num;
                }
                else if (op == '/') {
                    last = last / num;
                }

                op = c;
                num = 0;
            }
        }
          cout<<result<<endl;
        result += last;
        return result;
    }
};