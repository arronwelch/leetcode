/* 15. 3Sum */

/*

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
	Input: nums = [-1,0,1,2,-1,-4]
	Output: [[-1,-1,2],[-1,0,1]]
	Explanation: 
	nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
	nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
	nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
	The distinct triplets are [-1,0,1] and [-1,-1,2].
	Notice that the order of the output and the order of the triplets does not matter.

Example 2:
	Input: nums = [0,1,1]
	Output: []
	Explanation: The only possible triplet does not sum up to 0.

Example 3:
	Input: nums = [0,0,0]
	Output: [[0,0,0]]
	Explanation: The only possible triplet sums up to 0.

Constraints:
	3 <= nums.length <= 3000
	-10^5 <= nums[i] <= 10^5

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>> res;
		sort(nums.begin(),nums.end());
		for(int first = 0; first < size; ++first)
		{
			if (nums[first] > 0) return res;
			if (first > 0 && nums[first] == nums[first-1]) continue;
			int left = first + 1;
			int right = size - 1;
			while(left<right)
			{
				if(nums[first]+nums[left]+nums[right]>0) right--;
				else if(nums[first]+nums[left]+nums[right]<0) left++;
				else
				{
					res.emplace_back(vector<int>{nums[first],nums[left],nums[right]});
					left++;
					right--;
					while(left < right && nums[left] == nums[left-1]) left++;
					while(left < right && nums[right] == nums[right+1]) right--;
				}
			}
		}
		return res;
	}
};

int main()
{
	cout << "Hello! leetcode 15\n";

	vector<int> nums = { -1,0,1,2,-1,-4 };
	Solution a;
	vector<vector<int>> ans = a.threeSum(nums);

	for(auto &i : ans)
	{
		cout << "[ ";
		for(auto &j: i)
		{
			cout << j << ", ";
		}
		cout << "\b\b ]\n";
	}
}