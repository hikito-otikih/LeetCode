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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ans = new ListNode(), *res = ans;
        while (head)
        {
            if (val != head -> val)
            {
                ans -> next = head;
                ans = ans -> next;
            }
            head = head -> next;
        }
        ans -> next = NULL;
        return res -> next;
    }
};