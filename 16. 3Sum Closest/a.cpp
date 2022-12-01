/* 16. 3Sum Closest */

/*

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
	Input: nums = [-1,2,1,-4], target = 1
	Output: 2
	Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
	Input: nums = [0,0,0], target = 1
	Output: 0
	Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Constraints:
	3 <= nums.length <= 500
	-1000 <= nums[i] <= 1000
	-104 <= target <= 104

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		int size = nums.size();
		int closest = INT_MAX;
		int res = 0;

		sort(nums.begin(), nums.end());
		for (int first = 0; first < size; ++first)
		{
			if (first > 0 && nums[first] == nums[first - 1])
				++first;
			int left = first + 1;
			int right = size - 1;
			while (left < right)
			{
				int sum = nums[first] + nums[left] + nums[right];

				if (sum == target)
					return target;
				else if (sum > target)
				{
					--right;
					while (left < right && nums[right] == nums[right + 1])
						--right;
				}
				else
				{
					++left;
					while (left < right && nums[left] == nums[left - 1])
						++left;
				}

				int distance = abs(sum - target);
				if (distance < closest)
				{
					closest = distance;
					res = sum;
				}
			}
		}
		return res;
	}
};

int main()
{
	cout << "Hello! leetcode 16\n";

	vector<int> nums = {-1, 2, 1, -4};
	int target = 1;
	Solution a;
	int res = a.threeSumClosest(nums, target);
	cout << res << endl;
}