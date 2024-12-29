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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ans = new ListNode(0, head), *res = ans;
        ListNode *a, *b;
        int n = k;
        for (int i = 1; i <= k; i ++)
        {
            if (i == k) a = head;
            head = head -> next;
        }
        ListNode *temp = ans;
        while (head != NULL)
        {
            n ++;
            head = head -> next;
            temp = temp -> next;
        }
        b = temp -> next;
        if (a == b) return res -> next;
        ListNode *nxt = k < n - k + 1 ? b -> next : a -> next;
        head = ans -> next;
        for (int i = 1; i <= n; i ++)
        {                                                             
            if (i == k) ans -> next = b;
            else 
                if (i == n - k + 1) ans -> next = a;
                else ans -> next = head;
            ans = ans -> next;
            if (i == max(k, n - k + 1)) head = nxt;
            else head = head -> next;
        }
        ans -> next = NULL;
        return res -> next;
    }
};