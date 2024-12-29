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
    bool isPalindrome(ListNode* head) {
        int mod = 1e9 + 7, pw = 1, base = 1e6 + 3;
        int cur[] = {0, 0};
        while (head)
        {
            cur[0] = (1LL * cur[0] * base % mod + head -> val) % mod;
            cur[1] = (1LL * pw * head -> val % mod + cur[1]) % mod;
            pw = 1LL * pw * base % mod;
            head = head -> next;
        }
        return cur[0] == cur[1];
    }
};