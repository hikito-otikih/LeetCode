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
    ListNode* swapPairs(ListNode* head) {
        if (head == 0) return head;
        ListNode *l1 = head, *l2 = head -> next;
        ListNode *ans = new ListNode(), *res = ans;
        while (l1 && l2)
        {
            ListNode* temp = l2 -> next;
            ans -> next = l2;
            ans = ans -> next;
            ans -> next = l1;
            ans = ans -> next;
            if (temp == 0)
            {
                ans -> next == 0;
                break;
            }
            l1 = temp;
            l2 = temp -> next;
        }
        if (l1)
        {
            ans -> next = l1;
            ans = ans -> next;
            ans -> next = 0;
        }
        return res -> next;
    }
};