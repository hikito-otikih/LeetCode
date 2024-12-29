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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *cur = head;
        if (cur == NULL)
        {
            return head;   
        }
        int n = 0;
        while (cur)
        {
            n ++;
            cur = cur -> next;
        }
        k %= n;
        if (k == 0) return head;
        cur = head;
        for (int i = 1; i <= k; i ++)
        {
            cur = cur -> next;
        }
        ListNode *crr = new ListNode(0, head), *ans = crr;
        ListNode *prev = NULL;
        while (cur != NULL)
        {
            prev = cur;
            cur = cur -> next;
            ans = ans -> next;
        }
        ListNode *res = ans -> next;
        ans -> next = NULL;
        prev -> next = head;
        return res;
    }
};