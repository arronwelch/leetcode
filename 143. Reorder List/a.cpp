/* 143. Reorder List */

/* Solution A */

/*
You are given the head of a singly linked-list. The list can be represented as:

L0 → L1 → … → Ln - 1 → Ln
Reorder the list to be on the following form:

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
You may not modify the values in the list's nodes. Only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4]
Output: [1,4,2,3]

Example 2:
Input: head = [1,2,3,4,5]
Output: [1,5,2,4,3]

Constraints:
The number of nodes in the list is in the range [1, 5 * 10^4].
1 <= Node.val <= 1000

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
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr) {
            return;
        }
        vector<ListNode*> vec;
        while (head != nullptr) {
            vec.__emplace_back(head);
            head = head->next;
        }
        int i = 0, j = vec.size()-1;
        while (i < j) {
            vec[i]->next = vec[j];
            i++;
            if (i == j)
                break;
            vec[j]->next = vec[i];
            j--;
        }
        vec[i]->next = nullptr;
    }
};

int main()
{
    ListNode* note = new ListNode(1);
    ListNode* HEAD = note;
    note->next = new ListNode(2);
    note = note->next;
    note->next = new ListNode(3);
    note = note->next;
    note->next = new ListNode(4);
    note = note->next;
    note->next = new ListNode(5);

    note = HEAD;
    while( note != nullptr)
    {
        cout << note->val << ' ';
        note = note->next;
    }
    cout << endl;

    Solution a;
    note = HEAD;
    a.reorderList(note);
    while( note != nullptr)
    {
        cout << note->val << ' ';
        note = note->next;
    }
    cout << endl;
}