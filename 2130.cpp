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
    int pairSum(ListNode* head) {
        ListNode *j = head;
        ListNode *prev1 = head, *prev2 = head;
        while (prev2 -> next && prev2 -> next -> next)
        {
            prev2 = prev2 -> next -> next;
            prev1 = prev1 -> next;
        }
        ListNode *i = prev1 -> next;
        prev1 -> next = NULL;
        ListNode *prev = NULL;
        while (i)
        {
            ListNode *temp = i -> next;
            i -> next = prev;
            prev = i;
            i = temp;
        }
        i = prev;
        int ans = -1e9;
        while (i && j)
        {
            ans = max(ans, i -> val + j -> val);
            i = i -> next;
            j = j -> next;
        }
        return ans;
    }
};