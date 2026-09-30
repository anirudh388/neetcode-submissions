class Solution {
public:
    bool isAlpha(char ch) {
        return (ch >= '0' && ch <= '9') ||
               (tolower(ch) >= 'a' && tolower(ch) <= 'z');
    }

    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {

            // Skip non-alphanumeric from left
            while (i <= j && !isAlpha(s[i])) {
                i++;
            }

            // Skip non-alphanumeric from right
            while (i <= j && !isAlpha(s[j])) {
                j--;
            }

            if (i > j) break;

            // Compare lowercase characters
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }

            i++;
            j--;
        }

        return true;
    }
};
