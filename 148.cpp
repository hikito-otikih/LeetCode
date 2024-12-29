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
    ListNode *Merge(ListNode *head, int n)
    {
        if (n == 1) return head;
        int mid = (n + 1) / 2;
        ListNode *luu = head;
        for (int i = 1; i < mid; i ++) head = head -> next;
        ListNode *temp = head -> next;
        head -> next = NULL;

        head = luu;
        head = Merge(head, mid);
        temp = Merge(temp, n - mid);
        ListNode *ans = new ListNode, *res = ans;
        while (head || temp)
        {
            if (head && (temp == 0 || head -> val <= temp -> val)) 
            {
                ans -> next = head;
                head = head -> next;
            }
            else
            {
                ans -> next = temp;
                temp = temp -> next;
            }
            ans = ans -> next;
        }
        return res -> next;
    }
    ListNode* sortList(ListNode* head)
    { 
        if (head == NULL) return head;
        ListNode *cur = head;
        int n = 0;
        while (cur)
        {
            n ++;
            cur = cur -> next;
        }
        return Merge(head, n);
    }
};