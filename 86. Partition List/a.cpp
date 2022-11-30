/* 86. Partition List */

/*

Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example 1:
	Input: head = [1,4,3,2,5,2], x = 3
	Output: [1,2,2,4,3,5]

Example 2:
	Input: head = [2,1], x = 2
	Output: [1,2]

Constraints:
	The number of nodes in the list is in the range [0, 200].
	-100 <= Node.val <= 100
	-200 <= x <= 200

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <iostream>

using namespace std;

// struct default is public
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* nptr) : val(x), next(nptr) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x)
	{
		ListNode* small = new ListNode(0);
		ListNode* smallHead = small;
		ListNode* large = new ListNode(0);
		ListNode* largeHead = large;
		while(head != nullptr)
		{
			if(head->val < x)
			{
				small->next = head;
				small = small->next;
			}
			else
			{
				large->next = head;
				large = large->next;
			}
			head = head->next;
		}
		large->next = nullptr;
		small->next = largeHead->next;
		return smallHead->next;
	}
};

int main()
{
	cout << "Hello! leetcode 86\n";

	ListNode* head = new ListNode(0);
	ListNode* HEAD = head;
	head->next = new ListNode(1);
	head = head->next;
	head->next = new ListNode(4);
	head = head->next;
	head->next = new ListNode(3);
	head = head->next;
	head->next = new ListNode(2);
	head = head->next;
	head->next = new ListNode(5);
	head = head->next;
	head->next = new ListNode(2);
	head = head->next;

	head = HEAD->next;
	while(head != nullptr)
	{
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;

	Solution sln1;
	ListNode* ans = sln1.partition(HEAD->next, 3);

	head = ans;
	while(head != nullptr)
	{
		cout << head->val << ' ';
		head = head->next;
	}
	cout << endl;
}