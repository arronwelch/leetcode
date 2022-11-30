/*

30. Substring with Concatenation of All Words

You are given a string s and an array of strings words. All the strings of words are of the same length.

A concatenated substring in s is a substring that contains all the strings of any permutation of words concatenated.

For example, if words = ["ab","cd","ef"], then "abcdef", "abefcd", "cdabef", "cdefab", "efabcd", and "efcdab" are all concatenated strings. "acdbef" is not a concatenated substring because it is not the concatenation of any permutation of words.
Return the starting indices of all the concatenated substrings in s. You can return the answer in any order.

Example 1:
	Input: s = "barfoothefoobarman", words = ["foo","bar"]
	Output: [0,9]
	Explanation: Since words.length == 2 and words[i].length == 3, the concatenated substring has to be of length 6.
	The substring starting at 0 is "barfoo". It is the concatenation of ["bar","foo"] which is a permutation of words.
	The substring starting at 9 is "foobar". It is the concatenation of ["foo","bar"] which is a permutation of words.
	The output order does not matter. Returning [9,0] is fine too.

Example 2:
	Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
	Output: []
	Explanation: Since words.length == 4 and words[i].length == 4, the concatenated substring has to be of length 16.
	There is no substring of length 16 is s that is equal to the concatenation of any permutation of words.
	We return an empty array.

Example 3:
	Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
	Output: [6,9,12]
	Explanation: Since words.length == 3 and words[i].length == 3, the concatenated substring has to be of length 9.
	The substring starting at 6 is "foobarthe". It is the concatenation of ["foo","bar","the"] which is a permutation of words.
	The substring starting at 9 is "barthefoo". It is the concatenation of ["bar","the","foo"] which is a permutation of words.
	The substring starting at 12 is "thefoobar". It is the concatenation of ["the","foo","bar"] which is a permutation of words.

Constraints:
	1 <= s.length <= 10^4
	1 <= words.length <= 5000
	1 <= words[i].length <= 30
	s and words[i] consist of lowercase English letters.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> findSubstring(string &s, vector<string> &words)
	{
		vector<int> res;
		int m = words.size(), n = words[0].size(), ls = s.size();
		for (int i = 0; i < n && i + m * n <= ls; ++i)
		{
			unordered_map<string, int> differ;
			for (int j = 0; j < m; ++j)
			{
				++differ[s.substr(i + j * n, n)];
			}

			for (string &word: words)
			{
				if (--differ[word] == 0)
					differ.erase(word);
			}

			for (int start = i; start < ls - m * n + 1; start += n)
			{
				if (start != i)
				{
					string word = s.substr(start + (m - 1) * n, n);
					if (++differ[word] == 0)
						differ.erase(word);
					word = s.substr(start - n, n);
					if (--differ[word] == 0)
						differ.erase(word);
				}
				if (differ.empty())
					res.emplace_back(start);
			}
		}
		return res;
	}
};

int main()
{
	cout << "Hello! leetcode 30\n";
	string str1 = "barfoothefoobarman";
	vector<string> sv1 = {"foo","bar"};

	Solution sln1;
	vector<int> ans1 = sln1.findSubstring(str1,sv1);

	cout << "[ ";
	for (auto it = ans1.begin(); it != ans1.end(); ++it)
	{
		cout << *it << ", ";
	}
	cout << "\b\b ]\n";
}