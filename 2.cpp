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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *x = new ListNode(), *y = x;
        int r = 0;
        while (l1 || l2)
        {
            x -> next = new ListNode();
            x = x -> next;

            int c = l1 ? l1 -> val : 0, d = l2 ? l2 -> val : 0;
            x -> val = c + d + r;
            r = (x -> val) / 10;
            x -> val %= 10;
            if (l1) l1 = l1 -> next;
            if (l2) l2 = l2 -> next;
        }
        if (r > 0) x -> next = new ListNode(1);
        return y -> next;
    }
};