class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int i = n - 1;

        while (i >= 0) {
            if (digits[i] < 9) {
                digits[i] += 1;
                return digits;
            } else {
                digits[i] = 0;
                i--;
            }
        }

        // If all digits were 9 (e.g., 999)
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
