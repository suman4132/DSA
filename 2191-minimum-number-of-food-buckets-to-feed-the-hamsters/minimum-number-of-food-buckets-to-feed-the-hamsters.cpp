class Solution {
public:
    int minimumBuckets(string s) {
        int n = s.length();
        int c = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'H') {
                if (i > 0 && s[i - 1] == 'B') {
                    continue;
                }
                else if (i < n - 1 && s[i + 1] == '.') {
                    s[i + 1] = 'B'; 
                    c++;
                }
                else if (i > 0 && s[i - 1] == '.') {
                    s[i - 1] = 'B'; 
                    c++;
                }
                else {
                    return -1;
                }
            }
        }

        return c;
    }
};