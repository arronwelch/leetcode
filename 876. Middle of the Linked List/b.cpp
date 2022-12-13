/* 876. Middle of the Linked List */

/* solution B */

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

Example 1:
Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:
Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

Constraints:
The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100
*/

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *nptr) : val(x), next(nptr) {}
};

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
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode* node = head;
        while(node)
        {
            n++;
            node = node->next;
        }
        int k = 0;
        node = head;
        while (k < n/2)
        {
            k++;
            node = node->next;
        }
        return node;
    }
};

int main()
{
    cout << "Hello! leetcode 876\n";
    ListNode *HEAD = nullptr;
    ListNode *node = new ListNode(1);
    HEAD = node;
    node->next = new ListNode(2);
    node = node->next;
    node->next = new ListNode(3);
    node = node->next;
    node->next = new ListNode(4);
    node = node->next;
    node->next = new ListNode(5);
    node = node->next;
    node->next = new ListNode(6);

    Solution A;
    ListNode *pos = A.middleNode(HEAD);
    for(ListNode* node = pos; node != nullptr; node = node->next)
    {
        cout << node->val << ' ';
    }
    cout << '\n';
}