/*
Problem: Unique Number of Occurrences
---------------------------------------
Given an array of integers arr, return true if and only if 
the number of occurrences of each value in the array is unique.

Constraints:
- 1 <= arr.length <= 1000
- -1000 <= arr[i] <= 1000

Example 1:
Input: arr = [1,2,2,1,1,3]
Output: true
Explanation:
The value 1 has 3 occurrences, 2 has 2 occurrences, and 3 has 1 occurrence.
No two values have the same number of occurrences.

Example 2:
Input: arr = [1,2]
Output: false
Explanation:
The value 1 has 1 occurrence, and 2 also has 1 occurrence.

Example 3:
Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

-------------------------------------------------
Brute Force Approach (using map + set):
-------------------------------------------------
bool uniqueOccurrences(vector<int>& arr) {
    unordered_map<int,int> freqMap;

    // Count occurrences
    for(auto &x : arr) {
        freqMap[x]++;
    }

    unordered_set<int> seen;
    // Check if frequencies are unique
    for(auto &it : freqMap) {
        int freq = it.second;
        if(seen.find(freq) != seen.end()) 
            return false;
        seen.insert(freq);
    }
    return true;
}
Time Complexity: O(n)  
Space Complexity: O(n)  

-------------------------------------------------
Optimized Approach (using fixed-size array):
-------------------------------------------------
1. Use a frequency array of size 2001 (offset by +1000 to handle negatives).
2. Count occurrences of each number.
3. Sort the frequency array.
4. If two adjacent frequencies are equal (and non-zero), return false.
5. Otherwise, return true.

Time Complexity: O(n) + O(2001 log 2001) ≈ O(n)  
Space Complexity: O(2001) = O(1) (constant extra space)
*/

#include <bits/stdc++.h>
using namespace std;

bool uniqueOccurrences(vector<int>& arr) {
    vector<int> freq(2001, 0); // To handle values from -1000 to +1000
    
    // Count frequencies
    for (auto &it : arr) {
        freq[it + 1000]++;
    }

    // Sort the frequencies
    sort(freq.begin(), freq.end());

    // Check for duplicates
    for (int i = 1; i < 2001; i++) {
        if (freq[i] != 0 && freq[i] == freq[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    vector<int> arr1 = {1,2,2,1,1,3};
    cout << (uniqueOccurrences(arr1) ? "true" : "false") << endl; // true

    vector<int> arr2 = {1,2};
    cout << (uniqueOccurrences(arr2) ? "true" : "false") << endl; // false

    vector<int> arr3 = {-3,0,1,-3,1,1,1,-3,10,0};
    cout << (uniqueOccurrences(arr3) ? "true" : "false") << endl; // true

    return 0;
}
