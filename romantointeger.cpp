#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500},
            {'M', 1000}
        };

        int total = 0;
        for (int i = 0; i < s.size(); i++) {
            int curr = roman[s[i]];
            if (i + 1 < s.size() && curr < roman[s[i + 1]]) {
                total -= curr;  // Subtraction case
            } else {
                total += curr;  // Normal addition
            }
        }
        return total;
    }
};

int main() {
    string s;
    cout << "Enter Roman numeral: ";
    cin >> s;

    Solution sol;
    int ans = sol.romanToInt(s);

    cout << "Integer value: " << ans << endl;

    return 0;
}
