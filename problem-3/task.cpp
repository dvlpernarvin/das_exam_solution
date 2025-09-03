// PROBLEM-3: Group Anagrams.

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for (string s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto &p : mp) res.push_back(p.second);
        return res;
    }
};

int main() {
    vector<string> words = {"eat","tea","tan","ate","nat","bat"};
    Solution sol;
    vector<vector<string>> ans = sol.groupAnagrams(words);

    for (auto &group : ans) {
        cout << "[ ";
        for (auto &w : group) cout << w << " ";
        cout << "]\n";
    }
    return 0;
}