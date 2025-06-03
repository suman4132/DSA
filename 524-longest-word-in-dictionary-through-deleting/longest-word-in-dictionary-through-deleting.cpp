class Solution {
public:
    bool isSubsequence(string s, string word) {
        int i = 0, j = 0;
        while (i < s.size() && j < word.size()) {
            if (s[i] == word[j]) {
                j++;
            }
            i++;
        }
        return j == word.size();
    }

    string findLongestWord(string s, vector<string>& dictionary) {
        string best = "";
        for (string word : dictionary) {
            if (isSubsequence(s, word)) {
                if (word.length() > best.length() || 
                   (word.length() == best.length() && word < best)) {
                    best = word;
                }
            }
        }
        return best;
    }
};
