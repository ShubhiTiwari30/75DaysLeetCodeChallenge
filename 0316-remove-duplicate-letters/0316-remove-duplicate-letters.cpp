class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26);

        // last occurrence store karo
        for(int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        stack<char> st;
        vector<bool> visited(26, false);

        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];

            // already used → skip
            if(visited[ch - 'a']) continue;

            // pop until condition satisfied
            while(!st.empty() && ch < st.top() && last[st.top() - 'a'] > i) {
                visited[st.top() - 'a'] = false;
                st.pop();
            }

            st.push(ch);
            visited[ch - 'a'] = true;
        }

        // stack → string
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};