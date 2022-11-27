/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without repeating characters.

Example 1:
	Input: s = "abcabcbb"
	Output: 3
	Explanation: The answer is "abc", with the length of 3.

Example 2:
	Input: s = "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.

Example 3:
	Input: s = "pwwkew"
	Output: 3
	Explanation: The answer is "wke", with the length of 3.
	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:
	0 <= s.length <= 5 * 104
	s consists of English letters, digits, symbols and spaces.

*/

#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char *s)
{
	int left = 0, right = 0;
	int max = 0;

	int len = strlen(s);
	if (len == 0 || len == 1)
		return len;

	while (s[right + 1] != '\0')
	{
		right++;
		for (int i = left; i < right; ++i)
		{
			if (s[i] == s[right])
			{
				left = i + 1;
				break;
			}
		}
		if (right - left + 1 > max)
			max = right - left + 1;
	}
	return max;
}

int main()
{
	char s1[] = "abcabcbbb";
	char s2[] = "bbbbb";
	char s3[] = "pwwkew";

	printf("Input: s1 = '%s'\nOutput: %d\n", s1, lengthOfLongestSubstring(s1));
	printf("Input: s2 = '%s'\nOutput: %d\n", s2, lengthOfLongestSubstring(s2));
	printf("Input: s3 = '%s'\nOutput: %d\n", s3, lengthOfLongestSubstring(s3));
}
