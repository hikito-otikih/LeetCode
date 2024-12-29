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
    int sz(ListNode *k)
    {
        int res = 0;
        while (k) 
        {
            res ++;
            k = k -> next;
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int s1 = sz(l1), s2 = sz(l2);
        ListNode *ans = new ListNode(), *res = ans;
        while (max(s1, s2))
        {
            int sum = 0;
            if (s1 < s2) 
            {
                sum += l2 -> val;
                l2 = l2 -> next;
                s2 --;
            }
            else
                if (s1 > s2)
                {
                    sum += l1 -> val;
                    l1 = l1 -> next;
                    s1 --;
                }
                else
                {
                    sum += l1 -> val + l2 -> val;
                    l1 = l1 -> next, l2 = l2 -> next;
                    s1 --, s2 --;
                }
            ListNode *x = new ListNode(sum);
            x -> next = ans;
            ans = x;
        }
        int carry = 0;
        ListNode *prev = NULL;
        while (ans != res)
        {
            ans -> val += carry;
            carry = ans -> val / 10;
            ans -> val %= 10;
            ListNode *temp = ans -> next;
            ans -> next = prev;
            prev = ans;
            ans = temp;
        }
        if (carry == 0) return prev;
        if (carry == 1) 
        {
            res -> val = 1;            
            res -> next = prev;
        }
        return res;
    }
};