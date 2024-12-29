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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *ans = new ListNode(0, head), *res = ans;
        for (int i = 1; i < left; i ++) 
        {
            ans -> next = head;
            ans = ans -> next;
            head = head -> next;    
        }
        ListNode *prev = NULL;
        for (int i = left; i <= right; i ++)
        {
            ListNode *temp = head -> next;
            head -> next = prev;
            prev = head;
            head = temp;
        }
        ListNode *nxt = ans -> next;
        ans -> next = prev;
        while (head)
        {
            nxt -> next = head;
            nxt = nxt -> next;
            head = head -> next;
        }
        return res -> next;
    }
};