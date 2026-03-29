class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {
            // opening brackets
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            else {
                // closing bracket but stack empty
                if(st.empty()) return false;

                char top = st.top();
                st.pop();

                // mismatch check
                if((ch == ')' && top != '(') ||
                   (ch == '}' && top != '{') ||
                   (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }

        return st.empty();
    }
};
