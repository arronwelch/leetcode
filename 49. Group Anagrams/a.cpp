/*
49. Group Anagrams

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
	Input: strs = ["eat","tea","tan","ate","nat","bat"]
	Output: [["bat"],["nat","tan"],["ate","eat","tea"]]

Example 2:
	Input: strs = [""]
	Output: [[""]]

Example 3:
	Input: strs = ["a"]
	Output: [["a"]]

Constraints:
	1 <= strs.length <= 10^4
	0 <= strs[i].length <= 100
	strs[i] consists of lowercase English letters.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iterator>

using namespace std;

class Solution {
public:
	vector<vector<string> > groupAnagrams(vector<string>& strs) {
		unordered_map<string, vector<string> > map;
		for(string &str : strs)
		{
			string key = str;
			sort(key.begin(), key.end());
			map[key].__emplace_back(str);
		}
		vector<vector<string> > ans;
		for(auto it = map.begin(); it != map.end(); ++it)
		{
			ans.__emplace_back(it->second);
		}
		return ans;
	}
};

int main()
{
	cout << "Hello! leetcode 49\n";

	string sa[] = { "eat","tea","tan","ate","nat","bat" };
	vector<string> strs1(sa, sa+ 6);
	Solution a;
	vector<vector<string> > ans =  a.groupAnagrams(strs1);
	for(auto it_i = ans.begin(); it_i != ans.end(); ++it_i) {
		for(auto it_j = (*it_i).begin(); it_j != (*it_i).end(); ++it_j )
			cout << '"' << *it_j << "\" ";
		cout << endl;
	}
}
