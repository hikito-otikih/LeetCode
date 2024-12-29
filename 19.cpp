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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *ans = new ListNode(0, head), *res = ans;
        for (int i = 1; i <= n; i ++)
        {
            head = head -> next;
        }
        while (head)
        {
            head = head -> next;
            ans = ans -> next;
        }
        ans -> next = ans -> next -> next;
        return res -> next;
    }
};