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
    void reorderList(ListNode* head) {
        ListNode *cur = head;
        int n = 0;
        while (cur)
        {
            n ++;
            cur = cur -> next;
        }
        cur = head;
        ListNode *prev = NULL;
        for (int i = 1; i <= (n + 1) / 2; i ++) 
        {
            prev = cur;
            cur = cur -> next;
        }
        prev -> next = NULL;
        ListNode *temp = NULL;
        while (cur)
        {
            ListNode *c = cur -> next;
            cur -> next = temp;
            temp = cur;
            cur = c;
        }
        while (temp)
        {
            ListNode *k = head -> next;
            ListNode *h = temp -> next;
            head -> next = temp;
            temp -> next = k;
            head = k;
            temp = h;
        }
    }
};