/*
Problem: Find Players With Zero or One Losses
-------------------------------------------------
You are given an integer array 'matches' where matches[i] = [winneri, loseri] 
indicates that the player winneri defeated player loseri in a match.

Return a list answer of size 2 where:
  - answer[0] is a list of all players that have not lost any match.
  - answer[1] is a list of all players that have lost exactly one match.

Notes:
  - The values in the two lists should be returned in increasing order.
  - You should consider only players who have played at least one match.

Example:
Input:
matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]

Output:
[[1,2,10],[4,5,7,8]]

Explanation:
- Players with zero losses: 1, 2, 10
- Players with exactly one loss: 4, 5, 7, 8
*/

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    int n = matches.size();
    unordered_map<int,int> lostmap;

    // Count how many times each player has lost
    for(int i = 0; i < n; i++) {
        int loser = matches[i][1];
        lostmap[loser]++;
    }

    vector<int> notlost;
    vector<int> lostonce;

    // Identify players with 0 losses and 1 loss
    for(int i = 0; i < n; i++) {
        int winner = matches[i][0];
        int loser = matches[i][1];

        // If winner not found in lostmap -> 0 losses
        if(lostmap.find(winner) == lostmap.end()) {
            notlost.push_back(winner);
            // Mark processed to avoid duplicates
            lostmap[winner] = 2;  
        }

        // If loser lost exactly once
        if(lostmap[loser] == 1) {
            lostonce.push_back(loser);
        }
    }

    sort(notlost.begin(), notlost.end());
    sort(lostonce.begin(), lostonce.end());

    return {notlost, lostonce};
}

int main() {
    vector<vector<int>> matches = {
        {1,3},{2,3},{3,6},{5,6},{5,7},{4,5},
        {4,8},{4,9},{10,4},{10,9}
    };

    vector<vector<int>> result = findWinners(matches);

    cout << "Players with 0 losses: ";
    for(int player : result[0]) {
        cout << player << " ";
    }
    cout << endl;

    cout << "Players with 1 loss: ";
    for(int player : result[1]) {
        cout << player << " ";
    }
    cout << endl;

    return 0;
}
