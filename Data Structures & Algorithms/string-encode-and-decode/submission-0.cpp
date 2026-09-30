class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";

        for (string s : strs) {
            ans += to_string(s.size()) + "#" + s;
        }

        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;

        int i = 0;

        while (i < s.size()) {
            int j = i;

            // Find #
            while (s[j] != '#') {
                j++;
            }

            // Get length
            int len = stoi(s.substr(i, j - i));

            // Start of actual string
            j++;

            ans.push_back(s.substr(j, len));

            // Move to next encoded string
            i = j + len;
        }

        return ans;
    }
};