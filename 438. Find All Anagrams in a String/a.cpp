/* 438. Find All Anagrams in a String */

/*

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:
	Input: s = "cbaebabacd", p = "abc"
	Output: [0,6]
	Explanation:
	The substring with start index = 0 is "cba", which is an anagram of "abc".
	The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
	Input: s = "abab", p = "ab"
	Output: [0,1,2]
	Explanation:
	The substring with start index = 0 is "ab", which is an anagram of "ab".
	The substring with start index = 1 is "ba", which is an anagram of "ab".
	The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:
	1 <= s.length, p.length <= 3 * 104
	s and p consist of lowercase English letters.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<int> findAnagrams(string s, string p)
	{
		int s_len = s.size();
		int p_len = p.size();

		if (s_len < p_len)
			return vector<int>();

		vector<int> ans;
		vector<int> s_table(26);
		vector<int> p_table(26);

		for (int i = 0; i < p_len; ++i)
		{
			++s_table[s[i] - 'a'];
			++p_table[p[i] - 'a'];
		}

		if (s_table == p_table)
			ans.emplace_back(0);

		for (int i = 0; i < s_len - p_len; ++i)
		{
			--s_table[s[i] - 'a'];
			++s_table[s[i + p_len] - 'a'];

			if (s_table == p_table)
				ans.emplace_back(i + 1);
		}
		return ans;
	}
};

class Solution2
{
public:
	vector<int> findAnagrams(string s, string p) {

	}
};